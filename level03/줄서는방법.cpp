#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num;
    int idx;
    long long fac;
    
    for (idx = 1; idx <= n; idx++)
    {
        num.push_back(idx);
    }
    while (n > 0)
    {
        fac = factorial(n) / n--;
        idx = (int)((k - 1) / fac);
        answer.push_back(num[idx]);
        num.erase(num.begin() + idx);
        k %= fac;
        if (k == 0)
            k = fac;
    }
    return answer;
}
