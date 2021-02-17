#include <string>
#include <vector>

using namespace std;

bool w[101][101][2];

bool check_0(int x, int y, int n)
{
    if (y == 0) 
        return 1;
    if (w[x][y - 1][0]) 
        return 1;
    if (x > 0 && w[x - 1][y][1]) 
        return 1;
    if (x < n && w[x][y][1]) 
        return 1;
    return 0;
}

bool check_1(int x, int y, int n)
{
    if (y > 0 && w[x][y - 1][0]) 
        return 1;
    if (x < n && y > 0 && w[x + 1][y - 1][0]) 
        return 1;
    if (x > 0 && x < n && w[x + 1][y][1] && w[x - 1][y][1]) 
        return 1;
    return 0;
}

bool del_0(int x, int y, int n)
{
    if (y < n && w[x][y + 1][0] && !check_0(x, y + 1, n))
        return 0;
    else if (y < n && w[x][y + 1][1] && !check_1(x, y + 1, n))
        return 0;
    else if (x > 0 && w[x - 1][y + 1][1] && y < n && !check_1(x - 1, y + 1, n))
        return 0;
    return 1;
}

bool del_1(int x, int y, int n)
{
    if (w[x][y][0] && !check_0(x, y, n))
        return 0;
    else if (x < n && w[x + 1][y][0] && !check_0(x + 1, y, n))
        return 0;
    else if (x > 0 && w[x - 1][y][1] && !check_1(x - 1, y, n))
        return 0;
    else if (x < n && w[x + 1][y][1] && !check_1(x + 1, y, n))
        return 0;
    return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> v(3);
    int i, x, y, a, b;
    
    for (i = 0; i < build_frame.size(); i++) {       
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        if (a == 0 && b == 1) 
        {
            if (check_0(x, y, n))
                w[x][y][a] = 1;
        }
        else if (a == 1 && b == 1)
        {
            if (check_1(x, y, n))
                w[x][y][a] = 1;
        }
        else if (a == 0 && b == 0)
        {
            w[x][y][0] = 0;
            if (!del_0(x, y, n)) 
                w[x][y][a] = 1;
        }
        else if (a == 1 && b == 0)
        {
            w[x][y][1] = 0;
            if (!del_1(x, y, n)) 
                w[x][y][a] = 1;
        }
    }
    for (x = 0; x <= n; x++)
    {
        for (y = 0; y <= n; y++)
        {
            for (a = 0; a < 2; a++)
            {
                if (w[x][y][a])
                {
                    v[0] = x;
                    v[1] = y;
                    v[2] = a;
                    answer.push_back(v);
                }
            }
        }
    }
    return answer;
}
