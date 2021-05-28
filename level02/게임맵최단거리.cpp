#include <vector>
#include <queue>

using namespace std;

int N;
int M;

struct pos
{
    int r;
    int c;
    
    void init(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
};

bool in_range(pos p)
{
    if (p.r < 0 || p.r >= N || p.c < 0 || p.c >= M)
        return false;
    return true;
}

int bfs(vector<vector<int>> maps)
{
    queue<pos> q;
    pos curr, next;
    vector<vector<bool>> visit;
    int d[] = {0, 0, -1, 1};
    int i, s, size, cnt = 0;
    
    visit.resize(N, vector<bool> (M, false));
    curr.init(0, 0);
    q.push(curr);
    visit[curr.r][curr.c] = true;
    while (!q.empty())
    {
        cnt++;
        size = q.size();
        for (s = 0; s < size; s++)
        {
            curr = q.front();
            q.pop();
            if (curr.r == N - 1 && curr.c == M - 1)
            {
                return cnt;
            }
            for (i = 0; i < 4; i++)
            {
                next.init(curr.r + d[i], curr.c + d[3 - i]);
                if (!in_range(next))
                    continue;
                if (visit[next.r][next.c])
                    continue;
                if (!maps[next.r][next.c])
                    continue;
                q.push(next);
                visit[next.r][next.c] = true;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer;
    
    N = maps.size();
    M = maps[0].size();
    answer = bfs(maps);
    return answer;
}
