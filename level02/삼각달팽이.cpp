#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int i;
    int x = 0;
    int y = 0;
    int num = 1;
    int flag = 0;
    int filled[1001][1001];
    
    while (flag < n)
    {
        i = flag;
        if (flag % 3 == 0)
        {
            while (i++ < n)
                filled[y++][x] = num++;
            y--;
            x++;
        }
        else if (flag % 3 == 1)
        {
            while (i++ < n)
                filled[y][x++] = num++;
            y--;
            x -= 2;
        }
        else
        {
            while (i++ < n)
                filled[y--][x--] = num++;
            y += 2;
            x++;
        }
        flag++;
    }
    for (y = 0; y < n; y++)
    {
        for (x = 0; x <= y; x++)
            answer.push_back(filled[y][x]);
    }
    return answer;
}
