#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int r;
    
	while (b)
    {
		r = a % b;
		a = b;
		b = r;
	}
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    int i;
    
    for (i = 1; i < arr.size(); i++)
    {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}
