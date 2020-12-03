#include <bits/stdc++.h>

using namespace std;

#define ll long long


string findWord(vector<string> v) {
    string res;
    unordered_map<char, char> cnt; // P>E, key= P, val = E
    unordered_set<char> starts;
    unordered_set<char> ends;
    for (auto cur : v) {
        char start = cur[0];
        char end = cur[2];
        cnt[start] = end;

        starts.insert(start);
        ends.insert(end);
    }
    char start = '@';
    char end = '#';
    for (auto cur : starts) {
        if (ends.find(cur) == ends.end()) {
            start = cur;
        }
    }
    for (auto cur : ends) {
        if (starts.find(cur) == starts.end()) {
            end = cur;
        }
    }

    if (start == '@') { // can't find start
        return res;
    }

    res += start;
    while (end != cnt[start]) {
        res += cnt[start];
        start = cnt[start];
    }
    res += end;
    return res;
}

int main() {
      
    cout << (findWord({"P>E","E>R","R>U"}) == "PERU") << endl; 
    cout << (findWord({"U>N", "G>A", "R>Y", "H>U", "N>G", "A>R"}) == "HUNGARY") << endl;
    cout << (findWord({"I>F", "W>I", "S>W", "F>T"}) == "SWIFT") << endl;
    cout << (findWord({"R>T", "A>L", "P>O", "O>R", "G>A", "T>U", "U>G"}) == "PORTUGAL") << endl;
    cout << (findWord({"W>I", "R>L", "T>Z", "Z>E", "S>W", "E>R", "L>A", "A>N", "N>D", "I>T"}) == "SWITZERLAND") << endl;
}   
    
