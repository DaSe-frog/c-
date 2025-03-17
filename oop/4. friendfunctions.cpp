/*Дан следующий класс Integer, который представляет число:
  1. Добавьте в него функцию, которая сравнивает текущий объект с другим объектом Integer, 
     переданным в качестве аргумента. Функция должна возвращать число больше нуля, 
     если текущий объект больше аргумента; меньше нуля, если текущий объект меньше аргумента, и 0, если объекты равны.
     В функции main создайте несколько объектов Integer и сравните их.

  2. Сделайте функцию compare, которая определена в предыдущем задании в классе Integer, дружественной.
*/


#include <iostream>

using namespace std;

class Integer{
public:
    Integer(int number)    {
        value = number;
    }
    void print() const    {
        std::cout << "Value: " << value << std::endl;
    }
    int Compare(int num2) {
        if (value > num2) return 1;
        if (value < num2) return -1;
        if (value == num2) return 0;
    }
    int GetNum() {
        return  value;
    }
private:
    int value;
};

int main() {
    Integer num1{ 12 };
    Integer num2{ 123 };
    Integer num3{ 12 };
    cout << "For num1 = 12 and num2 = 123 fun return " << num1.Compare(num2.GetNum()) << endl;
    cout << "For num1 = 12 and num3 = 12 fun return " << num1.Compare(num3.GetNum()) << endl << endl;

    cout << "For num2 = 123 and num1 = 12 fun return " << num2.Compare(num1.GetNum()) << endl;
    cout << "For num2 = 123 and num3 = 12 fun return " << num2.Compare(num3.GetNum()) << endl << endl;

    cout << "For num3 = 12 and num1 = 12 fun return " << num3.Compare(num1.GetNum()) << endl;
    cout << "For num3 = 12 and num2 = 123 fun return " << num3.Compare(num2.GetNum()) << endl << endl;
    return 0;
}



