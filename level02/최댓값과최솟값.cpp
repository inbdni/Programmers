#include <string>
#include <vector>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    string num = "";
    int min_num = INT_MAX;
    int max_num = INT_MIN;
    int i;
    
    for (i = 0; i <= s.size(); i++)
    {
        if (s[i] == ' ' || i == s.size())
        {
            min_num = min(min_num, stoi(num));
            max_num = max(max_num, stoi(num));
            num.clear();
        }
        else
        {
            num += s[i];
        }
    }
    answer += to_string(min_num) + " " + to_string(max_num);
    return answer;
}
