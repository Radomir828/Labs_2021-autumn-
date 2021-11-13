//
// Created by Korisnik on 25.10.2021..
//

#ifndef SORTING_LAB1_DYNAMICARRAY_H
#define SORTING_LAB1_DYNAMICARRAY_H
#include "Sequence.h"
#include <chrono>

using namespace std;

template<class T>
class DynamicArray: public Sequence<T> {
private:
    T* array;
    int size;
    int capacity;
public:
    DynamicArray();
    //explicit DynamicArray(int capacity_);
//    ~DynamicArray();

    void clear();

    const int& get_size() override;
    const int& get_capacity();// override;

    const T& get_first() override;
    const T& get_last() override;
    const T& get_at_index(int index);// override;
    T& operator [](int index);// override;

    bool is_empty() override;
    bool is_full() override;

    void append(const T& data) override;
    void resize(int new_capacity); //override;
    void remove_last_element() override;
    void get_subsequence(int start_index, int end_index);// override;
    void print();

//    void remove_even_numbers();
//    void merge_sort(T*);

};

template<class T>
DynamicArray<T>::DynamicArray() {
    capacity = 1;
    size = 0;
    array = new T[capacity];
    if(!array)
        throw bad_alloc();
}

/*template<class T>
DynamicArray<T>::DynamicArray(int capacity_) {
    capacity = capacity_;
    size = 0;
    array = new T[capacity_];

    if(!array)
        throw bad_alloc();
}*/

template<class T>
const int& DynamicArray<T>::get_size() {
    return size;
}

template<class T>
const int& DynamicArray<T>::get_capacity() {
    return capacity;
}

template<class T>
const T &DynamicArray<T>::get_first() {
    return array[0];
}

template<class T>
const T &DynamicArray<T>::get_last() {
    return array[size - 1];
}

template<class T>
const T &DynamicArray<T>::get_at_index(int index) {
    if(index > size) {
        throw out_of_range("index mast be <= size");
    }
    return array[index];
}

template<class T>
T &DynamicArray<T>::operator[](int index) {
    if(index < 0) {
        throw out_of_range("index must be >= 0");
    }
    return array[index];
}

template<class T>
bool DynamicArray<T>::is_empty() {
    if(size == 0 ){
        return true;
    } else if(size < 0){
        throw out_of_range("size must be >= 0");
    } else{
        return false;
    }
}

template<class T>
bool DynamicArray<T>::is_full() {
    if(size == capacity){
        return true;
    } else{
        return false;
    }}

template<class T>
void DynamicArray<T>::append(const T& data) {
    if(is_full()){
        resize(capacity * 2);
        array[size] = data;
        size++;
    } else{
        array[size] = data;
        size++;
    }

}

template<class T>
void DynamicArray<T>::resize(int new_capacity) {
    //capacity = new_capacity;
    T* temp_array = new T[new_capacity];
    if(!temp_array){
        throw bad_alloc();
    }
    memcpy(temp_array, array, size * sizeof(T));
    delete [] array;
    array = temp_array;
    capacity = new_capacity;

}

template<class T>
void DynamicArray<T>::remove_last_element() {
    if(is_empty()) {
        throw out_of_range("You can't remove element. Array is empty!");
    } else{
        //array[size - 2] = array[size - 1];
        T* temp_array = new T[capacity];
        if(!temp_array){
            throw bad_alloc();
        }
        for(int i = 0; i < size - 1; i++) {
            temp_array[i] = array[i];
        }
        delete[] array;
        array = temp_array;
        size--;
    }

}

template<class T>
void DynamicArray<T>::get_subsequence(int start_index, int end_index) {
    if(start_index < 0 || end_index < 0 || start_index > size || end_index> size){
        throw out_of_range("start_index and end_index out of range");
    }

    for( ; start_index < end_index; start_index++){
        cout<<array[start_index]<<endl;
    }

}

/*template<class T>
DynamicArray<T>::~DynamicArray() {
    clear();

}*/

template<class T>
void DynamicArray<T>::clear() {
    delete[] array;
    array = nullptr;
    size = 0;
    capacity = 1;
}

template<class T>
void DynamicArray<T>::print() {
    for(int i = 0; i < size; i++){
        cout<<array[i]<<endl;
    }

}

/*
template<class T>
void DynamicArray<T>::remove_even_numbers() {
    int m = 0;
    for(int i = 0; i < size; i++){
        if(array[i] % 2 != 0){
            if(i != m){
                array[m] = array[i];
            }
            m++;
        }
    }
    size = m;
    for(int i = 0; i < m; i++){
        cout<<array[i]<<endl;
    }
}*/

#endif //SORTING_LAB1_DYNAMICARRAY_H
