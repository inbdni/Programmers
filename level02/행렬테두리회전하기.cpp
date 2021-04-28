#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;

void init(int rows, int columns)
{
    int i, j, num = 1;
    
    board.resize(rows + 1, vector<int> (columns + 1));
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= columns; j++)
        {
            board[i][j] = num++;
        }
    }
}

int rot(int x1, int y1, int x2, int y2)
{
    queue<int> q;
    int x, y, res = 2e9;
    
    x = x1;
    y = y1;
    while (y < y2)
        q.push(board[x][y++]);
    while (x < x2)
        q.push(board[x++][y]);
    while (y > y1)
        q.push(board[x][y--]);
    while (x > x1)
        q.push(board[x--][y]);
    x = x1;
    y = y1;
    while (y < y2)
    {
        res = min(res, q.front());
        board[x][++y] = q.front();
        q.pop();
    }
    while (x < x2)
    {
        res = min(res, q.front());
        board[++x][y] = q.front();
        q.pop();
    }
    while (y > y1)
    {
        res = min(res, q.front());
        board[x][--y] = q.front();
        q.pop();
    }
    while (x > x1)
    {
        res = min(res, q.front());
        board[--x][y] = q.front();
        q.pop();
    }
    return res;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int i, min_value;
    
    init(rows, columns);
    for (i = 0; i < queries.size(); i++)
    {
        min_value = rot(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        answer.push_back(min_value);
    }
    return answer;
}
