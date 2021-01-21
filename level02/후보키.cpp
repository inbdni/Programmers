#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

void make_comb(int n, vector<string> &comb)
{
    int i, j;
    string num = "";
    string tmp = "";
    
    for (i = 0; i < n; i++)
        num += to_string(i);
    do
    {
        for (i = 1; i <= num.size(); i++)
        {
            tmp += num.substr(0, i);
            sort(tmp.begin(), tmp.end());
            if (find(comb.begin(), comb.end(), tmp) == comb.end())
                comb.push_back(tmp);
            tmp.clear();
        }
    } while (next_permutation(num.begin(), num.end()));
    sort(comb.begin(), comb.end(), comp);
}

void del_comb(string n, vector<string> &comb)
{
    int i, j, cnt;
    for (i = comb.size() - 1; i >= 0; i--)
    {
        cnt = 0;
        for (j = 0; j < n.size(); j++)
        {
            if ((find(comb[i].begin(), comb[i].end(), n[j])) != (comb[i].end()))
                cnt++;
        }
        if (cnt == n.size())
            comb.erase(comb.begin() + i);
    }
}

bool check_key(string idx, vector<vector<string>> &relation)
{
    int i, j;
    string tmp;
    unordered_map<string, int> um;

    for (i = 0; i < relation.size(); i++)
    {
        tmp.clear();
        for (j = 0; j < idx.size(); j++)
            tmp += relation[i][idx[j] - '0'];
        if (um[tmp])
            return false;
        um[tmp]++;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    bool res;
    vector<string> comb;

    make_comb(relation[0].size(), comb);
    while (!comb.empty())
    {
        res = check_key(comb.front(), relation);
        if (res)
        {
            del_comb(comb.front(), comb);
            answer++;
        }
        else
        {
            comb.erase(comb.begin());
        }
    }
    return answer;
}
