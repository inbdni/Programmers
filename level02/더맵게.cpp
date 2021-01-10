#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int min;
    int mix;
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    
    while (!pq.empty())
    {
        if (pq.top() >= K)
            return answer;
        if (pq.size() == 1)
            return -1;
        answer++;
        min = pq.top();
        pq.pop();
        mix = min + pq.top() * 2;
        pq.pop();
        pq.push(mix);
    }
}
