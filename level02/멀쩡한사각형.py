def gcd(a, b):
    if a < b:
        r = a;
        a = b;
        b = r;
    while b:
        r = a % b;
        a = b;
        b = r;
    return a;

def solution(w,h):
    answer = (w * h) - (w + h - gcd(w, h));
    return answer
