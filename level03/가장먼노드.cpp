#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<int>> &graph)
{
    vector<bool> visited;
    queue<int> q;
    int i, j;
    int size, cnt, res;
    int node, next;
    
    visited.resize(n + 1, false);
    visited[1] = true;
    q.push(1);
    while (!q.empty())
    {
        cnt = 0;
        size = q.size();
        for (i = 0; i < size; i++)
        {
            node = q.front();
            q.pop();
            for (j = 0; j < graph[node].size(); j++)
            {
                next = graph[node][j];
                if (visited[next])
                    continue;
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
        if (cnt != 0)
        {
            res = cnt;
        }
    }
    return res;
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    int i, answer;
    
    for (i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    answer = bfs(n, graph);
    return answer;
}
