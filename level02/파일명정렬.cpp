#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

void parsing(string &a, string &head, string &num)
{
    int i = 0;
    
    while (!isdigit(a[i]) && i < a.size())
    {
        head += a[i++];
    }
    while (isdigit(a[i]) && i < a.size())
    {
        num += a[i++];
    }
    transform(head.begin(), head.end(), head.begin(), ::toupper);
}

int comp(string &a, string &b)
{
    string a_head = "";
    string a_num = "";
    string b_head = "";
    string b_num = "";
    
    parsing(a, a_head, a_num);
    parsing(b, b_head, b_num);
    if (a_head.compare(b_head) != 0)
    {
        return a_head < b_head;
    }
    if (stoi(a_num) != stoi(b_num))
    {
        return stoi(a_num) < stoi(b_num);
    }
    return find(answer.begin(), answer.end(), a) < find(answer.begin(), answer.end(), b);
}

vector<string> solution(vector<string> files) {
    int i;
    
    for (i = 0; i < files.size(); i++)
    {
        answer.push_back(files[i]);
    }
    sort(files.begin(), files.end(), comp);
    return files;
}
