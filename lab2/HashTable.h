//
// Created by radomir on 03.02.2022.
//

#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

#include <vector>
#include "Person.h"

template< class K, class V>
class HashTable {
private:
    struct HashItem {
        K key;
        V value;
    };
    HashItem **table; // u ovom masivu cuvamo strukturu HashItem*
    int capacity;
    int size;

public:
    explicit HashTable(int capacity_);
    ~HashTable();
    void add(const K& key, const V& value);
    void remove(const K& key);
    void find(const K& key);
    bool is_present(const K& key);
    void print_size(){ std::cout << size;}
    void print_capacity() { std::cout << capacity;}
    V get_element(const K& key);
    void resize();

    int hash_function(K key);
    void print_table();


};


template<class K, class V>
HashTable<K, V>::HashTable(int capacity_) {
    if (capacity_ < 1) {
        throw std::logic_error("Capacity can't be less than 1");
    }
    capacity = capacity_;
    size = 0;
    table = new HashItem*[capacity];
    if(!table){
        throw std::bad_alloc();
    }
    std::fill_n(table, capacity, nullptr);

}

template<class K, class V>
HashTable<K, V>::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        if (table[i]){
            delete table[i];
            table[i] = nullptr;
        }
    }
    delete [] table;

}

template<class K, class V>
int HashTable<K, V>::hash_function(K key) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
        sum += int(key[i]);
    return  sum % capacity;
}

template<class K, class V>
void HashTable<K, V>::add(const K& key, const V& value) {
    if (size == capacity) {
        resize();
    }
    int index = hash_function(key);
    auto *new_element = new HashItem;
    new_element->value = value;
    new_element->key = key;

    if (table[index] == nullptr) {
        table[index] = new_element;
    } else {
        while(table[index] != nullptr && table[index]->key != key) {
            index++;
            index %= capacity;
        }
        table[index] = new_element;
    }
    size++;

}

template<class K, class V>
void HashTable<K, V>::resize() {
    int old_capacity = capacity;
    capacity *= 5;
    auto** new_table = new HashItem*[capacity];
    if(!new_table){
        throw std::bad_alloc();
    }
    std::fill_n(new_table, capacity, nullptr);

    for (int i = 0; i < old_capacity; i++) {
        if (table[i] != nullptr) {
            int new_index = hash_function(table[i]->key);
            new_table[new_index] = table[i];
        }
    }
    delete [] table;
    table = new_table;
}

template<class K, class V>
void HashTable<K, V>::print_table() {

    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            std::cout << i << ": Key = " << table[i]->key << "\t\tValue = " << table[i]->value << std::endl;
        } else {
            std::cout << i << ": null" << "\t"<< std::endl;
        }
    }

}

template<class K, class V>
void HashTable<K, V>::find(const K &key) {
    int index = hash_function(key);
    bool found = false;
    while (table[index] != nullptr) {
        if (table[index]->key == key ) {
            std::cout << "Element is found. Value:" << table[index]->value << std::endl;
            found = true;
        }
        index++;
        index %= capacity;
    }
    if(!found) {
        std::cout << "Element is not found." << std::endl;
    }

}

template<class K, class V>
void HashTable<K, V>::remove(const K& key) {
    int index = hash_function(key);
    bool found = false;
    while (table[index] != nullptr) {
        if (table[index]->key == key ) {

            delete table[index];
            table[index] = nullptr;
            found = true;
        }
        index++;
        index %= capacity;
    }
    if(!found) {
        throw std::logic_error("Element is not present in table");

    }
    size--;
}

template<class K, class V>
V HashTable<K, V>::get_element(const K &key) {
    int index = hash_function(key);
    while (table[index] != nullptr) {
        if (table[index]->key == key ) {
//            std::cout << "Element is found. Value:" << table[index]->value << std::endl;
            return table[index]->value;
        }
        index++;
        index %= capacity;
    }

    throw std::logic_error("Element you are looking for is not present in table");
}

template<class K, class V>
bool HashTable<K, V>::is_present(const K &key) {

    int index = hash_function(key);
    while (table[index] != nullptr) {
        if (table[index]->key == key ) {
            return true;
        }
        index++;
        index %= capacity;
    }

    return false;
}

#endif //HASH_TABLE_HASHTABLE_H
