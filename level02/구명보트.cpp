#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i;
    int weight;

    i = 0;
    sort(people.begin(), people.end());
    while (i < people.size())
    {
        weight = people.back();
        people.pop_back();
        while (weight + people[i] <= limit)
        {
            weight += people[i++];
        }
        answer++;
    }
    return answer;
}
