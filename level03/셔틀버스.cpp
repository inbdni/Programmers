#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int to_min(string s)
{
    int t;
    
    t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    return t;
}

string to_str(int t)
{
    string s = "";
    
    if (t / 60 < 10)
    {
        s += "0";
    }
    s += to_string(t / 60) + ":";
    if (t % 60 < 10)
    {
        s += "0";
    }
    s += to_string(t % 60);
    return s;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer;
    vector<vector<int>> bus(n + 1);
    int limit, num, cnt, crew;
    int i;

    sort(timetable.begin(), timetable.end());
    limit = to_min("09:00");
    num = 1;
    cnt = 0;
    for (i = 0; i < timetable.size(); i++)
    {
        crew = to_min(timetable[i]);
        while (limit < crew || cnt == m)
        {
            num++;
            limit += t;
            cnt = 0;
        }
        if (num > n)
            break;
        bus[num].push_back(crew);
        cnt++;
    }
    if (bus[n].size() == m)
        answer = to_str(bus[n].back() - 1);
    else
        answer = to_str(to_min("09:00") + (n - 1) * t);
    return answer;
}
