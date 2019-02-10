/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

*/

class Solution {
public:
    bool isSign(const char& ch) {
        return (ch == '-' || ch == '+');
    }
    int myAtoi(string str) {
        int size = str.size();
        int start = 0;
        while (start < size && str[start] == ' ') {
            start++;
        };
        if (start == size && !isdigit(str[start - 1])
            || !isdigit(str[start]) && !isSign(str[start])) {
            return 0;
        }
        char sign;
        if (isSign(str[start])) {
            sign = str[start];
            ++start;
        }
        long long ans = 0;
        for (int i = start; i < size && isdigit(str[i]); ++i) {
            int curr = (str[i] - '0');
            if (ans > INT_MAX/10 || 
              (ans == INT_MAX / 10 && curr > 7)) {
               if (sign == '-') {
                   return INT_MIN;
               } else {
                   return INT_MAX;
               }
           }
            ans = ans * 10 + curr;  
        }
        if (sign == '-') {
            ans *= -1;
        }
        return ans;
    }
            
    
    
};