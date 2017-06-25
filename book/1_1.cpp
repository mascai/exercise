Реализуйте алгоритм, определяющий, все ли символы в строке встречаются
только один раз. А если при этом запрещено использование дополнительных
структур данных?


bool Alg1(string s){ // O(N^2)
    int n = s.size();
    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j < n; j++){
            if (s[i] == s[j]){
                return false;
            }
        }
    }
    return true;
}

bool Alg2(string s){ // O(N)
    unsigned int flag = 0; // bit flag
    for (auto i : s){ // chars in string
        if (flag & (1 << (i - 'a')) > 0){
            return false;
        }
        flag |= (1 << (i - 'a'));
    }
    return true;
}
int main()
{
    cout << Alg2("bacda");
    return 0;
}
