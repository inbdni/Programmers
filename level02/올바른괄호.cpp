#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int opened = 0;
    int i = 0;
    
    while (s[i] != 0)
	{
        if (s[i] == '(')
		{
            opened++;
        }
		else
		{
            if (opened == 0)
			{
                answer = false;
                break;
            }
			else 
			{
                opened--;
            }
        }
        i++;
    }
    if (opened != 0)
        answer = false;
    return answer;
}
