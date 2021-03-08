#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int idx_a = 0;
    int idx_b = 0;
    int size = A.size();
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    while (idx_a < size && idx_b < size)
    {
        if (A[idx_a] < B[idx_b])
        {
            answer++;
            idx_a++;
            idx_b++;
        }
        else
        {
            idx_a++;
        }
    }
    return answer;
}
