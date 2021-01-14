#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(long long a, long long b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    return a * b;
}

long long calculation(vector<long long> num, vector<char> op, vector<char> priority)
{
    int i = 0;
    int j = 0;
    
    while (!op.empty() && j < priority.size())
    {
        if (i >= op.size())
        {
            i = 0;
            j++;
        }
        if (op[i] == priority[j])
        {
            num[i] = calc(num[i], num[i + 1], op[i]);
            op.erase(op.begin() + i);
            num.erase(num.begin() + i + 1);
            i--;
        }
        i++;
    }
    return abs(num[0]);
}

long long solution(string expression) {
    long long answer = 0;
    int i = 0;
    int j = 0;
    vector<long long> num;
    vector<char> op;
    vector<char> priority = {'*', '+', '-'};
    
    num.push_back(0);
    for (i = 0; i < expression.size(); i++)
    {
        if (isdigit(expression[i]))
        {
            num[j] = num[j] * 10 + expression[i] - '0';
        }
        else
        {
            op.push_back(expression[i]);
            num.push_back(0);
            j++;
        }
    }
    do
    {
        answer = max(answer, calculation(num, op, priority));
    } while (next_permutation(priority.begin(), priority.end()));

    return answer;
}
