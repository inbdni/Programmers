#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    vector<int> temp;
    int i;
    
    for (i = 0; i < s.size(); i++)
    {
        temp.push_back(s[i]);
    }
    for (i = 0; i < temp.size(); i++)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
        {
            temp[i] += n;
            if (temp[i] > 'Z')
            {
                temp[i] -= 26;
            }
        }
        if (temp[i] >= 'a' && temp[i] <= 'z')
        {
            temp[i] += n;
            if (temp[i] > 'z')
            {
                temp[i] -= 26;
            }
        }
        answer += temp[i];
    }
    return answer;
}
