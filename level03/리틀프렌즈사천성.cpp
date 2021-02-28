#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

struct pos
{
    int m;
    int n;
    int r;
    bool turn;
    
    void init(int m, int n, int r, bool turn)
    {
        this->m = m;
        this->n = n;
        this->r = r;
        this->turn = turn;
    }
};

int M;
int N;
int d[] = {-1, 1, 0, 0};
bool visit[101][101][4];
map<char, vector<pair<int, int>>> tile;

bool in_range(int m, int n)
{
    if (m < 0 || m >= M || n < 0 || n >= N)
        return false;
    return true;
}

bool find_pair(char target, vector<string> &board)
{
    queue<pos> q;
    pos curr, next;
    int i, m, n;
    
    memset(visit, false, sizeof(visit));
    m = tile[target][0].first;
    n = tile[target][0].second;
    for (i = 0; i < 4; i++)
    {
        visit[m][n][i] = true;
        next.init(m + d[i], n + d[3 - i], i, false);
        if (!in_range(next.m, next.n))
        {
            continue;
        }
        q.push(next);
        visit[next.m][next.n][i] = true;
    }
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (board[curr.m][curr.n] == target)
        {
            board[m][n] = '.';
            board[curr.m][curr.n] = '.';
            return true;
        }
        if (board[curr.m][curr.n] != '.')
        {
            continue;
        }
        for (i = 0; i < 4; i++)
        {
            next.init(curr.m + d[i], curr.n + d[3 - i], i, curr.turn);
            if (curr.r != i)
            {
                if (curr.turn)
                {
                    continue;
                }
                next.turn = true;
            }
            if (!in_range(next.m, next.n) || visit[next.m][next.n][next.r])
            {
                continue;
            }
            q.push(next);
            visit[next.m][next.n][next.r] = true;
        }
    }
    return false;
}

void find(string &answer, vector<string> &board)
{
    char target;
    bool remove;
    
    while (!tile.empty())
    {
        remove = false;
        for (auto t : tile)
        {
            target = t.first;
            if (find_pair(target, board))
            {
                remove = true;
                answer += target;
                tile.erase(target);
                break;
            }
        }
        if (!remove)
        {
            answer = "IMPOSSIBLE";
            break;
        }
    }
}

void check_tile(vector<string> &board)
{
    int i, j;
    
    tile.clear();
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (isalpha(board[i][j]))
            {
                tile[board[i][j]].push_back(make_pair(i, j));
            }
        }
    }
}

string solution(int m, int n, vector<string> board)
{
    string answer = "";
    
    M = m;
    N = n;
    check_tile(board);
    find(answer, board);
    return answer;
}
