#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int i, j, k, max_value;
    int row = land.size();
    int col = land[0].size();
    int m[row][col];
    
    for (i = 0; i < col; i++)
    {
        m[0][i] = land[0][i];
    }
    for (i = 1; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            max_value = 0;
            for (k = 0; k < col; k++)
            {
                if (j == k)
                    continue;
                max_value = max(max_value, m[i - 1][k]);
            }
            m[i][j] = land[i][j] + max_value;
            answer = max(answer, m[i][j]);
        }
    }
    return answer;
}
