#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int i = 0;
    int time = 0;

    sort(jobs.begin(), jobs.end());
    while (i < jobs.size() || !pq.empty())
    {
        if (i < jobs.size() && jobs[i][0] <= time)
        {
            pq.push(jobs[i++]);
            continue;
        }
        if (!pq.empty())
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
        {
            time = jobs[i][0];
        }
    }
    answer /= jobs.size();
    return answer;
}
