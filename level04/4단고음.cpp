#include <cmath>

int calc(int n, int cnt)
{
    int res = 0;
    
    if (n < 3 || 2 * log(n) / log(3) < cnt)
        return 0;
    if (n == 3)
    {
        if (cnt == 2)
            return 1;
        else
            return 0;
    }
    if (n % 3 == 0 && cnt >= 2)
        res += calc(n / 3, cnt - 2);
    res += calc(n - 1, cnt + 1);
    return res;
}

int solution(int n) {
    int answer;
    
    answer = calc(n - 2, 2);
    return answer;
}
