Для двух строк напишите метод, определяющий, является ли одна строка перестановкой другой.

bool Alg1_2(string s1, string s2){
    map<char, int> m1;
    if (s1.length() != s2.length()){
        return false;
    }
    for (auto i : s1){
        ++m1[i];
    }
    for (auto i : s2){
        if (--m1[i] < 0) {
            return false;
        }
    }
    return true;
}
