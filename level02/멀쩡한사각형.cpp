using namespace std;

int gcd(int a, int b) {
    int r;
    
    if (a < b)
    {   
        r = a;
        a = b;
        b = r;
    }
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer;

    answer = ((long)w * (long)h) - (w + h - gcd(w, h));
    return answer;
}
