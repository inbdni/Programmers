#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    long long minTime, maxTime, avgTime;
    long long man;
    int i;
    
    minTime = 1;
    maxTime = *max_element(times.begin(), times.end()) * (long long)n;
    while (minTime <= maxTime)
    {
        man = 0;
        avgTime = (minTime + maxTime) / 2;
        for (i = 0; i < times.size(); i++)
        {
            man += avgTime / times[i];
        }
        if (man < n)
        {
            minTime = avgTime + 1;
        }
        else
        {
            maxTime = avgTime - 1;
            answer = avgTime;
        }
    }
    return answer;
}
