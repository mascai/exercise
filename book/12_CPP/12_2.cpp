#include <iostream>
#include<bits/stdc++.h>

using namespace std ;

void Revers(char *str){
    int sz = 0;
    char *end = str;
    while(*end){
        end++;
    }
    --end;
    while (str < end){
        char temp = *str;
        *str++ = *end;
        *end-- = temp;

    }
}

int main(){
    char ch[5] = "Help";
    Revers(ch);
    cout << ch;
}
