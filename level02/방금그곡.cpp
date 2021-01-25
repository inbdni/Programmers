#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string del_hash(string &s)
{
    int i;
    string res = "";
    
    for (i = 0; i < s.size(); i++)
    {
        if (s[i + 1] == '#')
            res += tolower(s[i++]);
        else
            res += s[i];
    }
    return res;
}

int get_time(string &s)
{
    int h, m;
    int sh = stoi(s.substr(0, 2));
    int sm = stoi(s.substr(3, 2));
    int eh = stoi(s.substr(6, 2));
    int em = stoi(s.substr(9, 2));
    
    if (sm > em)
    {
        em += 60;
        eh -= 1;
    }
    h = eh - sh;
    m = em - sm;
    
    return (h * 60 + m);
}

string get_title(string &s)
{
    int i = 12;
    int size = 0;
    
    while (i < s.size() && s[i] != ',')
        i++;
    
    return s.substr(12, i - 12);
}

string get_melody(string &s)
{
    int i = 12;
    
    while (i < s.size() && s[i] != ',')
        i++;
    i++;
    
    return s.substr(i);
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    string melody;
    int i, res;
    int time, max_time = 0;
    
    m = del_hash(m);
    for (i = 0; i < musicinfos.size(); i++)
    {
        time = get_time(musicinfos[i]);
        if (time <= max_time)
        {
            continue;
        }
        melody.clear();
        melody += get_melody(musicinfos[i]);
        melody = del_hash(melody);
        while (melody.size() < time)
        {
            melody += melody;
        }
        melody = melody.substr(0, time);
        res = melody.find(m);
        if (res == string::npos)
        {
            continue;
        }
        max_time = time;
        answer.clear();
        answer += get_title(musicinfos[i]);
    }
    return answer;
}
