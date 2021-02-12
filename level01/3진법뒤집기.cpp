#include <string>
#include <vector>

using namespace std;

string to_three(int n)
{
    string res = "";
    
    while (n)
    {
        res += to_string(n % 3);
        n /= 3;
    }
    return res;
}

int to_ten(string s)
{
    int i, res = 0;
    
    for (i = 0; i < s.size(); i++)
    {
        res = res * 3 + s[i] - '0';
    }
    return res;
}

int solution(int n) {
    int answer = 0;
    
    if (n)
        answer = to_ten(to_three(n));
    return answer;
}
