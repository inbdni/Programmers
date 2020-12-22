#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a;
    int b;
    int r;
    
    a = n;
    b = m;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;        
    }
    answer.push_back(a);
    answer.push_back(n * m / a);
    return answer;
}
