#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    string idx;
    
    idx = to_string(distance(seoul.begin(), find(seoul.begin(), seoul.end(), "Kim")));
    answer += "김서방은 ";
    answer += idx;
    answer += "에 있다";
    return answer;
}
