#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int i;
    int j;
    int line;
    int item;
    vector<int> basket;

    for (i = 0; i < moves.size(); i++)
    {
        line = moves[i] - 1;
        for (j = 0; j < board.size(); j++)
        {
            item = board[j][line];
            if (item == 0)
            {
                continue;
            }
            else
            {
                board[j][line] = 0;
                break;
            }
        }
        if (item == 0)
        {
            continue;
        }
        if (basket.empty())
        {
            basket.push_back(item);
        }
        else
        {
            if (basket.back() == item)
            {
                answer += 2;
                basket.pop_back();
            } 
            else
            {
                basket.push_back(item);
            }
        }
    }
    return answer;
}
