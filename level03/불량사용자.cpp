#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

bool match(string &a, string &b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
    {
        if (b[i] == '*')
            continue;
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void dfs(int idx, string &select, vector<string> &user_id, vector<string> &banned_id)
{
    if (idx == banned_id.size())
    {
        um[select]++;
        return;
    }
    for (int i = 0; i < user_id.size(); i++)
    {
        if (select[i] == '1')
            continue;
        if (match(user_id[i], banned_id[idx]))
        {
            select[i] = '1';
            dfs(idx + 1, select, user_id, banned_id);
            select[i] = '0';
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    string select = "00000000";
    
    dfs(0, select, user_id, banned_id);
    answer = um.size();
    return answer;
}
