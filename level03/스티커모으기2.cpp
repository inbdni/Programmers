#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int i;
    int size = sticker.size();
    int m[size];
    
    if (size == 1)
    {
        return sticker[0];
    }
    if (size == 2)
    {
        return max(sticker[0], sticker[1]);
    }
    m[0] = sticker[0];
    m[1] = sticker[0];
    for (i = 2; i < size - 1; i++)
    {
        m[i] = max(m[i - 2] + sticker[i], m[i - 1]);
        answer = max(answer, m[i]);
    }
    m[0] = 0;
    m[1] = sticker[1];
    for (i = 2; i < size; i++)
    {
        m[i] = max(m[i - 2] + sticker[i], m[i - 1]);
        answer = max(answer, m[i]);
    }
    return answer;
}
