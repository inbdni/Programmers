#include <string>
#include <vector>

using namespace std;

void dfs(int com, int n, vector<vector<int>> &computers)
{
    int i;
    
    computers[com][com] = 0;
    for (i = 0; i < n; i++)
    {
        if (computers[com][i] && computers[i][i])
            dfs(i, n, computers); 
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int i;
    
    for (i = 0; i < n; i++)
    {
        if (computers[i][i])
        { 
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}
