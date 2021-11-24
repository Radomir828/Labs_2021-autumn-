//
// Created by Korisnik on 25.10.2021..
//

#ifndef SORTING_LAB1_SEQUENCE_H
#define SORTING_LAB1_SEQUENCE_H

#include <iostream>

using namespace std;

template<class T>
class Sequence{
public:
    Sequence() = default;
    virtual ~Sequence() = default;

    virtual int get_size() = 0;
    //virtual const int& get_capacity() = 0;

    virtual const T& get_first() = 0;
    virtual const T& get_last() = 0;
    virtual const T& get_at_index(int) = 0;
    // virtual T& operator[](int) = 0;

    virtual bool is_empty() = 0;
    virtual bool is_full() = 0;
    virtual void append(const T&) = 0;
//    virtual void resize(int ) = 0;
    virtual void remove_last_element() = 0;
    //virtual void get_subsequence(int, int) = 0;
};

#endif //SORTING_LAB1_SEQUENCE_H
