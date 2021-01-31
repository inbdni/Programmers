#include <string>
#include <vector>

using namespace std;

pair<int, int> get_time(string s)
{
    int start, end = 0;
    int process;
    
    end += stoi(s.substr(11, 2)) * 3600 * 1000 ;
    end += stoi(s.substr(14, 2)) * 60 * 1000;
    end += stoi(s.substr(17, 2)) * 1000;
    end += stoi(s.substr(20, 3));
    process = stof(s.substr(24, 5)) * 1000;
    start = end - process + 1;
    return make_pair(start, end);
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> time;
    int i, j, cnt, limit;
    
    for (i = 0; i < lines.size(); i++)
    {
        time.push_back(get_time(lines[i]));
    }
    for (i = 0; i < lines.size(); i++)
    {
        cnt = 0;
        limit = time[i].second + 1000;
        for (j = i; j < lines.size(); j++)
        {
            if (time[j].first < limit)
                cnt++;
        }
        answer = max(answer, cnt);
    }
    return answer;
}
