/*
https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/

*/

int solution(int N) {
    int res = 0;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            if (N / i == i) {
                res += 1;
            } else {
                res += 2;
            }
        }
    }
    return res;
}
