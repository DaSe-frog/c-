/* Дан следующий класс Integer, который представляет число:
*  Добавьте в него конструктор копирования. В функции main создайте один объект Integer и скопируйте его в другой.
*/

#include <iostream>

using namespace std;

class Integer{
public:
    Integer(int number)    {
        value = number;
    }
    Integer(const Integer& i) { //конструктор копирования
        value = i.value;
    }
    void print() const {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

int main(){
    Integer num{ 456 };
    num.print();
    Integer num_two{ num }; //вызов конструктора копирования
    num_two.print();
}

