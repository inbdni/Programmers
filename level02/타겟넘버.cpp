#include <string>
#include <vector>

using namespace std;

void dfs(int r, vector<int> numbers, int sum, int target, int *answer) {
    if (r == numbers.size())
    {
        if (sum == target)
            (*answer)++;
        return;
    }
    dfs(r + 1, numbers, sum + numbers[r], target, answer);
    dfs(r + 1, numbers, sum - numbers[r], target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, numbers, 0, target, &answer);
    return answer;
}
