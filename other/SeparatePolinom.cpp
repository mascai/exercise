#include <bits/stdc++.h>

using namespace std;

void Print(map<int, int>res) {
    for(auto pos=res.begin();pos!=res.end();++pos) {
        cout << pos->second << "*x^" << pos->first << endl;
    }
    cout << "------------" << endl;
}

map<int,int> SeparatePolinom(string input) {
  stringstream stream;
    stream << input;
    map<int,int>res;
    while(stream.peek()!= EOF) {
        bool is_signed=false;
        int mul=1,exp=0;
        if(stream.peek()=='-' || stream.peek()=='+')
            is_signed=stream.get()=='-';
        if(isdigit(stream.peek()))
            stream>>mul;
        if(is_signed)
            mul=-mul;

        if(stream.peek()=='*')
        {
            stream.get();
            assert(stream.peek()=='x');
            stream.get();
            if(stream.peek()=='^')
            {
                stream.get();
                stream>>exp;
            }else
                exp=1;
        } else {
            if (stream.peek()=='x') {
                stream.get();
            }
            if(stream.peek()=='^')
            {
                stream.get();
                stream>>exp;
            }else
                exp=0;
        }
        res[exp]=mul;
    }
    return res;
}


int main(){
    string input = "6-2*x^100+100*x^2";
    //cin >> input;
    map<int,int>res = SeparatePolinom(input);
    Print(res);


}
