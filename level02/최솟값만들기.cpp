#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int i = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    while (i < A.size())
	{
        answer += A[A.size() - i - 1] * B[i];
        i++;
    }
    return answer;
}
