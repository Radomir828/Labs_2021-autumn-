//
// Created by Korisnik on 13.11.2021..
//

#ifndef SORTING_LAB1_LINKEDLIST_H
#define SORTING_LAB1_LINKEDLIST_H
template<class T>
class LinkedList: public Sequence<T>{
private:
    typedef struct Item{
        T data;
        struct Item *next;
    } Item;

    typedef struct List{
        Item *head;
        Item *tail;
    } List;

    List *list;
    int size;

public:
    LinkedList();
    ~LinkedList();
    const T& get_first() override;
    const T& get_last() override;
    // const T& get_at_index(int index) override;
    // T& operator[] (int) override;
    const int& get_size() override;
    bool is_empty() override;
    bool is_full() override;
    void append(const T& data_) override;
    void remove_last_element();// override;
    void print();
    void remove_by_index(int index);



};

template<class T>
LinkedList<T>::LinkedList() {
    list = new List;
    list->head = nullptr;
    list->tail = nullptr;
    size = 0;


}

template<class T>
LinkedList<T>::~LinkedList() {
    Item *ptr = list->head, *ptr_prev;

    while (ptr) {
        if(ptr == nullptr) {
            break;
        }
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    delete list;
}


template<class T>
const T &LinkedList<T>::get_first() {
    return list->head->data;
}

template<class T>
const T &LinkedList<T>::get_last() {
    return list->tail->data;
}

template<class T>
const int& LinkedList<T>::get_size() {
    return size;
}

template<class T>
bool LinkedList<T>::is_empty() {
    if(size == 0){
        return true;
    } else{
        return false;
    }
}

template<class T>
bool LinkedList<T>::is_full() {
    if(size > 0){
        return true;
    } else{
        return false;
    }
}

template<class T>
void LinkedList<T>::append(const T &data_) {
    Item *node = new Item ;
    if(!node)
        throw bad_alloc();

    node->data = data_;
    node->next = nullptr;
    if(list->head == nullptr){              //unos kad nam je lista prazna
        list->head = node;
        list->tail = node;
    } else{
        list->tail->next = node;
        list->tail = node;
    }
    size++;  // povecava se broj elemenata;

}


template<class T>
void LinkedList<T>::print() {
    Item *ptr = list->head;
    while(ptr){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }

}

template<class T>
void LinkedList<T>::remove_last_element() {
    Item * ptr = list->head;
    while (ptr->next->next != nullptr)
        ptr = ptr->next;

    delete (ptr->next);

    ptr->next = nullptr;


    size --;

}

template<class T>
void LinkedList<T>::remove_by_index(int index) {
    Item *ptr = list->head;
    int i = 0;
//    Item *temp = ptr;
    if(index == 0){
        list->head = ptr->next;
        delete ptr;
        return;
    }
    Item *temp = ptr;
    while(ptr != nullptr && i < index){
        temp = ptr;
        ptr = ptr->next;
        i++;
    }
    //Item *temp = ptr;
    Item *deleted_node = ptr;
    Item *temp2 = deleted_node->next;
    delete deleted_node;
    temp->next = temp2;

}


#endif //SORTING_LAB1_LINKEDLIST_H
