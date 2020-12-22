#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    int i;

    while (n != 0)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    sort(num.begin(), num.end());
    for (i = num.size() - 1; i >= 0; i--)
    {
        answer = answer * 10 + num[i];
    }
    return answer;
}
