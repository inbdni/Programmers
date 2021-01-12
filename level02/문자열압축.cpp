#include <string>
#include <vector>
#include <queue>

using namespace std;

int compression(string s, int unit)
{
    queue<string> q;
    string tmp = "";
    int i = 0;
    int len = 0;
    int cnt;
    
    while (i < s.size())
    {
        q.push(s.substr(i, unit));
        i += unit;
    }
    while (!q.empty())
    {
        if (q.size() == 1)
        {
            len += q.front().size();
            break;
        }
        cnt = 1;
        tmp += q.front();
        q.pop();
        while (!q.empty() && tmp.compare(q.front()) == 0)
        {
            q.pop();
            cnt++;
        }
        tmp.clear();
        if (cnt > 1)
            len += unit + to_string(cnt).size();
        else
            len += unit;
    }
    return len;
}

int solution(string s) {
    int answer = s.size();
    int unit = 1;

    for (unit = 1; unit < s.size(); unit++)
        answer = min(answer, compression(s, unit));
    return answer;
}
