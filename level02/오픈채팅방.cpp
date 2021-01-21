#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> parse(string str)
{
    int i, j = 0;
    vector<string> v;
    
    for (i = 0; i < 3; i++)
    {
        v.push_back("");
        while (str[j] != ' ' && j < str.size())
            v[i] += str[j++];
        j++;
    }
    return v;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    int i;
    string tmp;
    vector<vector<string>> str;
    unordered_map<string, string> um;
    
    for (i = 0; i < record.size(); i++)
    {
        str.push_back(parse(record[i]));
        if (str[i][0][0] == 'L')
            continue;
        if (um[str[i][1]].compare(str[i][2]) == 0)
            continue;
        um[str[i][1]].clear();
        um[str[i][1]] += str[i][2];
    }
    for (i = 0; i < str.size(); i++)
    {
        tmp += um[str[i][1]];
        switch(str[i][0][0])
        {
            case 'E':
                tmp += "님이 들어왔습니다.";
                break;
            case 'L':
                tmp += "님이 나갔습니다.";
                break;
            default:
                tmp.clear();
                continue;
        }
        answer.push_back(tmp);
        tmp.clear();
    }
    return answer;
}
