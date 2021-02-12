#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int i, sum = 0;
    
    sort(d.begin(), d.end());
    for (i = 0; i < d.size(); i++)
    {
        sum += d[i];
        if (sum > budget)
            break;
    }
    answer = i;
    return answer;
}
