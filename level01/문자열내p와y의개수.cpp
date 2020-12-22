#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int i;
    int p = 0;
    int y = 0;

    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == 'p' || s[i] == 'P')
        {
            p++;
        } 
        else if (s[i] == 'y' || s[i] == 'Y')
        {
            y++;
        }
    }
    if (p != y)
    {
        answer = false;
    }
    return answer;
}
