#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int loc = location;
    int max = *max_element(priorities.begin(), priorities.end());
    int prio;

    while (!priorities.size())
    {
        prio = priorities[0];
        priorities.erase(priorities.begin());
        
        if (prio < max)
            priorities.push_back(prio);
        else
        {
            answer++;
            if (loc == 0)
                return answer;
            max = *max_element(priorities.begin(), priorities.end());
        }
		if (loc == 0)
            loc = priorities.size() - 1;
        else
            loc--;
    }
}
