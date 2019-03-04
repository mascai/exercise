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
int atoi(string str)
{
    int sz = str.size();
    if (str.size()  < 1) {
        return 0;
    }
    int sign = 1; // -1 == '-', 1 == '+'
    if (str[0] == '-') {
        sign = -1;
    }
    int start = 0;
    while (start < sz && str[start] == '0') {
        start++;
    }
    if (start == sz) {
        return 0;
    }
    int ans = 0;
    if (str[0] == '-' || str[0] == '+') {
        start++;
    }
    for (int i = start; i< sz; i++) {
        if (!isdigit(str[i])) {
            return -1;
        }
        ans = ans * 10 + str[i] - '0';
    }
    return ans * sign;
}
