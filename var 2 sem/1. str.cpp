// 1. str.cpp 
// В строке, состоящей из групп нулей и единиц, подсчитать количество единиц в группах с нечетным количеством символов.
//

#include <iostream>
#include <string>
#include <stdlib.h>

int main() {
    using namespace std;
    string s;
    int count1 = 0, count2 = 0; // 1 - счетчик единиц  в группе, 2 - счетчик единиц по всем группам
    cout << "Enter the string: " << endl;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            count1++;
        }
        else if (s[i] == '0') {
            if (count1 % 2) {
                count2 += count1;
            }
            count1 = 0; 
        }
        else { //если элемент строки не является 0 или 1, выводим сообщение об ошибке ввода
            cout << "input error" << endl;
            exit(0);
        }
    }
    if (count2 != 0) {
        cout << count2<<endl;
    }
    else cout << "net grupp s nechetnym kolichestvom yedinits" << endl;
    return 0;
}