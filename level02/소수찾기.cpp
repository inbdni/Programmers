#include <string>
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
 
int solution(string numbers) {
    int answer = 0;
    int i;
    int j;
    int tmp;
    vector<int> num;
    vector<int> n;
    
    for (i = 0; i < numbers.size(); i++)
    {
        num.push_back(numbers[i] - '0');
    }
    sort(num.begin(), num.end());
    do {
        for (i = 1; i <= num.size(); i++)
        {
            tmp = 0;
            for (j = 0; j < i; j++)
            {
                tmp = (tmp * 10) + num[j];
            }
            n.push_back(tmp);
        }
    } while (next_permutation(num.begin(), num.end()));
    sort(n.begin(), n.end());
    n.erase(unique(n.begin(), n.end()), n.end());
    for (i = 0; i < n.size(); i++) {
        answer += is_prime(n[i]);
    }

    return answer;
}
