//
// Created by radomir on 12.02.2022.
//

#ifndef HASH_TABLE_CACHE_H
#define HASH_TABLE_CACHE_H

#include <queue>
#include <ctime>
#include "HashTable.h"
using namespace std;

template<class K>
struct QueueItem{
    K key;
    time_t time_el;
};

template<class K, class V>
class Cache {
private:
    HashTable<K, V> hash_table;
    queue<QueueItem<K>> cache;
    size_t size;
    time_t time_life;

public:
    Cache (size_t size_, time_t time_life_): hash_table(size_){
        size = size_;
        time_life = time_life_;
    };

    const V& get(K key){
        while(!cache.empty() && clock() - cache.front().time_el >= time_life ){
            hash_table.remove(cache.front().key);
            cache.pop();
            size--;
        }
        return (hash_table.get_element(key));
    };

    void push(K key, V value){
        while( (!cache.empty() && clock() - cache.front().time_el >= time_life) || cache.size() == size){
            hash_table.remove(cache.front().key);
            cache.pop();
            size--;
        }

        if (search(key)) {
            return;
        }

        struct QueueItem<K> *new_ptr = new struct QueueItem<K>;
        new_ptr->key = key;
        new_ptr->time_el = clock();
        size++;
        cache.push(*new_ptr);
        hash_table.add(key, value);
    };

    bool search(K key){
        return (hash_table.is_present(key));
    }

};
#endif //HASH_TABLE_CACHE_H
