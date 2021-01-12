#include <string>
#include <vector>

using namespace std;

void compression(vector<vector<int>> &arr, int size, int x, int y, vector<int> &answer)
{   
    int i;
    int j;
    int target;
    bool same = true;

    target = arr[y][x];
    for (i = y; i < y + size; i++)
    {
        for (j = x; j < x + size; j++)
        {
            if (arr[i][j] != target)
            {
                same = false;
                break;
            }
        }
        if (!same)
            break;
    }
    if (same)
    {
        answer[target]++;
        return;
    }
    size /= 2;
    compression(arr, size, x, y, answer);
    compression(arr, size, x, y + size, answer);
    compression(arr, size, x + size, y, answer);
    compression(arr, size, x + size, y + size, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    compression(arr, arr.size(), 0, 0, answer);
    return answer;
}
