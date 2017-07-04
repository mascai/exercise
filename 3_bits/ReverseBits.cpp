/*

*/

//BIT SOOLUTION
void SwapBits(unsigned int& x, unsigned int i, unsigned int j) {
    unsigned int val_i = (x >> i) & 1,
                 val_j = (x >> j) & 1;
    if (val_i ^ val_j){
        x ^= 1 << j;
        x ^= 1 << i;
    }
}

unsigned int Solution::reverse(unsigned int A) {
    unsigned int n = sizeof(A) * 8;
    for (int i = 0; i < n / 2; i++){
        SwapBits(A, i, n - i - 1);
    }
    return A;
}


//SIMPLE SOLUTION
unsigned int Solution::reverse(unsigned int A) {
    if (!A){
        return 0;
    }
    vector<int>v;
    while (A > 0){
        v.push_back(A % 2);
        A /= 2;
    }
    while (v.size() != 32){
        v.push_back(0);
    }
    unsigned int ans = 0, cnt = 0;
    for (int i = v.size() - 1; i >= 0; i--){
        ans += v[i] * pow(2, cnt++);
    }
    return ans;
}

