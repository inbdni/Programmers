#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int is_prime(int n) {
    int i;
    
    if (n < 2)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int solution(vector<int> nums) {
    int answer = 0;
    int i;
    int cnt;
    int tmp;
    vector<int> used;
    vector<int> n;
    
    while (i < nums.size() - 3)
    {
        used.push_back(0);
        i++;
    }
    while (i < nums.size())
    {
        used.push_back(1);
        i++;
    }
    do {
        i = 0;
        cnt = 0;
        tmp = 0;
        while (cnt < 3)
        {
            if (used[i])
            {
                tmp += nums[i];
                cnt++;
            }
            i++;
        }
        answer += is_prime(tmp);
    } while (next_permutation(used.begin(), used.end()));
    
    return answer;
}
