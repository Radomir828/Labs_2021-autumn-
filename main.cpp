
#include "menu.h"

using namespace std;

int main() {


    DynamicArray<int> array;

    srand(time(nullptr));

    for(int i = 0; i < 10; i++){
        array.append(rand() % 290);
    }
    array.print();
    cout<<"After sorting:"<<endl;
    Sort<int> sorting;
//    auto start = high_resolution_clock::now();
//    sorting.merge_sort(array, 0, array.get_size() - 1);
//    auto end = high_resolution_clock::now();
//    auto duration = duration_cast<nanoseconds>(end - start);
//    array.print()
//    cout << "Time taken for merge sort: "
//         << duration.count() << " ns" << endl;


    auto start = high_resolution_clock::now();
    sorting.quickSort(array, 0, array.get_size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    array.print();
    cout << "Time taken for quick sort: "
         << duration.count() << " ns" << endl;

/*sorting.quickSort(array, 0, array.get_size() - 1);
    array.print();*/


    return 0;
}
