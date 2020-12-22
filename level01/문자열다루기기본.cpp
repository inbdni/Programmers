#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int i;
    
    if (s.size() != 4 && s.size() != 6)
    {
        answer = false;
        return answer;
    }
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            answer = false;
            break;
        }
    }
    return answer;
}
