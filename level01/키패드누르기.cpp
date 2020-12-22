#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

char push(int* hand_x, int* hand_y, int num_x, int num_y, string flag) {
    if (flag.compare("left") == 0)
    {
        *hand_x = num_x; 
        *hand_y = num_y;
        return 'L';
    } 
    else
    {
        *hand_x = num_x;
        *hand_y = num_y;
        return 'R';
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_x, left_y, right_x, right_y, num_x, num_y;
    int i, left_dist, right_dist;
 
    left_x = 0; 
    left_y = 3;
    right_x = 2; 
    right_y = 3;
    
    for (i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
        {
            num_x = 1;
            num_y = 3;
        } 
        else
        {
            num_x = (numbers[i] - 1) % 3;
            num_y = (numbers[i] - 1) / 3;
        }
        if (num_x == 0)
        {   // 왼손: 1, 4, 7       
            answer += push(&left_x, &left_y, num_x, num_y, "left");
        } 
        else if (num_x == 2)
        {   // 오른손: 3, 6, 9
            answer += push(&right_x, &right_y, num_x, num_y, "right");
        } 
        else
        {   // 가까운 손: 2, 5, 8, 0
            left_dist = abs(left_x - num_x) + abs(left_y - num_y);
            right_dist = abs(right_x - num_x) + abs(right_y - num_y);
            if (left_dist > right_dist)
            {
                answer += push(&right_x, &right_y, num_x, num_y, "right");
            } 
            else if (left_dist < right_dist)
            {
                answer += push(&left_x, &left_y, num_x, num_y, "left");
            } 
            else
            {
                if (hand.compare("left") == 0) 
                    answer += push(&left_x, &left_y, num_x, num_y, "left");
                else
                    answer += push(&right_x, &right_y, num_x, num_y, "right");
            }
        }
    }
    return answer;
}
