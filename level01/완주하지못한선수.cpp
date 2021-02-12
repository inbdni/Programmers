#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> um;
    int i;
    
    for (i = 0; i < completion.size(); i++)
    {
        um[completion[i]]++;
    }
    for (i = 0; i < participant.size(); i++)
    {
        if (!um[participant[i]])
        {
            answer += participant[i];
            break;
        }
        um[participant[i]]--;
    }
    return answer;
}
