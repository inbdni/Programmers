#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int last = -1;
    int i;
    
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] != last) 
        {
            last = arr[i];
            answer.push_back(last);
        }
    }
    return answer;
}
