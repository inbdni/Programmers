#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct TRIE
{
    TRIE *next[26];
    int cnt;
    
    TRIE()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
    
    ~TRIE()
    {
        int i;
        
        for (i = 0; i < 26; i++)
        {
            if (next[i] != NULL)
                delete next[i];
        }
    }
    
    void insert(string &s, int idx)
    {
        int curr;
        
        cnt++;
        if (idx == s.size())
            return;
        curr = s[idx] - 'a';
        if (next[curr] == NULL)
            next[curr] = new TRIE();
        next[curr]->insert(s, idx + 1);
    }
    
    int find(string &s, int idx)
    {
        int i, curr;
        
        if (s[idx] == '?')
            return cnt;
        curr = s[idx] - 'a';
        if (next[curr] == NULL)
            return 0;
        return next[curr]->find(s, idx + 1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    TRIE *root[10001];
    TRIE *rroot[10001];
    int i, cnt;
    string rstr;
    
    for (i = 0; i <= 10000; i++)
    {
        root[i] = new TRIE();
        rroot[i] = new TRIE();
    }
    for (i = 0; i < words.size(); i++)
    {
        rstr = words[i];
        reverse(rstr.begin(), rstr.end());
        root[words[i].size()]->insert(words[i], 0);
        rroot[words[i].size()]->insert(rstr, 0);
    }
    for (i = 0; i < queries.size(); i++)
    {
        rstr = queries[i];
        reverse(rstr.begin(), rstr.end());
        if (queries[i].front() != '?')
            cnt = root[queries[i].size()]->find(queries[i], 0);
        else
            cnt = rroot[queries[i].size()]->find(rstr, 0);
        answer.push_back(cnt);
    }
    return answer;
}
