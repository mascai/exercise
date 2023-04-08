/*
Найди максимально возможный отрезок времени для встречи на завтра — с точностью до минут. А если общий митинг поставить нельзя, выведи "ALARM"

Формат ввода
На первой строке два целых числа - N (0 <= N <= 10̂5) и M (0 <= M <= 10̂5)- количество участников команды и общее количество встреч На следующей - твое расписание, в формате HH:MM-HH:MM На следующих M строках - описания встреч, в формате X HH:MM-HH:MM, где X - номер участника команды
Формат вывода
Описание возможной встречи в формате HH:MM-HH:MM или строка "ALARM"
Пример 1
Ввод	Вывод
1 1
12:00-20:00
1 12:00-12:30
12:30-20:00
Пример 2
Ввод	Вывод
1 1
12:00-20:00
1 12:00-20:00
ALARM


*/


#include <type_traits>
#include <new>
#include <iostream>
#include <iomanip>

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



struct Time {
    Time() = default;

    Time(int n) {
        h = n / 60;
        m = n % 60;
    }

    int h;
    int m;

    friend ostream& operator<<(ostream& os, const Time& t) {
        if (t.h < 10) {
            os << '0';
        }
        os << t.h << ':';
        
        if (t.m < 10) {
            os << '0';
        }
        os << t.m;
        return os;
    }
};


int time_to_int(const Time& t) {
    return t.h * 60 + t.m;
}


pair<int, int> input_time() {
    Time start, end;
    cin >> start.h;
    cin.ignore(1);
    cin >> start.m;

    cin.ignore(1);
    cin >> end.h;
    cin.ignore(1);
    cin >> end.m;
    return {time_to_int(start), time_to_int(end)};
}


int main() {
    int n, m;
    cin >> n >> m;
    
    auto possible_time = input_time();
    vector<int> minutes(1440, 0);
    for (int i = possible_time.first; i < possible_time.second; ++i) {
        minutes[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int cur_idx = 0;
        cin >> cur_idx;
        auto cur_time = input_time();
        for (int i = cur_time.first; i < cur_time.second; ++i) {
            minutes[i] = 0;
        }
    }
    
    int res_start = 0;
    int cur_start = 0;

    int cur_len = 0;
    int res_len = 0;
    bool is_alarm = true;
    for (int i = 0; i < 1440; ++i) {
        if (minutes[i] == 1) {
            is_alarm = false;
            ++cur_len;
            if (cur_len > res_len) {
                res_len = cur_len;
                res_start = cur_start;
            } 
        } else {
            cur_len = 0;
            cur_start = i + 1;
        }
    }
    if (is_alarm) {
        cout << "ALARM";
    } else {
        cout << Time(res_start) << '-';
        cout << Time(res_start + res_len);
    }
    
}
