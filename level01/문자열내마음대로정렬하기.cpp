#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compare(string s1, string s2) {
    if (s1[N] < s2[N])
        return true;
    else if (s1[N] == s2[N])
        return s1 < s2;
    else
        return false;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    N = n;
    answer.assign(strings.begin(), strings.end());
    sort(answer.begin(), answer.end(), compare);
    return answer;
}
