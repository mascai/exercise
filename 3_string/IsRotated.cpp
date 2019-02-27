/*

Given two strings, the task is to find if a string ('a') can be obtained by rotating another string ('b') by two places.
Examples:
Input : a = "amazon"
           b = "azonam" // rotated anti-clockwise
Output : 1
Input : a = "amazon"
           b = "onamaz" // rotated clockwise
Output : 1

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1<=T<=50
1<=length of a, b <100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0

*/


// C++ program to check if a string is two time
// rotation of another string.
#include<bits/stdc++.h>
using namespace std;

// Function to check if string2 is obtained by
// string 1
bool isRotated(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    int len = str2.length();
    for (int i = 1; i < len; ++ i) {
        string clock_rot = "";
        string anticlock_rot = "";


        // Initialize string as anti-clockwise rotation
        anticlock_rot = anticlock_rot +
                        str2.substr(len-i, i) +
                        str2.substr(0, len-i) ;

        // Initialize string as clock wise rotation
        clock_rot = clock_rot +
                    str2.substr(i) +
                    str2.substr(0, i) ;

        // check if any of them is equal to string1
        if (str1.compare(clock_rot) == 0 ||
                str1.compare(anticlock_rot) == 0) {

            return 1;
        }
    }
    return 0;
}

// Driver code
int main()
{
    string str1 = "amazon";
    string str2 = "zonama";

    isRotated(str1, str2) ? cout << "Yes"
                          : cout << "No";
    return 0;
}
