/*  Определите абстрактный класс Animal, который представляет животное 
    и который имеет две переменных - name (кличка животного) и weight (вес животного). 
    
    Также определите в классе Animal чистую виртуальную функцию makeSound, 
    которая представляет произносимые животным звуки, и функцию print, которая выводит на консоль имя и вес животного.

    Определите классы Cat (кошка) и Dog (собака), которые наследуются от класса Animal и которые переопределяют функцию makeSound

*/

#include <iostream>

using namespace std;

class Animal {
public: 
    Animal(string name, int weight) : name(name), weight(weight) {    }
    string name;
    int weight;

    virtual void makeSound() {
        //ее буду наследовать другие две
    }
    void print() {
        cout << "Name: " << name << ", weight: " << weight << endl;
    }
};

class Cat : public Animal {
    // тут наследуем фнкцию makesoud
};

class Dog : public Animal {
    // тут наследуем фнкцию makesoud
};

int main(){
    std::cout << "Hello World!\n";
}


