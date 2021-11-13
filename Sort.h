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

    void merge_sort(DynamicArray<T> arr, int start, int end);//    void merge(DynamicArray<T>, DynamicArray<T>, DynamicArray<T>);//, const int, const int);
    void merge(DynamicArray<T> array, int start, int mid, int end);
    void insert_sort(DynamicArray<T> array);
    void quickSort(DynamicArray<T> , int , int );
//    void swap(T*, T*);
    int partition (DynamicArray<T>, int, int);

    void swap(T &a, T &b);
};


template<typename T>
void Sort<T>::insert_sort(DynamicArray<T> array) {
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
int Sort<T>::partition (DynamicArray<T> array, int start, int end)
{
    T pivot = array[end];
    int index = start;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= pivot)
        {
            swap(array[index], array[i]);
            index++;    // increment index of smaller element
        }
    }
    swap(array[index], array[end]);
    return index;
}

template<typename T>
void Sort<T>::quickSort(DynamicArray<T> array, int start, int end)
{
    if (start < end)
    {

        int pivot_index = partition(array, start, end);

        quickSort(array, start, pivot_index - 1);
        quickSort(array, pivot_index + 1, end);
    }
}

template<typename T>
void Sort<T>::merge(DynamicArray<T> array, int start, int mid, int end) {

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
        if (left_subarr[i] <= right_subarr[j]) {
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
void Sort<T>:: merge_sort(DynamicArray<T> arr, int start, int end) {


    if (start < end) {
        int m = start + (end - start) / 2;

        merge_sort(arr, start, m);
        merge_sort(arr, m + 1, end);
        merge(arr, start, m, end);
    }
}

#endif //SORTING_LAB1_SORT_H
