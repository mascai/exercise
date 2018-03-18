/*

Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False



*/

// get length of the number
int len(int n) {
    int ans = 0;
    while (n > 0) {
        ++ans;
        n /= 10;
    }
    return ans;
}

// get id's element from end of n
int get_num(int n, int id) {
    int sz = len(n);
    for (int i = 0; i < id; i++) {
        n /= 10;
    }
    return n % 10;
}
int Solution::isPalindrome(int n) {
    if (n < 0) {
        return 0;
    }
    int sz = len(n);
    for (int i = 0; i <= sz / 2; i++) {
        if (get_num(n, i) != get_num(n, sz - i - 1)) {
            return 0;
        }
    }
    return 1;
}
