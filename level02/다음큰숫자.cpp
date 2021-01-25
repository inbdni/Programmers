#include <string>
#include <vector>
#include <climits>

using namespace std;

int cnt_one(int n)
{
    int cnt = 0;
    
    while (n)
    {
        if (n % 2 == 1)
            cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n)
{
    int answer;
    int i;
    int one, num, cnt;
    
    one = cnt_one(n);
    for(i = 1; n + i < INT_MAX; i++)
    {
        num = n + i;
        cnt = cnt_one(num);
        if (cnt == one)
            break;
    }
    answer = n + i;
    return answer;
}
