#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int i;
    int a;
    int b;
    int c;

    do 
    {
        i = 0;
        while (i < data.size())
        {
            a = distance(friends.begin(), find(friends.begin(), friends.end(), data[i][0]));
            b = distance(friends.begin(), find(friends.begin(), friends.end(), data[i][2]));
            c = data[i][4] - '0';
            if (data[i][3] == '=' && (abs(a - b) - 1 != c))
                break;
            if (data[i][3] == '>' && (abs(a - b) - 1 <= c))
                break;
            if (data[i][3] == '<' && (abs(a - b) - 1 >= c))
                break;
            i++;
        }
        if (i == data.size())
            answer++;
    } while (next_permutation(friends.begin(), friends.end()));
    
    return answer;
}
