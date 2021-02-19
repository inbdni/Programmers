#include <string>
#include <vector>
#include <cstring>

using namespace std;

int get_sec(string time)
{
    int hh, mm, ss, res;
    
    hh = stoi(time.substr(0, 2));
    mm = stoi(time.substr(3, 2));
    ss = stoi(time.substr(6, 2));
    res = hh * 3600 + mm * 60 + ss;
    return res;
}

string get_time(int sec)
{
    string tmp, res = "";
    string colon[] = {"", ":", ":"};
    int num[] = {3600, 60, 1};
    int i;
    
    for (i = 0; i < 3; i++)
    {
        tmp = to_string(sec / num[i]);
        sec %= num[i];
        if (tmp.size() == 1)
            tmp = "0" + tmp;
        res += colon[i] + tmp;
    }
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "00:00:00";
    int i, j;
    int play, adv;
    int on, off;
    long long view[360000];
    long long sum_view, max_view;
    
    play = get_sec(play_time);
    adv = get_sec(adv_time);
    if (play == adv)
    {
        return answer;
    }
    memset(view, 0, sizeof(view));
    for (i = 0; i < logs.size(); i++)
    {
        on = get_sec(logs[i].substr(0, 8));
        off = get_sec(logs[i].substr(9, 8));
        for (j = on; j < off; j++)
        {
            view[j]++;
        }
    }
    for (i = 1; i < play; i++)
    {
        view[i] += view[i - 1];
    }
    max_view = view[adv];
    for (i = 1; i + adv < play; i++)
    {
        sum_view = view[i + adv] - view[i];
        if (sum_view > max_view)
        {
            max_view = sum_view;
            answer = get_time(i + 1);
        }    
    }
    return answer;
}
