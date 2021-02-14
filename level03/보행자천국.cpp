#include <vector>

#define v   0
#define h   1
#define MOD 20170805

using namespace std;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer;
    int d[m][n][2];
    int i, j, value, tmp;
    
    for (i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                d[i][j][v] = 1;
                d[i][j][h] = 1;
                continue;
            }
            value = city_map[i][j];
            if (value == 0)
            {
                tmp = (i > 0) ? d[i - 1][j][v] : 0;
                tmp += (j > 0) ? d[i][j - 1][h] : 0;
                d[i][j][v] = tmp % MOD;
                d[i][j][h] = tmp % MOD;
            }
            else if (value == 1)
            {
                d[i][j][v] = 0;
                d[i][j][h] = 0;
            }
            else if (value == 2)
            {
                d[i][j][v] = (i > 0) ? d[i - 1][j][v] : 0;
                d[i][j][h] = (j > 0) ? d[i][j - 1][h] : 0;
            }
        }
    }
    answer = d[m - 1][n - 1][v];
    return answer;
}
