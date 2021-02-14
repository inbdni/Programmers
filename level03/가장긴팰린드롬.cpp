#include <string>
#include <vector>

using namespace std;

vector<vector<int>> d;

int dp(int start, int end, string &s)
{
    if (start >= end)
        return 1;
    if (d[start][end] != -1)
        return d[start][end];
    if (s[start] == s[end])
        d[start][end] = dp(start + 1, end - 1, s);
    else
        d[start][end] = 0;
    return d[start][end];
}

int solution(string s)
{
    vector<int> v;
    int i, start, len;
    
    v.resize(s.size(), -1);
    for (i = 0; i < s.size(); i++)
    {
        d.push_back(v);
    }
    for (len = s.size(); len > 0; len--)
    {
        for (start = 0; start + len <= s.size(); start++)
        {
            if (dp(start, start + len - 1, s))
            {
                return len;
            }
        }
    }
}
