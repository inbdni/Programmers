#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    vector<string>::iterator iter;
    int i;
    
    if (cacheSize == 0)
    {
        answer = cities.size() * 5;
        return answer;
    }
    for (i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
    }
    for (i = 0; i < cities.size(); i++)
    {
        iter = find(cache.begin(), cache.end(), cities[i]);
        if (iter != cache.end())
        {
            answer += 1;
            cache.erase(iter);
        }
        else
        {
            answer += 5;
            if (cache.size() == cacheSize)
                cache.erase(cache.begin());
        }
        cache.push_back(cities[i]);
    }
    return answer;
}
