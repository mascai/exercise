// Функция для поиска подстроки в строке
// + поиск позиции, с которой начинается подстрока

using namespace std;

int isSubstring(string src_str, string sub_str){
    int sz = sub_str.length();
    for(int i = 0; i <= src_str.length() - sz; i++){
        for (int j = 0; src_str[i+j] == sub_str[j]; j++){
            if (sz == j + 1) {
                return i;
            }
        }
    }
    return -1;
}

int main(){
    cout << isSubstring("abacac1b", "aca");
}
