string s2 ="find",s1 = "find in me find";
vector<int> prefix_function (string s) {
    int n = (int) s.length();

    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];

        while ((j > 0) && (s[i] != s[j] || j==s2.size() || i==s2.size()))
            j = pi[j-1];
        if (s[i] == s[j] && i!=s2.size() && j!=s2.size())  ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){
    s1=s2+'#'+s1;
    vector<int> p= prefix_function(s1);


    forn(i,p.size()){
        if(p[i]==s2.size()){
            cout << i-2*s2.size()+1 << " ";
        }
    }
    return 0;
}
