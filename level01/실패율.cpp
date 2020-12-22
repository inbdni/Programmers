#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> fail;
    int i, temp_user, total_user;
    
    for (i = 0; i < N; i++)
    {
        fail.push_back(make_pair(i + 1, 0));
    }
    for (i = 0; i < stages.size(); i++)
    {
        if (stages[i] > N)
        {
            continue;
        }
        fail[stages[i] - 1].second++;
    }
    total_user = stages.size();
    for (i = 0; i < fail.size(); i++)
    {
        temp_user = fail[i].second;
        if (total_user)
        {
            fail[i].second /= (double)total_user;
        } 
        else
        {
            fail[i].second = 0.0;
        }
        total_user -= temp_user;
    }
    sort(fail.begin(), fail.end(), compare);
    for (i = 0; i < fail.size(); i++)
    {
        answer.push_back(fail[i].first);
    }
    return answer;
}
