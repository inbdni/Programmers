#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int i;
    int j;
    int total = prices.size();
    
    for (i = 0; i < total; i++)
    {
        j = i + 1;
        while (j < total)
        {
            if (prices[i] > prices[j++])
                break;
        }
        answer.push_back(j - i - 1);    
    }
    return answer;
}
