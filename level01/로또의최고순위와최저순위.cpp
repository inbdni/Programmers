#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_rank(int match)
{
    if (match == 6)
        return 1;
    if (match < 2)
        return 6;
    return 7 - match;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int i;
    int unknown = 0;
    int match = 0;
    
    for (i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            unknown++;
            continue;
        }
        if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            match++;
        }
    }
    answer.push_back(get_rank(match + unknown));
    answer.push_back(get_rank(match));
    return answer;
}
