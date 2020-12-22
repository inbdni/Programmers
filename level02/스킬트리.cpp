#include <string>
#include <vector>

using namespace std;

int is_possible(string skill, char c, int offset) {
    int i;
    
    i = offset + 1;
    while (skill[i]) {
        if (c == skill[i])
            return 0;
        i++;
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int i;
    int j;
    int k;
    
    i = 0;
    while (i < skill_trees.size()) {
        j = 0;
        k = 0;
        while (skill_trees[i][j]) {
            if (skill[k] == 0)
                break;
            if (is_possible(skill, skill_trees[i][j], k) == 0)
                break;
            if (skill_trees[i][j] == skill[k])
                k++;
            j++;
        }
        if (skill[k] == 0 || skill_trees[i][j] == 0)
            answer++;
        i++;
    }
    return answer;
}
