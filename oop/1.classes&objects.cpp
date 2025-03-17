/*
 *   1.
 *    + Создайте класс Integer с одной приватной переменной типа int. 
 *    + Определите конструктор класса, который выводит сообщение при создании объекта. 
 *    + Определите функции для получения и установки переменной и вывода ее значения. 
 *    + В функции main: 
 *           + создайте объект класса Integer
 *           + вызовите у него функции класса, получая, устанавливая и выводя значение переменной каждого объекта.
 *
 *    2. Возьмите класс Integer из предыдущего задания и разделите объявление функций класса от их определения.
*/

#include <iostream>

using namespace std;

/*class Integer1 {

private:

    int number;

public:

    Integer1(int value) {
        cout << "Constructor Integer." << endl;
        number = value;
        cout << "The object " << number << " was created!" << endl;
    }

    int GetValue() { 
        cout << "Get Value." << endl;
        return number; 
    }

    void SetValue(int num) {
        cout << "Set Value." << endl;
        number = num;
    }

    void PrintValue() {
        cout << "PrintValue" << endl;
        cout << "The value is: " << number << endl << endl;
    }

};


int main1() {
    Integer1 value{ 12 };
    value.PrintValue();
    value.SetValue(10);
    value.PrintValue();
    value.SetValue(value.GetValue() * 10);
    value.PrintValue();
}*/

class Integer2 {
private:
    int number;
public:
    Integer2(int value);
    int GetValue();
    void SetValue(int num);
    void PrintValue();
};

Integer2::Integer2(int value) {
    cout << "Constructor Integer." << endl;
    number = value;
    cout << "The object " << number << " was created!" << endl;
}

int Integer2::GetValue() {
    cout << "Get Value." << endl;
    return number;
}

void Integer2::SetValue(int num) {
    cout << "Set Value." << endl;
    number = num;
}

void Integer2::PrintValue() {
    cout << "PrintValue" << endl;
    cout << "The value is: " << number << endl << endl;
}

int main() {
    Integer2 value{ 12 };
    value.PrintValue();
    value.SetValue(10);
    value.PrintValue();
    value.SetValue(value.GetValue() * 10);
    value.PrintValue();
}
