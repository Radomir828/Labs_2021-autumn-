//
// Created by radomir on 03.02.2022.
//

#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

#include <vector>

template< class K, class V> class HashTable;

class Person{
private:
    int age;
    std::string name;
    std::string country;
public:
    Person() = default;
    ~Person() = default;

    Person(int age_, std::string name_, std::string country_) {
        age = age_;
        name = std::move(name_);
        country = std::move(country_);
    }
    int get_age() const { return age;}
    std::string get_name() const { return name;}
    std::string get_country() const { return country;}

    friend std::ostream &operator<<(std::ostream &, const Person &);
    friend std::istream &operator>>(std::istream &in, Person &p1);
    friend bool operator !=(const Person &p1, const Person &p2);
    friend bool operator ==(const Person &p1, const Person &p2);

};


bool operator ==(const Person &p1, const Person &p2)
{
    if (p1.get_age() != p2.get_age()) {
        return false;
    }
    if (p1.get_name() != p2.get_name()) {
        return false;
    }
    if (p1.get_country() != p2.get_country()) {
        return false;
    }
    return true;
}

bool operator !=(const Person &p1, const Person &p2)
{
    return !(p1 == p2);
}


std::ostream &operator<<(std::ostream &output, const Person &man) {
    output << man.name << " ";
    output << man.age << " ";
    output << man.country << " ";


    return output;
}
std::istream &operator>>(std::istream &in, Person &p1) {
    in >> p1.age;
    in >> p1.name;
    in >> p1.country;
    return in;
}

/*template<class K, class V>
class HashItem {
private:
    K key;                  // Name
    V value;                // Person
    HashItem<K, V> *next;
    bool is_empty{};
    bool is_deleted{};
    friend class HashTable<K, V>;
public:
    HashItem() = default;
    HashItem(K key_, V value_) {
        key = key_;
        value = value_;
        next = nullptr;
        is_empty = true;
        is_deleted = false;
    }
    ~HashItem() = default;

    const K& get_key() { return key; }
    const V& get_value() { return value; }

};*/

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
    void get_size(){ std::cout<< size;}
    V get_element(const K& key);

    int hash_function(K key);
    void print_table();


};


template<class K, class V>
HashTable<K, V>::HashTable(int capacity_) {
    capacity = capacity_;
    size = 0;
    table = new HashItem*[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
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
        throw std::out_of_range("Hash table is full!");
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


#endif //HASH_TABLE_HASHTABLE_H
