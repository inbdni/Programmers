#include <string>
#include <cstring>

using namespace std;

int convert(char c)
{
    switch (c)
    {
        case 'U': return 0;
        case 'D': return 1;
        case 'R': return 2;
        case 'L': return 3;
    }
}

int opposite(int i)
{
    switch(i)
    {
        case 0: return 1;
        case 1: return 0;
        case 2: return 3;
        case 3: return 2;
    }
}

int solution(string dirs)
{
    int answer = 0;
    int i, x, y, dx, dy, cmd;
    int d[] = {-1, 1, 0, 0};
    bool visited[11][11][4];
    
    x = 5;
    y = 5;
    memset(visited, false, sizeof(visited));
    for (i = 0; i < dirs.size(); i++)
    {
        cmd = convert(dirs[i]);
        dx = x + d[3 - cmd];
        dy = y + d[cmd];
        if (dx < 0 || dx > 10 || dy < 0 || dy > 10)
            continue;
        if (!visited[dx][dy][cmd])
        {
            visited[dx][dy][cmd] = true;
            visited[x][y][opposite(cmd)] = true;
            answer++;
        }
        x = dx;
        y = dy;
    }
    return answer;
}
