#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int cmp1(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

int cmp2(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> song;
    unordered_map<string, int> time;
    vector<pair<string, int>> tmp;
    int i, j, limit;
    string g;
    
    for (i = 0; i < genres.size(); i++)
    {
        song[genres[i]].push_back(make_pair(i, plays[i]));
        time[genres[i]] += plays[i];
    }
    for (auto t : time)
    {
        tmp.push_back(make_pair(t.first, t.second));
    }
    sort(tmp.begin(), tmp.end(), cmp1);
    for (i = 0; i < tmp.size(); i++)
    {
        g = tmp[i].first;
        limit = min(song[g].size(), (unsigned long) 2);
        sort(song[g].begin(), song[g].end(), cmp2);
        for (j = 0; j < limit; j++)
        {
            answer.push_back(song[g][j].first);
        }
    }
    return answer;
}
