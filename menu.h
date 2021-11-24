//
// Created by Korisnik on 13.11.2021..
//

#ifndef SORTING_LAB1_MENU_H
#define SORTING_LAB1_MENU_H
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sort.h"
#include <chrono>
#include <cassert>
using namespace std::chrono;
using namespace std;
class Animal {
private:
    int age;
    string name;
    int weight;
public:
    Animal() = default;

    Animal(int _age, const string &_name, int _weight) {
        age = _age;
        name = _name;
        weight = _weight;
    }

    int get_age() const {
        return age;
    };

    int get_weight() const {
        return age;
    };

    const string &get_name() const {
        return name;
    };

    friend ostream &operator<<(ostream &, const Animal &);
    friend istream &operator>>(istream &, Animal &);
};

ostream& operator <<(ostream &output, const Animal &a)
{
    output << a.age << " ";
    output << a.name << " ";
    output << a.weight;
    return output;
}

istream& operator >>(istream &input, Animal &a){
    input >> a.age;
    return input;
}


template<typename T>
int comp_simple(const T& a, const T& b){
    if (a > b) { return 1; }
    if (a == b) { return 0; }
    return -1;

}


int comp_animal(const Animal& a1, const Animal& a2) {
    if(a1.get_age() > a2.get_age()) { return 1;}
    if(a1.get_age() == a2.get_age()) { return 0;}
    return -1;
}


using namespace std;
void menu() {

}
#endif //SORTING_LAB1_MENU_H
