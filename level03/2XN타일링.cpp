#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<long long> dp;
    int i;
    
    dp.push_back(1);
    dp.push_back(2);
    for (i = 2; i < n; i++)
    {
        dp.push_back((dp[i - 1] + dp[i - 2]) % 1000000007);
    }
    return dp.back();
}
