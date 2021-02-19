#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int a;  // y1
    int b;  // x1
    int c;  // y2
    int d;  // x2
    int r;  // 가로 : 0, 세로 : 1
    
    void init(int a, int b, int c, int d, int r)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->r = r;
    }
};

int N;
int m[101][101][2];
int d[] = {-1, 1, 0, 0};

bool is_dest(pos p)
{
    if (p.a == N && p.b == N - 1 && p.r == 0)
    {
        return true;
    }
    if (p.a == N - 1 && p.b == N && p.r == 1)
    {
        return true;
    }
    return false;
}

void push_pos(queue<pos> &q, pos p, int dist)
{
    if (!m[p.a][p.b][p.r])
    {
        q.push(p);
        m[p.a][p.b][p.r] = dist + 1;
    }
}

int bfs(vector<vector<int>> &board)
{
    queue<pos> q;
    pos curr, next;
    int i, dist;
    
    next.init(1, 1, 1, 2, 0);
    q.push(next);
    m[next.a][next.b][next.r] = 1;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        dist = m[curr.a][curr.b][curr.r];
        if (is_dest(curr))
        {
            return dist - 1;
        }
        for (i = 0; i < 4; i++)
        {
            next.init(curr.a + d[i], curr.b + d[3 - i], curr.c + d[i], curr.d + d[3 - i], curr.r);
            if (next.a >= 1 && next.c <= N && next.b >= 1 && next.d <= N)
            {
                if (!board[next.a - 1][next.b - 1] && !board[next.c - 1][next.d - 1])
                {
                    push_pos(q, next, dist);
                }
            }
        }
        if (curr.r == 0)
        {
            if (curr.a > 1 && !board[curr.a - 2][curr.b - 1] && !board[curr.c - 2][curr.d - 1])
            {
                next.init(curr.a - 1, curr.b, curr.a, curr.b, !curr.r);
                push_pos(q, next, dist);
                next.init(curr.c - 1, curr.d, curr.c, curr.d, !curr.r);
                push_pos(q, next, dist);
            }
            if (curr.c < N && !board[curr.a][curr.b - 1] && !board[curr.c][curr.d - 1])
            {
                next.init(curr.a, curr.b, curr.a + 1, curr.b, !curr.r);
                push_pos(q, next, dist);
                next.init(curr.c, curr.d, curr.c + 1, curr.d, !curr.r);
                push_pos(q, next, dist);
            }
        }
        else
        {
            if (curr.b > 1 && !board[curr.a - 1][curr.b - 2] && !board[curr.c - 1][curr.d - 2])
            {
                next.init(curr.a, curr.b - 1, curr.a, curr.b, !curr.r);
                push_pos(q, next, dist);
                next.init(curr.c, curr.d - 1, curr.c, curr.d, !curr.r);
                push_pos(q, next, dist);
            }
            if (curr.d < N && !board[curr.a - 1][curr.b] && !board[curr.c - 1][curr.d])
            {
                next.init(curr.a, curr.b, curr.a, curr.b + 1, !curr.r);
                push_pos(q, next, dist);
                next.init(curr.c, curr.d, curr.c, curr.d + 1, !curr.r);
                push_pos(q, next, dist);
            }
        }

    }
    return 0;
}

int solution(vector<vector<int>> board)
{
    int answer;

    N = board.size();
    answer = bfs(board);
    return answer;
}
