#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> m(n + 1);
    int i;
    
    m[1] = 1;
    m[2] = 2;
    for (i = 3; i <= n; i++)
    {
        m[i] = (m[i - 1] + m[i - 2]) % 1234567;
    }
    return m[n];
}
