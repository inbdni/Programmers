#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    unordered_set<int> us[9];
    int i, j, num;
    
    if (N == number)
    {
        return 1;
    }
    for (i = 1; i <= 8; i++)
    {
        num = 0;
        for (j = 0; j < i; j++)
        {
            num = num * 10 + N;
        }
        us[i].insert(num);
    }
    for (i = 2; i <= 8; i++)
    {
        for (j = 1; j <= i; j++)
        {
            for (auto a : us[j])
            {
                for (auto b : us[i - j])
                {
                    us[i].insert(a + b);
                    us[i].insert(a - b);
                    us[i].insert(a * b);
                    if (b != 0)
                        us[i].insert(a / b);
                }
            }
        }
        if (us[i].find(number) != us[i].end())
        {
            return i;
        }
    }
    return -1;
}
