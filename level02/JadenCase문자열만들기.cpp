#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool first = true;
    int i;
    
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            first = true;
            continue;
        }
        if (first)
        {
            first = false;
            if (isalpha(s[i]))
                s[i] = toupper(s[i]); 
        }
        else 
        {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
        }
    }
    return s;
}
