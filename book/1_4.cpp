/*
Напишите функцию, которая проверяет, является ли заданная строка перестановкой
палиндрома. ( Палиндром - слово или фраза, одинаково читающиеся
в прямом и обратном направлении; перестановка - строка, содержащая те
же символы в другом порядке.) Палиндром не ограничивается словами из
словаря.
Пример:
Ввод: Tact Соа
Вывод: True ( перестановк и : "taco cat " , " atco cta " , и т . д . )
*/


bool Alg1_4(string str){
    map<char, int>cnt;
    int diff = 'A' - 'a';
    for (auto ch : str){
        if (ch == ' '){
            continue;
        }
        if (ch >= 'A' && ch <= 'Z'){
            ch = ch - diff;
        }
        cnt[ch]++;
    }
    int f = 0;

    for (auto i : cnt){
        f += i.second % 2;
        //cout << i.first << ' ' << i.second << endl;
    }
    if (f > 1){
        return false;
    }
    return true;
}


int main()
{
    string s = "Tact Coa";
    cout << Alg1_3(s);
    return 0;
}
