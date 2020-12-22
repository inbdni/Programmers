#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> parse;
    int i, index = -1;
    char temp;
    
    for (i = 0; i < dartResult.size(); i++)
    {
        temp = dartResult[i];
        if (temp == '*')
        {
            parse[index] *= 2;
            if (index > 0)
            {
                parse[index - 1] *= 2;
            }
        } 
        else if (temp == '#')
        {
            parse[index] *= -1;
        } 
        else if (temp <= '9')
        {
            if (temp == '0' && index > -1 && parse[index] == 1)
            {
                parse[index] *= 10;
            }
            else
            {
                parse.push_back(temp - '0');
                index++;
            }
        } 
        else if (temp == 'D')
        {
            parse[index] = pow(parse[index], 2);
        } 
        else if (temp == 'T')
        {
            parse[index] = pow(parse[index], 3);
        }
    }
    for (i = 0; i < parse.size(); i++)
    {
        answer += parse[i];
    }
    return answer;
}
