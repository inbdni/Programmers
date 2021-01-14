#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string base = "0123456789ABCDEF";

string convert(int n, int num) {
    string result = "";
    
    if (num == 0)
    {
        result += '0';
        return result;
    }
    while (num)
    {
        result += base[num % n];
        num /= n;
    }
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int i;
    int num = 0;
    int seq = 0;
    string baseNum;
    
    while (answer.size() < t)
    {
        baseNum += convert(n, num);
        num++;
        for (i = 0; i < baseNum.size(); i++)
        {
            seq++;
            if (seq == p)
            {
                answer += baseNum[i];
                if (answer.size() == t)
                    break;
            } 
            if (seq == m)
                seq = 0;
        }
        baseNum.clear();
    }
    return answer;
}
