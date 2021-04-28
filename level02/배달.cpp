#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(vector<int> &dist, vector<vector<pair<int, int>>> &graph)
{
    priority_queue<pair<int, int>> pq;
    pair<int, int> curr, next;
    int i, start = 1;
    
    dist[start] = 0;
    pq.push(make_pair(start, 0));
    while (!pq.empty())
    {
        curr = pq.top();
        pq.pop();
        if (dist[curr.first] < curr.second)
        {
            continue;
        }
        for (i = 0; i < graph[curr.first].size(); i++)
        {
            next = graph[curr.first][i];
            next.second += curr.second;
            if (dist[next.first] > next.second)
            {
                dist[next.first] = next.second;
                pq.push(next);
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;
    int i;
    
    graph.resize(N + 1);
    dist.resize(N + 1, INT_MAX);
    for (i = 1; i <= N; i++)
    {
        graph[i].push_back(make_pair(i, 0));
    }
    for (i = 0; i < road.size(); i++)
    {
        graph[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        graph[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    dijkstra(dist, graph);
    for (i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
        {
            answer++;
        }
    }
    return answer;
}
