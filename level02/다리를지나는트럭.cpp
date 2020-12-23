#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> bridge;
    int curr_weight = 0;
    int next = 0;
    int done = 0;
    
    while (done < truck_weights.size())
    {
        answer++;
        if (bridge.size() == bridge_length)
        {
            curr_weight -= bridge[0];
            if (bridge[0] != 0)
            {
                done++;
            }   
            bridge.erase(bridge.begin());
        }
        if (curr_weight + truck_weights[next] <= weight)
        {
            curr_weight += truck_weights[next];
            bridge.push_back(truck_weights[next]);
            next++;
        }
        else
        {
            bridge.push_back(0);
        }
    }
    return answer;
}
