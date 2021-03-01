#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool bsearch(vector<int> &stones, int &k, int niniz)
{
    int i, zero = 0;
    
    for (i = 0; i < stones.size(); i++)
    {
        if (stones[i] - niniz <= 0)
        {
            zero++;
        }
        else
        {
            zero = 0;
        }
        if (zero >= k)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int s = 1;
    int e = *max_element(stones.begin(), stones.end());
    int mid;
    
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (bsearch(stones, k, mid))
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;
}
