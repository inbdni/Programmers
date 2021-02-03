#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int i, l_min, r_min;
    int size = a.size() - 1;
    vector<int> left;
    vector<int> right;
    
    l_min = a[0];
    left.push_back(l_min);
    r_min = a[size];
    right.push_back(r_min);
    for (i = 1; i < size; i++)
    {   
        l_min = min(l_min, a[i]);
        left.push_back(l_min);
        r_min = min(r_min, a[size - i]);
        right.push_back(r_min);
    }
    for (i = 0; i <= size; i++)
    {
        if (a[i] <= left[i] || a[i] <= right[size - i])
            answer++;
    }
    return answer;
}
