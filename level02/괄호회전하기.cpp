#include <string>
#include <vector>

using namespace std;

bool is_open(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool is_pair(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    if (a == '{' && b == '}')
        return true;
    if (a == '[' && b == ']')
        return true;
    return false;
}

bool is_right(string &s)
{
    vector<char> v;
    int i;
    
    for (i = 0; i < s.size(); i++)
    {
        if (is_open(s[i]))
            v.push_back(s[i]);
        else if (!v.empty() && is_pair(v.back(), s[i]))
            v.pop_back();
        else
            return false;
    }
    if (!v.empty())
        return false;
    return true;
}

int solution(string s)
{
    int answer = 0;
    int x;
    string tmp;
    
    for (x = 0; x < s.size(); x++)
    {
        tmp = s.substr(x) + s.substr(0, x);
        if (is_right(tmp))
            answer++;
    }
    return answer;
}
