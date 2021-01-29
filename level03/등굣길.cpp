#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> mem(n + 1, vector<int> (m + 1, 0));
    int i, j;
    
    for (i = 0; i < puddles.size(); i++)
    {
        mem[puddles[i][1]][puddles[i][0]] = -1;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                mem[i][j] = 1;
            }
            else
            {
                if (mem[i][j] < 0)
                    continue;
                if (i > 1 && mem[i - 1][j] != -1)
                    mem[i][j] += mem[i - 1][j];
                if (j > 1 && mem[i][j - 1] != -1)
                    mem[i][j] += mem[i][j - 1];
                mem[i][j] %= 1000000007;
            }
        }
    }
    answer = mem[n][m];
    return answer;
}
