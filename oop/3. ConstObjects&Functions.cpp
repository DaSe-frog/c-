/*
* Дан следующий класс Integer, который хранит некоторое число:
* Исправьте класс, сделав константными все функции, которые можно сделать константными.
  Определите в функции main переменную и константу этого класса Integer и проверьте, какие операции можно применять к ним.
*/


#include <iostream>

using namespace std;


class Integer{

public:
    Integer(int number);
    int getValue() const;
    void setValue(int number);
    void print() const;

private:
    int value;

};

Integer::Integer(int number) {
    value = number;
    cout << "Object created" << endl;
}

int Integer::getValue() const {
    return value;
}

void Integer::setValue(int number) { 
    value = number; 
}

void Integer::print() const{
    cout << "Value: " << value << endl;
}

int main() {
    // cout << "Hello World!\n";
    const Integer val{ 1256 };
    val.getValue();
    val.print();
    Integer val2{ 45 };
    val2.print();
    val2.setValue(26);
    val2.print();
}