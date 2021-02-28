#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int tmp, int to)
{
    vector<int> v;
    
    v.push_back(from);
    v.push_back(to);
    if (n == 1)
    {
        answer.push_back(v);
        return;
    }
    hanoi(n - 1, from, to, tmp);
    answer.push_back(v);
    hanoi(n - 1, tmp, from, to);
}

vector<vector<int>> solution(int n)
{
    hanoi(n, 1, 2, 3);
    return answer;
}
