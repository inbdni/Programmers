#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void combination(string s, int r, vector<string> &comb)
{
    int i;
    int n = s.size();
    string tmp;
    vector<bool> selected(n);
    
    for (i = 1; i <= r; i++)
    {
        selected[n - i] = true;
    }
    do
    {
        for (i = 0; i < n; i++)
        {
            if (selected[i])
                tmp += s[i];
        }
        comb.push_back(tmp);
        tmp.clear();
    } while (next_permutation(selected.begin(), selected.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<map<string, int>> menu(course.size());
    vector<int> max_value(course.size());
    vector<string> comb;
    int i, j, k;
    
    for (i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        for (j = 0; j < course.size(); j++)
        {
            if (orders[i].size() < course[j])
                continue;
            comb.clear();
            combination(orders[i], course[j], comb);
            for (k = 0; k < comb.size(); k++)
            {
                menu[j][comb[k]]++;
                max_value[j] = max(max_value[j], menu[j][comb[k]]);
            }
        }
    }
    for (i = 0; i < course.size(); i++)
    {
        if (max_value[i] == 1)
            continue;
        for (auto &it : menu[i])
        {
            if (it.second == max_value[i])
                answer.push_back(it.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
