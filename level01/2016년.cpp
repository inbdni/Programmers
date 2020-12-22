#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"}; 
    int i = 1;
    int j = 1;
    int dayNum = 0;
    
    while (i != a)
    {
        if (i == 2)
        {
            i++;
            dayNum += 29;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            i++;
            dayNum += 30;
        }
        else
        {
            i++;
            dayNum += 31;
        }
    }
    while (j != b)
    {
        j++;
        dayNum++;
    }
    answer += day[dayNum % 7];
    return answer;
}
