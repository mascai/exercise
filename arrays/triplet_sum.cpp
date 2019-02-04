/*

Triplets with Sum between given range

Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed
*/
void checkNumber(vector<double>& A, double num) {
    if (A[0] + A[1] + A[2] > 2 && num < A[0]) {
        A[0] = num;
        sort(begin(A), end(A), greater<double>());
    } else if (A[0] + A[1] + A[2] < 1 && num > A[2]) {
        A[2] = num;
        sort(begin(A), end(A), greater<double>());
    }
}


int Solution::solve(vector<string> &A) {
    int n = A.size();
    
    vector<double>input;
    for (int i = 0; i < n; ++i) {
        input.push_back(atof(A[i].data()));
    }
    vector<double>vec{input[0], input[1], input[2]};
    sort(begin(vec), end(vec), greater<double>());
    for (int i = 3; i < input.size(); ++i) {
        checkNumber(vec, input[i]);
    }
    double sum = vec[0] + vec[1] + vec[2];
    if (sum > 1 && sum < 2) {
        return 1;
    } else {
        return 0;
    }
}
