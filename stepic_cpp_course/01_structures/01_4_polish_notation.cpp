/*
Обратная польская запись
Вам дано выражение, записанное в обратной польской нотации. Найдите значение этого выражения

Входные данные
Вам подаётся строка, состоящая из цифр и знаков арифметических операций: -, +, *. Каждая цифра - отдельный операнд.

Выходные данные
Выведите значение выражения. Гарантируется, что оно по модулю не превосходит 1000.

Примеры
входные данные                                      выходные данные

12+                          3
входные данные                                      выходные данные

34*                          12
*/

#include <bits/stdc++.h>

using namespace std;


int main()
{
    string input;
    cin >> input;

    stack<int> st;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] >= '0' and input[i] <= '9') {
            st.push(input[i] - '0');
        } else {
            int rhs = st.top();
            st.pop();

            int lhs = st.top();
            st.pop();

            if (input[i] == '+') {
                st.push(lhs + rhs);
            } else if (input[i] == '-') {
                st.push(lhs - rhs);
            } else if (input[i] == '*') {
                st.push(lhs * rhs);
            } else {
                throw std::runtime_error("Unexpected character");
            }
        }
    }
    cout << st.top();
    return 0;
}
