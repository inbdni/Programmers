#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int quo, rem, i;
    
    if (s < n)
    {
        answer.push_back(-1);
        return answer;
    }
    quo = s / n;
    rem = s % n;
    for (i = 0; i < rem; i++)
    {
        answer.push_back(quo + 1);
    }
    for (i = rem; i < n; i++)
    {
        answer.push_back(quo);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
