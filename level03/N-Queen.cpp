#include <string>
#include <vector>

using namespace std;

vector<int> board;
int answer;

void dfs(int r, int n)
{
    int i, j;
    
    if (r > n)
    {
        answer++;
        return;
    }
    for (i = 1; i <= n; i++)
    {
        board[r] = i;
        for (j = 1; j < r; j++)
        {
            if (board[j] == i || abs(r - j) == abs(i - board[j]))
            {
                board[r] = 0;
                break;
            }
        }
        if (board[r])
            dfs(r + 1, n);
    }
}

int solution(int n)
{
    board.resize(n + 1, 0);
    dfs(1, n);
    return answer;
}
