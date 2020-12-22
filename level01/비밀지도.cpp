#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int i, j;
    unsigned int temp, mask;
    string str;
    
    for (i = 0; i < n; i++)
    {
        temp = arr1[i] | arr2[i];
        mask = 1 << (n - 1);
        str.clear();
        for (j = 0; j < n; j++)
        {
            if ((temp & mask) > 0)
                str += '#';
            else
                str += ' ';
            mask = mask >> 1;
        }
        answer.push_back(str);
    }
    return answer;
}
