#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    int i, j;
    
    cin >> a >> b;
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
