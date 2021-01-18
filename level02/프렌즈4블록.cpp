#include <string>
#include <vector>

using namespace std;

bool find_block(vector<vector<pair<char, int>>> &v)
{
    int i;
    int j;
    char block;
    bool more = false;
    
    for (i = 1; i < v.size(); i++)
    {
        for (j = 1; j < v[i].size(); j++)
        {
            block = v[i][j].first;
            if (v[i][j - 1].first != block)
                continue;
            if (v[i - 1].size() <= j - 1)
                continue;
            if (v[i - 1][j].first != block)
                continue;
            if (v[i - 1][j - 1].first != block)
                continue;
            more = true;
            v[i][j].second = true;
            v[i][j - 1].second = true;
            v[i - 1][j].second = true;
            v[i - 1][j - 1].second = true;
        }
    }
    return more;
}

int erase_block(vector<vector<pair<char, int>>> &v, int answer)
{
    int i;
    int j;
    
    for (i = 0; i < v.size(); i++)
    {
        for (j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].second)
            {
                answer++;
                v[i].erase(v[i].begin() + j);
                j--;
            }
        }
    }
    return answer;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int i, j;
    bool more = true;
    char block;
    vector<vector<pair<char, int>>> v;
    vector<pair<char, int>> tmp;
    
    for (i = 0; i < n; i++)
    {
        for (j = m - 1; j >= 0; j--)
        {
            tmp.push_back(make_pair(board[j][i], 0));
        }
        v.push_back(tmp);
        tmp.clear();
    }
    while (more)
    {
        more = false;
        if (find_block(v))
            more = true;
        answer = erase_block(v, answer);
    }
    return answer;
}
