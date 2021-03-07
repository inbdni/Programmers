#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>

#define N       4
#define MAX_NUM 7

using namespace std;

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

vector<vector<pos>> card;
string diff_per;
string same_per;
int card_num;

void init_card(vector<vector<int>> &board)
{
    pos p;
    int i, j;
    
    card.clear(); 
    card.resize(MAX_NUM);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j])
            {
                p.init(i, j);
                card[board[i][j]].push_back(p);
            }
        }
    }
}

void init_diff()
{
    int i;
    
    diff_per.clear();
    for (i = 1; i < MAX_NUM; i++)
    {
        if (!card[i].empty())
            diff_per += to_string(i);
    }
}

void init_same(int r)
{
    int i;
    int n = card_num;
    
    same_per.clear();
    for (i = 0; i < n - r; i++)
        same_per += "0";
    for (i = n - r; i < n; i++)
        same_per += "1";
}

bool in_range(pos p)
{
    if (p.r < 0 || p.r >= N || p.c < 0 || p.c >= N)
        return false;
    return true;
}

int get_dist(pos src, pos dst, vector<vector<int>> &board)
{
    queue<pos> q;
    pos curr, next, tmp;
    int d[] = {-1, 1, 0, 0};
    bool visit[N][N];
    int i, j, size;
    int res = 0;
    
    memset(visit, false, sizeof(visit));
    visit[src.r][src.c] = true;
    q.push(src);
    while (!q.empty())
    {
        size = q.size();
        for (i = 0; i < size; i++)
        {
            curr = q.front();
            q.pop();
            if (curr.r == dst.r && curr.c == dst.c)
            {
                return res;
            }
            for (j = 0; j < 4; j++)
            {
                next.init(curr.r + d[j], curr.c + d[3 - j]);
                if (!in_range(next) || visit[next.r][next.c])
                    continue;
                visit[next.r][next.c] = true;
                q.push(next);
            }
            for (j = 0; j < 4; j++)
            {
                next = curr;
                while (1)
                {
                    tmp.init(next.r + d[j], next.c + d[3 - j]);
                    if (!in_range(tmp))
                        break;
                    next.r += d[j];
                    next.c += d[3 - j];
                    if (board[next.r][next.c])
                        break;
                }
                if (visit[next.r][next.c])
                    continue;
                visit[next.r][next.c] = true;
                q.push(next);
            }
        }
        res++;
    }  
}

int game(vector<vector<int>> board, int r, int c)
{
    vector<pos> order;
    pos p;
    int i, j, a, b;
    int res = 0;
    
    p.init(r, c);
    order.push_back(p);
    for (i = 0; i < card_num; i++)
    {
        a = diff_per[i] - '0';
        b = same_per[i] - '0';
        order.push_back(card[a][b]);
        b = abs(b - 1);
        order.push_back(card[a][b]);
    }
    for (i = 1; i < order.size(); i++)
    {
        res += get_dist(order[i - 1], order[i], board);
        if (i % 2 == 0)
        {
            p = order[i - 1];
            board[p.r][p.c] = 0;
            p = order[i];
            board[p.r][p.c] = 0;
            res += 2;
        }
    }
    return res;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INT_MAX;
    int i;
    
    init_card(board);
    init_diff();
    card_num = diff_per.size();
    do
    {
        for (i = 0; i <= card_num; i++)
        {
            init_same(i);
            do
            {
                answer = min(answer, game(board, r, c));
            } while (next_permutation(same_per.begin(), same_per.end()));
        }
    } while (next_permutation(diff_per.begin(), diff_per.end()));
    return answer;
}
