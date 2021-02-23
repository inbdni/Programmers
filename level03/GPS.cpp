#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> mem;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log)
{
    int answer;
    int i, j, g, next;
    
    graph.clear();
    graph.resize(n + 1, vector<int> (0));
    mem.clear();
    mem.resize(k + 1, vector<int> (n + 1, INT_MAX));
    for (i = 1; i <= n; i++)
    {
        graph[i].push_back(i);
    }
    for (i = 0; i < edge_list.size(); i++)
    {
        graph[edge_list[i][0]].push_back(edge_list[i][1]);
        graph[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    mem[1][gps_log.front()] = 0;
    for (i = 1; i < k; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (mem[i][j] == INT_MAX)
                continue;
            for (g = 0; g < graph[j].size(); g++)
            {
                next = graph[j][g];
                if (next == gps_log[i])
                    mem[i + 1][next] = min(mem[i + 1][next], mem[i][j]);
                else
                    mem[i + 1][next] = min(mem[i + 1][next], mem[i][j] + 1);
            }
        }
    }
    answer = mem[k][gps_log.back()];
    if (answer == INT_MAX)
        answer = -1;
    return answer;
}
