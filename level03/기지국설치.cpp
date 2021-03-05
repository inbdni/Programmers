#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int i, apart;
    
    apart = (stations[0] - w) - 1;
    if (apart > 0)
        answer += (apart - 1) / (2 * w + 1) + 1;
    for (i = 1; i < stations.size(); i++)
    {
        apart = (stations[i] - w) - (stations[i - 1] + w) - 1;
        if (apart > 0)
            answer += (apart - 1) / (2 * w + 1) + 1;
    }
    apart = n - (stations[i - 1] + w);
    if (apart > 0)
        answer += (apart - 1) / (2 * w + 1) + 1;
    return answer;
}
