#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>> path;
map<string, vector<bool>> visited;
vector<string> answer;

bool dfs(int r, int n, string curr)
{
    int i;
    
    if (r == n)
    {
        return true;
    }
    for (i = 0; i < path[curr].size(); i++)
    {
        if (visited[curr][i])
        {
            continue;
        }
        visited[curr][i] = true;
        answer.push_back(path[curr][i]);
        if (dfs(r + 1, n, path[curr][i]))
        {
            return true;
        }
        answer.pop_back();
        visited[curr][i] = false;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    map<string, vector<string>>::iterator it;
    int i;
    
    for (i = 0; i < tickets.size(); i++)
    {
        path[tickets[i][0]].push_back(tickets[i][1]);
        visited[tickets[i][0]].push_back(false);
    }
    for (it = path.begin(); it != path.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }
    answer.push_back("ICN");
    dfs(0, tickets.size(), "ICN");
    return answer;
}
