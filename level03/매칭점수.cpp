#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct page
{
    string url;
    vector<int> link;
    int link_num;
    int basic_score;
    double match_score;
    
    void init()
    {
        url.clear();
        link.clear();
        link_num = 0;
        basic_score = 0;
        match_score = 0;
    }
};

unordered_map<string, int> url_list;
vector<page> web_page;

string get_url(string &s, int idx)
{
    string res = "";
    
    while (s[idx] != '\"')
        res += s[idx++];
    return res;
}

void get_body(string &s, string &word, int index)
{
    int idx = s.find("<body>") + 7;
    int end = s.find("</body>");
    int link_idx;
    string tmp;
    string href = "<a href=\"https://";
    
    while (idx < end)
    {
        tmp.clear();
        while (isalpha(s[idx]))
        {
            tmp += s[idx++];
        }
        if (tmp.empty())
        {
            idx++;
            continue;
        }
        if (tmp.compare(word) == 0)
        {
            web_page[index].basic_score++;
        }
        if (tmp.compare("a") == 0 && s.substr(idx - 2).find(href) == 0)
        {
            link_idx = url_list[get_url(s, idx + 15)] - 1;
            if (link_idx >= 0)
                web_page[link_idx].link.push_back(index);
            web_page[index].link_num++;
        }
    }
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    page p;
    int i, j, idx;
    double max_score = 0;
    string meta = "<meta property=\"og:url\" content=\"https://";
    
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for (i = 0; i < pages.size(); i++)
    {
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        p.init();
        p.url = get_url(pages[i], pages[i].find(meta) + 41);
        web_page.push_back(p);
        url_list[p.url] = i + 1;
    }
    for (i = 0; i < pages.size(); i++)
    {
        get_body(pages[i], word, i);
    }
    for (i = 0; i < web_page.size(); i++)
    {
        web_page[i].match_score = web_page[i].basic_score;
        for (j = 0; j < web_page[i].link.size(); j++)
        {
            idx = web_page[i].link[j];
            web_page[i].match_score += (double)web_page[idx].basic_score / web_page[idx].link_num;
        }
        if (max_score < web_page[i].match_score)
        {
            max_score = web_page[i].match_score;
            answer = i;
        }
    }
    return answer;
}
