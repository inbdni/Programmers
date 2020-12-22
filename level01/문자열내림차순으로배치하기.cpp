#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> temp;
    long long i;
    
    for (i = 0; i < s.size(); i++)
    {
        temp.push_back(s[i]);
    }
    sort(temp.begin(), temp.end());
    for (i = temp.size() - 1; i >= 0; i--)
    {
        answer += temp[i];
    }
    return answer;
}
