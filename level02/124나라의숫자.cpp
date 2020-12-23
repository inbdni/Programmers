#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<char> num = {'1', '2', '4'};
    
    while (n > 0)
    {
        answer = num[(n-1) % 3] + answer;
        n = (n-1) / 3;
    }
    return answer;
}
