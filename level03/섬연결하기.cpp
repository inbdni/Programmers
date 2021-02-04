#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int getParent(int a)
{
    if (parent[a] == a)
        return a;
    return getParent(parent[a]);
}

int isCycle(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a == b)
        return true;
    return false;
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int i;
    int a, b;
    
    sort(costs.begin(), costs.end(), cmp);
    for (i = 0; i < n; i++)
    {
        parent.push_back(i);
    }
    for (i = 0; i < costs.size(); i++)
    {
        a = costs[i][0];
        b = costs[i][1];
        if (isCycle(a, b))
            continue;
        answer += costs[i][2];
        unionParent(a, b);
    }
    return answer;
}
