#include <string>
#include <vector>
#include <climits>

using namespace std;

int dfs(int depth, string begin, string target, vector<string> &words, vector<bool> &used)
{
    int i, j, cnt;
    int res = INT_MAX;
    
    if (depth == words.size())
    {
        return INT_MAX;
    }
    if (begin.compare(target) == 0)
    {
        return depth;
    }
    for (i = 0; i < words.size(); i++)
    {
        if (used[i])
        {
            continue;
        }
        cnt = 0;
        for (j = 0; j < begin.size(); j++)
        {
            if (begin[j] != words[i][j])
                cnt++;
            if (cnt > 1)
                break;
        }
        if (cnt == 1)
        {
            used[i] = true;
            res = min(res, dfs(depth + 1, words[i], target, words, used));
            used[i] = false;
        }
    }
    return res;
}

int solution(string begin, string target, vector<string> words) {
    int answer = INT_MAX;
    vector<bool> used;
    
    used.resize(words.size(), false);
    answer = min(answer, dfs(0, begin, target, words, used));
    if (answer == INT_MAX)
        return 0;
    return answer;
}
