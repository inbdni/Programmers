#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> temp;
    int i, j, row, cul;
    
    row = arr1.size();
    cul = arr1[0].size();
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < cul; j++)
        {
           temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temp);
        temp.clear();
    }
    return answer;
}
