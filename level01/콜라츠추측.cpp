#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long temp = num;
    
    while (temp != 1)
    {
        if (temp % 2 == 0)
        {
            temp = temp / 2;
        } 
        else
        {
            temp = temp * 3 + 1;
        }     
        answer++;
        if (answer == 500)
        {
            return -1;
        }       
    }
    return answer;
}
