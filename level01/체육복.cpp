#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector<bool> available;
    int i, num;
    
    available.resize(n + 1, false);
    for (i = 0; i < reserve.size(); i++)
    {
        available[reserve[i]] = true;
    }
    for (i = 0; i < lost.size(); i++)
    {
        num = lost[i];
        if (available[num])
        {
            available[num] = false;
            answer++;
            lost.erase(lost.begin() + i);
            i--;
        }
    }
    for (i = 0; i < lost.size(); i++)
    {
        num = lost[i];
        if (num > 1 && available[num - 1])
        {
            available[num - 1] = false;
            answer++;
        }
        else if (num < n && available[num + 1])
        {
            available[num + 1] = false;
            answer++;
        }
    }
    return answer;
}
