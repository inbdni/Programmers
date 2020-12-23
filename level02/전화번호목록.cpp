#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int i;
    size_t len;
    
    sort(phone_book.begin(), phone_book.end());
    i = 0;
    while (i < phone_book.size() - 1)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            answer = false;
            break;
        }
        i++;
    }
    return answer;
}
