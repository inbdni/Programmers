#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int i;
    int diff = 0;
    unordered_map<int, int> um;
    
    answer = nums.size() / 2;
    for (i = 0; i < nums.size(); i++)
    {
        um[nums[i]]++;
        if (um[nums[i]] == 1)
            diff++;
    }
    answer = min(diff, answer);
    return answer;
}
