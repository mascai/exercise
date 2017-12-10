/*
ЧАСТОТА ВСТРЕЧАНИЯ ПАР СЛОВ

Для поиска закономерностей в текстах можно исследовать зависимости между вхождениями различных слов.

Вам задан предварительно обработанный литературный английский текст. Он состоит из слов, каждое из которых состоит из строчных латинских букв. Знаки препинания и форматирование были удалены.

Будем говорить, что слова u и v образуют устойчивую пару, если слово v встречается непосредственно после слова u больше одного раза, причем число вхождений v непосредственно после u строго больше числа вхождений непосредственно после u любого другого слова w. Требуется найти все устойчивые пары в тексте.
Формат ввода

На вход подается текст, составленный из слов. Словом называется последовательность строчных латинских букв. Слова разделяются пробелами и/или переводами строк. Входные данные не содержат других символов, кроме строчных латинских букв, пробелов и переводов строк.

Гарантируется, что ввод представляет собой литературный текст на английском языке, из которого удалены знаки препинания и форматирование, а все заглавные буквы заменены на строчные. Размер текста не превышает 1 мегабайта.
Формат вывода

Первая строка выходных данных должна содержать целое число — количество устойчивых пар. Далее выведите устойчивые пары, по одной на строке. Разделяйте слова в устойчивой паре одним пробелом. Пары должны быть отсортированы по алфавиту по первому слову.
Пример
Ввод 	Вывод

this is the house that jack built
this is the malt that lay in the house that jack built
this is the rat that ate the malt
that lay in the house that jack built
this is the cat that killed the rat
that ate the malt that lay in the house that jack built
this is the dog that worried the cat
that killed the rat that ate the malt
that lay in the house that jack built

	

14
ate the
built this
cat that
house that
in the
is the
jack built
killed the
lay in
malt that
rat that
that jack
the house
this is

*/

#include <bits/stdc++.h>

using namespace std;

bool cmp ( pair<string, string> &a,  pair<string, string>  &b) {
    string as = a.first;
    string bs = b.first;
    if (as.compare(bs) > 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    map<string, map<string, int>>cnt; // <u, <v, number of v after u>>
    string line;
    vector<pair<string, string>>ans;
    string last_word="!";
    while (getline(cin, line, '\n')) {
        stringstream ss;
        ss << line;
        string word;
        vector<string>v;
        while (ss >> word) {
            v.push_back(word);
        }
        for (int i = 0; i < v.size() - 1; i++) {
            if (i == 0 &&  last_word != "!") {
                cnt[last_word][v[0]]++;
            }
            cnt[v[i]][v[i + 1]]++;
        }
        last_word = v.back();
    }
    for (auto u_map : cnt) {
        int max_word = 0;
        string max_str;
        //for (auto v_map : u_map.second) {
            for (auto item : u_map.second) {
                if (item.second > max_word) {
                    max_word = item.second;
                    max_str = item.first;
                }
            }
            if (max_word > 1) {
                ans.push_back(make_pair(u_map.first, max_str));
            }

    }
    sort(begin(ans), end(ans), cmp);
    cout << ans.size() << endl;
    for (auto item : ans) {
        cout << item.first << ' ' << item.second << endl;
    }
    return 0;
}
