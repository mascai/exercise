#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> compute_prefix_function(const string& s)
{
	int len = s.length();
	vector<int> p(len); // значения префикс-функции
	                    // индекс вектора соответствует номеру последнего символа аргумента
	p[0] = 0; // для префикса из нуля и одного символа функция равна нулю

    int k = 0;
	for (int i = 1; i < len; ++i) {
		while ((k > 0) && (s[k] != s[i]))
			k = p[k - 1];
		if (s[k] == s[i])
			++k;
		p[i] = k;
	}
	return p;
}

int main() {
    string s1="alekmos";
    string s2="ekm";
    string s = s2+'#'+s1;
    auto ans = compute_prefix_function(s);
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == s2.size()) {
            cout << i - 2*s2.size() + 1;
        }
    }
}
