/*
Input : "XIV"
Return : 14
*/
int CharToInt(char c){
    switch(c){
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L':   return 50;
        case 'C':   return 100;
        case 'D':   return 500;
        case 'M':   return 1000;
        default:    return 0;
    }
}

int Solution::romanToInt(string A) {
    int n = A.size();
    int num = 0;
    for (int i = 0; i < n; i++){
        if (i + 1 < n && CharToInt(A[i]) < CharToInt(A[i + 1])){
            num -= CharToInt(A[i]);
        } else {
            num += CharToInt(A[i]);
        }
    }
    return num;
}
