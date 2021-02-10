#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    int i, op, num;
    
    for (i = 0; i < operations.size(); i++)
    {
        op = operations[i][0];
        num = stoi(operations[i].substr(2));
        if (op == 'I')
        {
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else
        {
            if (dq.empty())
                continue;
            if (num == -1)
                dq.pop_front();
            else
                dq.pop_back();
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    if (dq.size())
    {
        answer[0] = dq.back();
        answer[1] = dq.front();
    }
    return answer;
}
