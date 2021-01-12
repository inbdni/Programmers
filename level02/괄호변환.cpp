#include <string>
#include <vector>

using namespace std;

bool    is_correct(string u)
{
    int i;
    int balance = 0;
    
    for (i = 0; i < u.size(); i++)
    {
        if (u[i] == '(')
            balance++;
        else
            balance--;
        if (balance < 0)
            return false;
    }
    return true;
}

int     do_separate(string p)
{
    int i;
    int balance = 0;
    
    for (i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            balance++;
        else
            balance--;
        if (balance == 0)
           break;
    }
    return i + 1;
}

string  do_opposite(string p)
{
    string result = "";
    int i;
    
    for (i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            result += ')';
        else
            result += '(';
    }
    return result;
}

string  do_convert(string p)
{
    string result = "";
    string u = "";
    string v = "";
    int i;
    
    if (p.empty())
    {
        return result;
    } 
    i = do_separate(p);
    if (i < p.size())
    {
        u += p.substr(0, i);
        v += p.substr(i);
    }
    else
    {
        u += p;
    }
    if (is_correct(u))
    {
        result += u;
        result += do_convert(v);
    }
    else
    {
        result += '(';
        result += do_convert(v);
        result += ')';
        result += do_opposite(u.substr(1, u.size() - 2));
    }
    return result;
}

string  solution(string p) {
    string answer = "";

    answer += do_convert(p);
    return answer;
}
