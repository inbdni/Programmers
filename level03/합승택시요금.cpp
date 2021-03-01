#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>> graph;
    int i, j, k;
    
    graph.resize(n + 1, vector<int> (n + 1, INT_MAX));
    for (i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }
    for (i = 0; i < fares.size(); i++)
    {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
            {
                if (graph[j][i] != INT_MAX && graph[i][k] != INT_MAX)
                {
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }
    answer = min(graph[s][a] + graph[a][b], graph[s][b] + graph[b][a]);
    for (i = 1; i <= n; i++)
    {
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    return answer;
}
