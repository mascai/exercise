/*
Реализуйте метод для выполнения простейшего сжатия строк с использованием
счетчика повторяющихся символов. Например, строка ааЬсссссааа превращается
в а2b1с5а3. Если •сжатая строка не становится короче исходной, то метод возвращает исходную строку. Предполагается, что строка состоит
только из букв верхнего и нижнего регистра (a-z).
*/


string Alg1_6(const string s){
    char prev = s[0];
    string res;
    if (s.size() == 0){
        return "";
    }
    int cnt = 1;
    for (unsigned i = 1; i < s.size(); i++){
        char cur = s[i];
        if (prev == cur){
            cnt++;
        } else {
           res.push_back(prev);
           res.push_back(cnt + '0');
           cnt = 1;
        }
        if (i == s.size() - 1){
            res.push_back(cur);
            res.push_back(cnt + '0');
        }
        prev = cur;
    }

    return res.size() < s.size() ? res : s;
}


int main()
{
    string s = "aaabbbbbca";
    cout << Alg1_6(s) << endl;
    return 0;
}
