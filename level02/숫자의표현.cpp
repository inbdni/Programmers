#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 1;
    int acc = 0;
    
    while (acc < n)
    {
        if ((n - acc) % i == 0)
            answer++;
        acc += i;
        i++;
    }
    return answer;
}
