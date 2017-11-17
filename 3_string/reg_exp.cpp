/*
Известно, что при работе с файлами можно указывать метасимволы * и ? для отбора нужной
группы файлов, причём знак * соответствует любому множеству, даже пустому, в имени файла, а
символ ? соответствует ровно одному символу в имени.
Первая строка программы содержит имя файла, состоящее только из заглавных букв латинского
алфавита (A-Z), а вторая — образец, содержащий только заглавные буквы латинского алфавита и,
возможно, символы * и ?. Строки не превышают по длине 700 символов. Требуется вывести слова
YES или NO в зависимости от того, сопоставляется ли имя файла указанному образцу.
Формат входных данных
SOMETEXT
PATTERN
Формат выходных данных
YES
или
NO

ABRACADABRA
ABRA*ABRA   ---> YES

FOOBAR
F*??O* ---> NO
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    string text, mask;
    cin >> text;
    cin >> mask;
    string new_mask;
    for (int i = 0; i < mask.size(); i++) {
        if (mask[i] == '*') {
            new_mask.push_back('(');
            new_mask.push_back('.');
            new_mask.push_back('*');
            new_mask.push_back(')');
        } else if (mask[i] == '?') {
            new_mask.push_back('[');
            new_mask.push_back('A');
            new_mask.push_back('-');
            new_mask.push_back('Z');
            new_mask.push_back(']');
        } else {
            new_mask.push_back(mask[i]);
        }
    }
    if (regex_match (text, std::regex(new_mask))) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    //bool b = f(text, mask, 0, 0);
    return 0;
}
