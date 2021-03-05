#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct track
{
    int r;
    int c;
    int dir;
    int go;
    int turn;
    
    void init(int r, int c, int dir, int go, int turn)
    {
        this->r = r;
        this->c = c;
        this->dir = dir;
        this->go = go;
        this->turn = turn;
    }
};

bool in_range(int r, int c, int N)
{
    if (r < 0 || r >= N || c < 0 || c >= N)
        return false;
    return true;
}

int calc(track t)
{
    return t.go * 100 + t.turn * 500;
}

int bfs(int N, vector<vector<int>> &board)
{
    queue<track> q;
    track curr, next;
    int d[] = {-1, 1, 0, 0};
    vector<vector<int>> m;
    int i;
    
    m.resize(N, vector<int> (N, INT_MAX));
    for (i = 0; i < 4; i++)
    {
        curr.init(0, 0, i, 0, 0);
        m[0][0] = 0;
        q.push(curr);
    }
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        for (i = 0; i < 4; i++)
        {
            next.init(curr.r + d[i], curr.c + d[3 - i], i, curr.go + 1, curr.turn);
            if (curr.dir != next.dir)
                next.turn++;
            if (!in_range(next.r, next.c, N))
                continue;
            if (board[next.r][next.c])
                continue;
            if (m[next.r][next.c] < calc(next))
                continue;
            m[next.r][next.c] = calc(next);
            q.push(next);
        }
    }
    return m[N - 1][N - 1];
}

int solution(vector<vector<int>> board)
{
    int answer;
    
    answer = bfs(board.size(), board);
    return answer;
}
