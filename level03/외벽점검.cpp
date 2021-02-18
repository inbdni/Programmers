#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    int i, j, k;
    int limit, size = weak.size();
    bool flag;
    
    for (i = 0; i < size - 1; i++)
    {
        weak.push_back(weak[i] + n);
    }
    sort(dist.begin(), dist.end());
    do
    {
        for (i = 0; i < size; i++)
        {
            k = 0;
            flag = true;
            limit = weak[i] + dist[k];
            for (j = i; j < i + size; j++)
            {
                if (weak[j] > limit)
                {
                    if (k + 1 == dist.size())
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        limit = weak[j] + dist[++k];
                    }
                }
            }
            if (flag)
            {
                answer = min(answer, k + 1);
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    if (answer == 10)
        answer = -1;
    return answer;
}
