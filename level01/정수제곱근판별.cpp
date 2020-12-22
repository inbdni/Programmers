#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double temp;
    
    temp = sqrt(n);
    if (temp - (int)temp == 0)
    {
        answer = pow(temp + 1, 2);
    }
    else
    {
        answer = -1;
    }
    return answer;
}
