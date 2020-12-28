#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int i;
    int j;
    int toleft;
    int toright;

    i = 0;
    while (1)
    {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        name[i] = 'A';

        j = i;
        toleft = 0;
        while (name[j] == 'A')
        {
            j--;
            if (j < 0)
                j += name.size();
            toleft++;
            if (toleft >= name.size())
                break;
        }

        if (toleft >= name.size())
            break;

        j = i;
        toright = 0;
        while (name[j] == 'A')
        {
            j++;
            if (j >= name.size())
                j -= name.size();
            toright++;
            if (toright >= name.size())
                break;
        }

        answer += min(toleft, toright);
        if (toleft < toright)
        {
            i -= toleft;
            if (i < 0)
                i += name.size();
        }
        else
        {
            i += toright;
            if (i >= name.size())
                i -= name.size();
        }
    }
    return answer;
}
