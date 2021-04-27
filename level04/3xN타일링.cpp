#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i, j;
    long long f[5001];
    
    if (n % 2)
        return answer;
    f[0] = 1;
    f[2] = 3;
    for (i = 4; i <= n; i += 2)
    {
        f[i] = f[i - 2] * f[2];
        for (j = i - 4; j >= 0; j -= 2)
            f[i] += f[j] * 2;
        f[i] %= 1000000007;
    }
    answer = f[n];
    return answer;
}
