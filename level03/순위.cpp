#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph;
    vector<bool> v;
    int i, j, k, cnt;
    
    v.resize(n + 1, false);
    graph.resize(n + 1, v);
    for (i = 0; i < results.size(); i++)
    {
        graph[results[i][0]][results[i][1]] = true;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
            {
                if (graph[j][i] && graph[i][k])
                    graph[j][k] = true;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        cnt = 0;
        for (j = 1; j <= n; j++)
        {
            if (graph[i][j] || graph[j][i])
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}
