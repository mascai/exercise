#include <iostream>

using namespace std;

int sign(int a) {
    return 1^((a >> 31) & 0x1); // ->1 if a >= 0 else ->0
}

int get_max(int a, int b) {
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(a - b);

    int use_a = sa ^ sb; // ->1  if (sign a = sign b)
    int use_c = use_a ^ 1;
    int k = use_a * sa + use_c * sc;
    int q = 1 ^ k;
    return a * k + b * q;
}

int main() {
    cout << get_max(INT_MAX - 2, -15);
}
