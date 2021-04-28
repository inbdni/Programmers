#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    int i, j, k;
    int lx, ly, rx, ry, mx, my;
    bool flag;
    
    sort(data.begin(), data.end());
    for (i = 0; i < data.size(); i++)
    {
        lx = data[i][0];
        ly = data[i][1];
        for (j = i + 1; j < data.size(); j++)
        { 
            rx = data[j][0];
            ry = data[j][1];
            if (lx == rx || ly == ry)
                continue;
            flag = true;
            for (k = i + 1; k < j; k++)
            {
                mx = data[k][0];
                my = data[k][1];
                if (min(lx, rx) < mx && mx < max(lx, rx) && min(ly, ry) < my && my < max(ly, ry))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                answer++;
        }
    }
    return answer;
}
