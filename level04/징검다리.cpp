#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int s, e, m, d, i;
    int prev, cnt;
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    s = rocks.front();
    e = rocks.back();
    while (s <= e)
    {
        prev = 0; 
        cnt = 0;
        m = (s + e) / 2;
        for (i = 1; i < rocks.size(); i++)
        {
            d = rocks[i] - rocks[prev];
            if (d < m)
                cnt++;
            else
                prev = i;
        }
        if (cnt <= n)
        {
            s = m + 1;
            answer = max(answer, m);
        }
        else
        {
            e = m - 1;
        }
    }
    return answer;
}
