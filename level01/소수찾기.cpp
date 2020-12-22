#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i, j;
    vector<int> prime(n+1, 0);
    
    for (i = 2; i <= n; i++)
    {
        if (prime[i] == -1)
        {
            continue;
        }
        answer++;
        for (j = i; j <= n; j += i)
        {
            prime[j] = -1;
        }
    }
    return answer;
}
