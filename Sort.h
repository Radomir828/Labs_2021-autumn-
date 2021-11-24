//
// Created by Korisnik on 29.10.2021..
//

#ifndef SORTING_LAB1_SORT_H
#define SORTING_LAB1_SORT_H
#include "DynamicArray.h"



template<typename T>
class Sort{
public:
    Sort() = default;
    ~Sort() = default;

    void merge_sort(DynamicArray<T>& arr, int start, int end, int (*comp) (const T&, const T&));//    void merge(DynamicArray<T>, DynamicArray<T>, DynamicArray<T>);//, const int, const int);
    void merge(DynamicArray<T>& array, int start, int mid, int end, int (*comp) (const T&, const T&));
    void insert_sort(DynamicArray<T>& array);
    void quick_sort(DynamicArray<T>& , int , int, int (*comp) (const T&, const T&) );
//    void swap(T*, T*);
    int partition (DynamicArray<T>&, int, int, int (*comp) (const T&, const T&));
    void swap(T&, T& );

   // void list_merge_sort( typename LinkedList<T>::Item* , int (*comp) (const T&, const T&));
//    void list_merge(LinkedList<T>&, LinkedList<T>&, LinkedList<T>&, int(*comp) (const T&, const T&));
//    void list_merge_sort(LinkedList<T>&, int(*comp) (const T&, const T&));
};


template<typename T>
void Sort<T>::insert_sort(DynamicArray<T>& array) {
    T character;
    int j;
    for(int i = 1; i < array.get_size(); i++){
        character = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > character){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = character;

    }
/*    for(int i = 0; i < array.get_size(); i++){
        cout<<array[i]<<endl;
    }*/
}


template<typename T>
void Sort<T>:: swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;

}


template<typename T>
int Sort<T>::partition (DynamicArray<T>& array, int start, int end, int (*comp) (const T&, const T&))
{
    T pivot = array[end];
    int index = start;

    for (int i = start; i < end; i++)
    {
        if (comp(array[i], pivot) <= 0)
        {
            swap(array[index], array[i]);
            index++;    // increment index of smaller element
        }
    }
    swap(array[index], array[end]);
    return index;
}

template<typename T>
void Sort<T>::quick_sort(DynamicArray<T>& array, int start, int end, int (*comp) (const T&, const T&))
{
    if (start < end)
    {

        int pivot_index = partition(array, start, end, comp);

        quick_sort(array, start, pivot_index - 1, comp);
        quick_sort(array, pivot_index + 1, end, comp);
    }
}

template<typename T>
void Sort<T>::merge(DynamicArray<T>& array, int start, int mid, int end, int  (*comp) (const T&, const T&)) {

    int n1 = mid - start + 1;
    int n2 = end - mid;
    DynamicArray<T> left_subarr;    // left_subarr[start, ..., mid]
    DynamicArray<T> right_subarr;   // right_subarr[mid + 1, ..., end]


    for (int i = 0; i < n1; i++)
        left_subarr.append(array[start + i]);       // array[start..mid] --> left_subarr
    for (int j = 0; j < n2; j++)
        right_subarr.append(array[mid + 1 + j]);    // array[(mid + 1)..end] --> right_subarr

    int i, j, k;
    i = 0;      // following left_subarr
    j = 0;      // following right_subarr
    k = start;  // following main array

//    while (i < n1 && j < n2) {
    while (i < left_subarr.get_size() && j < right_subarr.get_size()) {
        if ( comp(left_subarr[i], right_subarr[j]) <= 0 ) {
            array[k] = left_subarr[i];
            i++;
        } else {
            array[k] = right_subarr[j];
            j++;
        }
        k++;
    }

    while (i < left_subarr.get_size()) {
        array[k] = left_subarr[i];
        i++;
        k++;
    }

    while (j < right_subarr.get_size()) {
        array[k] = right_subarr[j];
        j++;
        k++;
    }
}

template<typename T>
void Sort<T>:: merge_sort(DynamicArray<T>& arr, int start, int end, int (*comp) (const T&, const T&)) {


    if (start < end) {
        int m = start + (end - start) / 2;

        merge_sort(arr, start, m, comp);
        merge_sort(arr, m + 1, end, comp);
        merge(arr, start, m, end, comp);
    }
}
/*
template<typename T>
void Sort<T>::list_merge_sort(typename LinkedList<T>::Item *list_head, int (*comp)(const T &, const T &)) {
    if (list_head == nullptr || list_head->next == nullptr) { return;}
    LinkedList<T>::Item *a = new LinkedList<T>;

    //cout<<list_head->next->data;
}*/


/*

template<typename T>
void Sort<T>::list_merge_sort(LinkedList<T>& list, int(*comp) (const T&, const T&)) {
    if(list.get_size() <= 1){ return;}

    LinkedList<T> list1, list2;

    int n = list.get_size();
    for(int i = 0; i <= n / 2; i++) {
        list1.append(list.get_at_index(i));
    }
    for(int i = (n / 2) + 1 ; i < n; i++) {
        list2.append(list.get_at_index(i));
    }
    cout<<"sve ok ";

    list.clear();
    cout<<"list1 :"; list1.print(); cout<<"\n\n";
    cout<<"list2 :"; list2.print(); cout<<"\n\n";

    list_merge_sort(list1, comp);
    list_merge_sort(list2, comp);
    list_merge(list1, list2, list, comp);

}


template<typename T>
void Sort<T>::list_merge(LinkedList<T> &list1, LinkedList<T> &list2, LinkedList<T> &list, int (*comp)(const T &, const T &)) {

    int i = 0;
    int j = 0;
    while (i < list1.get_size() && j < list2.get_size()) {
        if(comp(list1.get_at_index(i), list2.get_at_index(j)) <= 0 ){
            list.append(list1.get_at_index(i));
            i++;

        } else {
            list.append(list2.get_at_index(j));
            j++;
        }
    }

    while (i < list1.get_size()) {
        list.append(list1.get_at_index(i));
        i++;
    }
    while (j < list1.get_size()) {
        list.append(list2.get_at_index(j));
        j++;
    }
}
*/

#endif //SORTING_LAB1_SORT_H
