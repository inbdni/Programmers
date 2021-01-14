#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    if (a.size() < b.size())
        return true;
    return false;
}

void parsing(string &s, vector<vector<int>> &v)
{
    vector<int> tmp;
    int i = 1;
    int j = -1;
    
    while (i < s.size() - 1)
    {
        if (s[i++] == '}')
        {
            v.push_back(tmp);
            tmp.clear();
            j = -1;
        }
        if (isdigit(s[i]))
        {
            tmp.push_back(0);
            j++;
            while (isdigit(s[i]))
            {
                tmp[j] = tmp[j] * 10 + s[i] - '0';
                i++;
            }
        }
    }
}

void making(vector<vector<int>> &v, vector<int> &answer)
{
    int i;
    int j;
    
    for (i = 0; i < v.size(); i++)
    {
        for (j = 0; j < v[i].size(); j++)
        {
            if (find(answer.begin(), answer.end(), v[i][j]) == answer.end())
            {
                answer.push_back(v[i][j]);
                break;
            }
        }
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    
    parsing(s, v);
    sort(v.begin(), v.end(), compare);
    making(v, answer);
    return answer;
}
