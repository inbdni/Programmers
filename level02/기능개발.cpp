#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int num;
    int remain;
    
    while (!progresses.empty())
    {
        num = 0;
        while (!progresses.empty())
        {
            remain = 100 - progresses[0];
            if (remain <= speeds[0] * day)
            {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                num++;
            }
            else
            {
                break;
            }
        }
        if (num != 0)
        {
            answer.push_back(num);
        }
        day++;
    }
    return answer;
}
