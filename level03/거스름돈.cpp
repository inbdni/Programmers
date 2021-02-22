#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n, vector<int> money)
{
    vector<int> m(n + 1);
    int i, j;
    
    m[0] = 1;
    for (i = 0; i < money.size(); i++)
    {
        for (j = money[i]; j <= n; j++)
        {
            m[j] += m[j - money[i]];
            m[j] %= MOD;
        }
    }
    return m[n];
}
