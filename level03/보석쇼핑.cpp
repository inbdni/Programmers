#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer (2);
    unordered_map<string, int> um;
    int i, s = 0, e = 0; 
    int dist, total;

    for (i = 0; i < gems.size(); i++)
    {
        um[gems[i]]++;
    }
    dist = gems.size() + 1;
    total = um.size();
    um.clear();
    while (1)
    {
        if (um.size() == total)
        {
            if (e - s < dist)
            {
                dist = e - s;
                answer[0] = s + 1;
                answer[1] = e;
            }
            um[gems[s]]--;
            if (um[gems[s]] == 0)
            {
                um.erase(gems[s]);
            }
            s++;
        }
        else
        {
            if (e == gems.size())
            {
                break;
            }
            um[gems[e]]++;
            e++;
        }
    }
    return answer;
}
