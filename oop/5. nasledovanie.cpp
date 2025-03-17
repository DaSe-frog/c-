/*  Определите базовый класс Animal, который представляет животное и который содержит две приватные переменные: 
    строку для хранения имени животного и целое число для хранения веса животного. 
    Определите общедоступную функцию print, которая выводит на консоль сообщение с указанием имени и веса объекта Animal.

    Также создайте два производных класса Cat (кошка) и Dog (собака), которые наследуются от класса Animal. 
    В функции main создайте несколько объектов типа Cat и Dog и с помощью функции print выведите информацию об этих объектах на консоль.
*/

#include <iostream>

using namespace std;

class Animal {

public:
    void print_info() {
        cout << "Name: " << name << ", weight: " << weight << ". " << endl;
    }

    string name;
    int weight;
};

class Cat : public Animal {

};

class Dog : public Animal {

};
 
int main() {
    Cat cat1;
    cat1.name = "Froggy";
    cat1.weight = 5;
    cat1.print_info();
    cout << endl << endl;

    Cat cat2;
    cat2.name = "Casper";
    cat2.weight = 2;
    cat2.print_info();
    cout << endl << endl;

    Dog dog1;
    dog1.name = "Puppy";
    dog1.weight = 30;
    dog1.print_info();
}