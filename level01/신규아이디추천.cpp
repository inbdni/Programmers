#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_possible(char c)
{
    if (isalpha(c) || isdigit(c))
        return true;
    if (c == '-' || c == '_' || c == '.')
        return true;
    return false;
}

string solution(string new_id) {
    string answer = "";
    int i, size = new_id.size();
    bool flag = true;
    
    for (i = 0; i < size; i++)
    {
        if (is_possible(new_id[i]))
        {
            if (new_id[i] == '.')
            {
                if (flag)
                    continue;
                flag = true;
            }
            else
            {
                flag = false;
            }
            answer += tolower(new_id[i]);
        }
    }
    if (answer.back() == '.')
    {
        answer = answer.substr(0, answer.size() - 1);
    }
    if (answer.empty())
    {
        answer += "a";
    }
    else if (answer.size() >= 16)
    {
        answer = answer.substr(0, 15);
        if (answer.back() == '.')
        {
            answer = answer.substr(0, answer.size() - 1);
        }
    }
    while (answer.size() < 3)
    {
        answer += answer.back();
    }
    return answer;
}
