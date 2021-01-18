#include <string>
#include <set>
#include <unordered_map>
#include <cctype>

using namespace std;

void parsing(multiset<string> &ms, string &str)
{
    int i;
    int j = 0;

    for (i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
    for (i = 1; i < str.size(); i++)
    {
        if (isalpha(str[i - 1]) && isalpha(str[i]))
            ms.insert(str.substr(i - 1, 2));
    }
}

int solution(string str1, string str2) {
    double answer = 65536;
    double a = 0;
    double b = 0;
    int cnt1, cnt2;
    multiset<string> ms1;
    multiset<string> ms2;
    multiset<string>::iterator iter;
    unordered_map<string, int> um;
    
    parsing(ms1, str1);
    parsing(ms2, str2);
    if (ms1.empty() && ms2.empty())
    {
        return answer;
    }
    for (iter = ms1.begin(); iter != ms1.end(); iter++)
    {
        if (um[*iter])
            continue;
        um[*iter]++;
        cnt1 = ms1.count(*iter);
        cnt2 = ms2.count(*iter);
        a += min(cnt1, cnt2);
        b += max(cnt1, cnt2);
    }
    for (iter = ms2.begin(); iter != ms2.end(); iter++)
    {
        if (um[*iter])
            continue;
        um[*iter]++;
        cnt1 = ms1.count(*iter);
        cnt2 = ms2.count(*iter);
        a += min(cnt1, cnt2);
        b += max(cnt1, cnt2);
    }
    answer *= a / b;
    
    return answer;
}
