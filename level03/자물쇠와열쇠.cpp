#include <string>
#include <vector>

using namespace std;

int n;
int m;
int l;

void rot(vector<vector<int>> &key)
{
    vector<vector<int>> tmp(key);
    int i, j;

    for (i = 0; i < key.size(); i++)
    {
        for (j = 0; j < key.size(); j++)
        {
            key[i][j] = tmp[j][abs(m - 1 - i)];
        }
    }
}

bool fit(int y, int x, vector<vector<int>> &key, vector<vector<int>> board)
{
    int i, j;
    
    for (i = y; i < y + m; i++)
    {
        for (j = x; j < x + m; j++)
        {
            board[i][j] += key[i - y][j - x];
        }
    }
    for (i = m - 1; i <= l - m; i++)
    {
        for (j = m - 1; j <= l - m; j++)
        {
            if (board[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> board;
    vector<int> v;
    int i, j, k;

    n = lock.size();
    m = key.size();
    l = n + 2 * (m - 1);
    
    v.resize(l, 0);
    board.resize(l, v);
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            board[m - 1 + i][m - 1 + j] = lock[i][j];
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j <= l - m; j++)
        {
            for (k = 0; k <= l - m; k++)
            {
                if (fit(j, k, key, board))
                    return true;
            }
        }
        rot(key);
    }
    return false;
}
