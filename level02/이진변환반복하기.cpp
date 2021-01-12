#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string one = "";
    int i;
    int cnt = 1;
    int zero = 0;
    int len = s.size();
    
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            one += s[i];
        else
            zero++;
    }
    len = one.size();
    one.clear();
    while (len != 1)
    {
        cnt++;
        while (len)
        {
            if (len % 2)
                one += "1";
            else
                zero++;
            len /= 2;
        }
        len = one.size();
        one.clear();
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}
