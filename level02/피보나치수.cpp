#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 1;
    int i = 2;
    int a = 0;
    int b = 1;

    while (i <= n)
	{
        answer = (a + b) % 1234567;
        a = b;
        b = answer;
        i++;
    }
    return answer;
}
