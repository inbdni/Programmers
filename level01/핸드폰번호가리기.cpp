#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int i;
    
    for (i=0; i < phone_number.size() - 4; i++)
    {
        answer.push_back('*');
    }
    for (i = phone_number.size() - 4; i < phone_number.size(); i++)
    {
        answer.push_back(phone_number[i]);
    }
    return answer;
}
