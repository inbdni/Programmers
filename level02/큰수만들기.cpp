#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int i = 0;
    int len = number.size() - k;
    
    while(k && i < number.size())
    {
        while (k && !answer.empty() && answer.back() < number[i])
        {
            answer.pop_back();
            k--;
        }
        answer += number[i++];
    }
    while (i < number.size())
    {
        answer += number[i++];
    }
    while (answer.size() > len)
    {
        answer.pop_back();
    }
    return answer;
}
