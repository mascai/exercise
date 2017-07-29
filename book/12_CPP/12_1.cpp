#include <iostream>
#include<bits/stdc++.h>

using namespace std ;

void PrintLast5Lines(char *FileName){
    int NUM = 5;
    ifstream fin(FileName);
    vector<string> arr(NUM, "");
    int cnt = 0;
    while(fin.peek() != EOF){ // .peek() читает символ из потока, не передвигая каретку
        getline(fin, arr[cnt % NUM]);
        cnt++;
    }
    int start = cnt > NUM ? cnt % NUM : 0; // индекс, с которого начинаем выводить строки
    int size = min(NUM, cnt);
    for (int i = 0; i < size; i++){
        cout << arr[(start + i) % NUM] << endl;
    }
}

int main(){
    PrintLast5Lines("1.txt");
}
