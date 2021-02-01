#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getstr(string s)
{
    vector<string> res;
    string tmp = "";
    int i;
    
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (tmp.compare("and") != 0)
                res.push_back(tmp);
            tmp.clear();
            continue;
        }
        tmp += s[i];
    }
    res.push_back(tmp);
    return res;
}

bool is_satisfy(vector<string> &info, vector<string> &query)
{
    int i;
    
    for (i = 0; i < 4; i++)
    {
        if (query[i].compare("-") == 0)
            continue;
        if (query[i].compare(info[i]) != 0)
            return false;
    }
    if (stoi(query[i]) > stoi(info[i]))
        return false;
    return true;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<string>> info_list;
    vector<string> q;
    int i, j, cnt;
    
    for (i = 0; i < info.size(); i++)
    {
        info_list.push_back(getstr(info[i]));
    }
    for (i = 0; i < query.size(); i++)
    {
        q = getstr(query[i]);
        cnt = 0;
        for (j = 0; j < info_list.size(); j++)
        {
            cnt += is_satisfy(info_list[j], q);
        }
        answer.push_back(cnt);
    }
    return answer;
}
