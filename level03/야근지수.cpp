#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q;
    int i;
    
    for (i = 0; i < works.size(); i++)
    {
        q.push(works[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (q.top() == 0)
            break;
        q.push(q.top() - 1);
        q.pop();
    }
    while (!q.empty())
    {
        answer += q.top() * q.top();
        q.pop();
    }
    return answer;
}
