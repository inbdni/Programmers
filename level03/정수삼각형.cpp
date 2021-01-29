#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> m;
    vector<int> tmp;
    int i, j;
    int left, right;
    
    tmp.push_back(triangle[0][0]);
    m.push_back(tmp);
    for (i = 1; i < triangle.size(); i++)
    {
        tmp.clear();
        for (j = 0; j < triangle[i].size(); j++)
        {
            left = (j > 0) ? m[i - 1][j - 1] : 0;
            right = (j < i) ? m[i - 1][j] : 0;
            tmp.push_back(max(left, right) + triangle[i][j]);
            if (i == triangle.size() - 1)
                answer = max(answer, max(left, right) + triangle[i][j]);
        }
        m.push_back(tmp);
    }
    return answer;
}
