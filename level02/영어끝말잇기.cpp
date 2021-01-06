#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int i;
    int j;
    int is_fail = 0;
    
    answer.push_back(0);
    answer.push_back(0);
    for (i = 0; i < words.size(); i++)
    {
        if (i > 0 && (words[i - 1].back() != words[i].front()))
        {
            is_fail = 1;
            break;
        }
        if (words[i].size() == 1)
        {
            is_fail = 1;
            break;
        }
        for (j = 0; j < i; j++)
        {
            if (words[j].compare(words[i]) == 0)
            {
                is_fail = 1;
                break;
            }
        }
        if (is_fail)
        {
            break;
        }
    }
    if (is_fail)
    {
        answer[0] = (i + 1) % n;
        if (answer[0] == 0)
        {
            answer[0] = n;
        }
        answer[1] = (i / n) + 1;
    }

    return answer;
}
