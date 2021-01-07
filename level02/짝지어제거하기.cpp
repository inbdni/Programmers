#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer;
    int i;
    stack<char> c;

    for (i = 0; i < s.size(); i++)
    {
        if (c.empty())
        {
            c.push(s[i]);
            continue;
        }
        if (c.top() == s[i])
        {
            c.pop();
        }
        else
        {
            c.push(s[i]);
        }
    }
    if (c.size())
    {
        answer = 0;
    }
    else
    {
        answer = 1;
    }

    return answer;
}
