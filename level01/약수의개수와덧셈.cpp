#include <string>
#include <vector>

using namespace std;

int get_num(int num) {
    int i, cnt = 0;
    
    for (i = 1; i * i < num; i++) {
        if (num % i == 0)
            cnt += 2;
    }
    if (i * i == num)
        cnt++;
    return cnt;
}

int solution(int left, int right) {
    int answer = 0;
    int i;
    
    for (i = left; i <= right; i++) {
        if (get_num(i) % 2)
            answer -= i;
        else
            answer += i;
    }
    return answer;
}
