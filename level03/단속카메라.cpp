#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int i, camera;
    
    sort(routes.begin(), routes.end());
    camera = routes[0][1];
    for (i = 1; i < routes.size(); i++)
    {
        if (camera < routes[i][0])
        {
            camera = routes[i][1];
            answer++;
        }
        if (camera > routes[i][1])
        {
            camera = routes[i][1];
        }
    }
    return answer;
}
