#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    int i;
    
    for (i = 0; i < s.size(); i++)
    {        
        if (s[i] == ' ')
        {
            answer += ' ';
            index = 0;
            continue;
        }
        if (index % 2 == 0)
        {
            if (s[i] > 90 )
                answer += s[i] - 32;
            else
                answer += s[i];
        }
        else 
        {
            if (s[i] < 97) 
                answer += s[i] + 32;
            else
                answer += s[i];
        }
        index++;
    }
    return answer;
}
