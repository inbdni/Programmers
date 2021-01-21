#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int x, y, tmp;
    int row = board.size();
    int col = board[0].size();
    int square[row][col];
    
    for (y = 0; y < row; y++)
    {
        square[y][0] = board[y][0];
        answer = max(answer, square[y][0]);
    }
    for (x = 0; x < col; x++)
    {
        square[0][x] = board[0][x];
        answer = max(answer, square[0][x]);
    }
    for (y = 1; y < row; y++)
    {
        for (x = 1; x < col; x++)
        {
            if (!board[y][x])
            {
                square[y][x] = 0;
                continue;
            }
            tmp = min(square[y - 1][x], min(square[y - 1][x - 1], square[y][x - 1]));
            square[y][x] = tmp + 1;
            answer = max(answer, square[y][x]);
        }
    }
    return answer * answer;
}
