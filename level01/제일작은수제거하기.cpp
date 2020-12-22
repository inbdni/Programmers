#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min, i;
    
    min = *min_element(arr.begin(), arr.end());
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] != min)
        {
            answer.push_back(arr[i]);
        }
    }
    if (answer.size() == 0) 
    {
        answer.push_back(-1);
    }   
    return answer;
}
