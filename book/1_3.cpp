/*
Напишите метод, заменяющий все пробелы в строке символами ' %20 ' . Можете
считать, что длина строки позволяет сохранить дополнительные символы,
а фактическая длина строки известна заранее.
*/

string Alg1_3(string str){

    int space = 0, n = str.size();
    vector<int>v;
    for (int i = 0; i < n; i++){
        if (str[i] == ' '){
            ++space;
        }
    }
    str.resize(n + space * 2); //new string size
    for (int i = n - 1, j = n + space * 2; i >= 0; i--){
        if (str[i] == ' '){
            str[j - 1] = '0';
            str[j - 2] = '2';
            str[j - 3] = '%';
            j -= 3;
        } else {
            str[j-1] =  str[i];
            j--;
        }
    }
    return str;
}


int main()
{
    string s = "  ab c ";
    cout << Alg1_3(s);
    return 0;
}
