#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width;
    int height = 3;
    int square = brown + yellow;
    
    while (1)
    {
        width = height;
        while (width * height <= square)
        {
            if (width * height == square)
            {
                if ((width - 2) * (height - 2) == yellow)
                {
                    answer.push_back(width);
                    answer.push_back(height);
                    return answer;
                }     
            }
            width++;
        }
        height++;
    }
}
