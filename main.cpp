
#include <utility>

#include "menu.h"

int main() {

/*    Animal cat(10, "zvrko", 4);
    Animal dog(100, "lesi", 14);
    Animal cow(12, "dusanka", 54);
    Animal snake(1, "qwer", 1);

    DynamicArray<Animal> array;
    array.append(dog);
    array.append(cat);
    array.append(cow);
    array.append(snake);
    array.print();
    Sort<Animal> sorting;
    sorting.merge_sort(array, 0, array.get_size() - 1, &comp_animal);*/
//    sorting.quicksort(array, 0, array.get_size() - 1, &comp_animal);

 /*   DynamicArray<int> array;

    srand(time(nullptr));
    for(int i = 0; i < 10; i++){
        array.append(rand() % 29);
    }
    array.print();
    Sort<int> sorting;
    sorting.merge_sort(array, 0, array.get_size() - 1, &comp_simple);*/
//    sorting.quick_sort(array, 0, array.get_size() - 1, &comp_simple);

    cout<<"After sorting:"<<endl;
    array.print();

/*    LinkedList<int> list;
    list.append(5);
    list.append(2);
    list.append(67);
    list.append(15);
    list.append(154);
   // list.merging();

   Sort<int> sorting;
   sorting.list_merge_sort(list.get_head(), &comp_simple);*/
    LinkedList<int> list;
    list.append(5);
    list.append(2);
    list.append(67);
    list.append(15);
    list.append(154);





    return 0;
}
