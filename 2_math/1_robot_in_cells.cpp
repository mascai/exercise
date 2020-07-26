/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)


*/

// Solution 1

int Solution::uniquePaths(int A, int B) {
    long long res = 1;
    for (int i = B; i <= A + B - 2; ++i) {
        res *= i;
        res /= (i - B + 1);
    }
    return res;
}

// solution 2
int foo(int curX, int curY, int A, int B) {
    if (curX == A and curY == B) {
        return 1;
    }
    if (curX > A or curY > B) {
        return 0;
    }
    if (curX +  1 > A) {
        return foo(curX, curY + 1, A, B);
    }
    if (curY + 1 > B) {
        return foo(curX + 1, curY, A, B);
    }
    return foo(curX + 1, curY, A, B) + foo(curX, curY + 1, A, B);
}

int Solution::uniquePaths(int A, int B) {
    return foo(0, 0, A-1, B-1);
    
}
