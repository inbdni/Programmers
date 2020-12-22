#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> array(3);
    int i, max;
    int first[] = {1, 2, 3, 4, 5};
    int second[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int firstSize = sizeof(first) / sizeof(int);
    int secondSize = sizeof(second) / sizeof(int);
    int thirdSize = sizeof(third) / sizeof(int);
    
    for (i = 0; i < answers.size(); i++)
    {
        if (answers[i] == first[i % firstSize])
        {
            array[0]++;
        }  
        if (answers[i] == second[i % secondSize])
        {
            array[1]++;
        }
        if (answers[i] == third[i % thirdSize])
        {
            array[2]++;
        } 
    }
    max = *max_element(array.begin(), array.end());
    for (i = 0; i < 3; i++)
    {
        if (array[i] == max)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}
