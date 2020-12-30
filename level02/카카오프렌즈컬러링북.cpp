#include <vector>
#include <queue>

using namespace std;

int bfs(int y, int x, int m, int n, vector<vector<int>> &picture)
{
    int i, dy, dx;
    int d[] = {0, 0, -1, 1};
    int target = picture[y][x];
    int size = 1;
    queue<pair<int, int>> q;
    
    q.push(make_pair(y, x));
    picture[y][x] = -1;
    
    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        for (i = 0; i < 4; i++)
        {
            dy = y + d[i];
            dx = x + d[3 - i];
            if (dy >= 0 && dy < m && dx >= 0 && dx < n)
            {
                if (picture[dy][dx] == target)
                {
                    picture[dy][dx] = -1;
                    q.push(make_pair(dy, dx));
                    size++;
                }
            }
        }
    }
    return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;   
    vector<int> answer(2);
    
    int x;
    int y;
    int size;

    y = 0;
    while (y < m)
    {
        x = 0;
        while (x < n)
        {
            if (picture[y][x] > 0)
            {
                size = bfs(y, x, m, n, picture);
                number_of_area++;
                max_size_of_one_area = max(size, max_size_of_one_area);
            }
            x++;
        }
        y++;
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
