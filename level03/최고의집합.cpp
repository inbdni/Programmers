#include <string>
#include <vector>

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
    for (i = 0; i < n - rem; i++)
    {
        answer.push_back(quo);
    }
    for (i = n - rem; i < n; i++)
    {
        answer.push_back(quo + 1);
    }
    return answer;
}
