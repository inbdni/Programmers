#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    string w, c;
    int idx = 1;
    int start = 0, len;
    
    for (c = "A"; c <= "Z"; c[0]++)
    {
        dict[c] = idx++;
    }
    while (start < msg.size())
    {
        for (len = msg.size() - start; len > 0; len--)
        {
            w = msg.substr(start, len);
            if (dict[w] > 0)
            {
                answer.push_back(dict[w]);
                break;
            }
        }
        if (start + len < msg.size())
        {
            c = msg.substr(start, len + 1);
            dict[c] = idx++;
        }
        start += len;
    }
    return answer;
}
