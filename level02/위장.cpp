#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int i;
    unordered_map<string, int> comb;
    unordered_map<string, int>::iterator it;
    
    for (i = 0; i < clothes.size(); i++)
    {
        comb[clothes[i][1]]++;
    }
    for (it = comb.begin(); it != comb.end(); it++)
    {
        answer *= it->second + 1;
    }
    return answer - 1;
}
