#include <iostream>
#include "HashTable.h"
#include <cassert>
#include "Cache.h"
#include <chrono>
#include <thread>


int main() {

    //Janko, Maja, Petra;
    Person Marko(28, "Marko Sobic", "Crna Gora");
    Person Janko (18, "Janko Karic", "Srbija");
    Person Maja (8, "Maja Raznatovic", "Bosna");
    Person Jana (78, "Jana Kuc", "Crna Gora");
    Person Petar (84, "Petar Peric", "Rusija");


    HashTable<std::string, Person> hash_table(2);


    hash_table.add(Maja.get_name(), Maja);
    hash_table.add(Jana.get_name(), Jana);
    hash_table.add("dfjhfdhfd", Janko);

    hash_table.print_table();
//    hash_table.print_capacity();
    std::cout << "\n\n\n";
    hash_table.remove(Jana.get_name());
    hash_table.print_table();


    assert(hash_table.get_element("dfjhfdhfd") == Janko);
    assert(hash_table.get_element(Maja.get_name()) == Maja);


    Cache<std::string, Person> cash(4, 10);

    cash.push(Maja.get_name(), Maja);
    if (cash.search(Maja.get_name()))
        cout << "Adding works!" << endl;


    std::this_thread::sleep_for(std::chrono::seconds(5));

    cash.push(Janko.get_name(), Janko);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    cash.push(Jana.get_name(), Jana);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    if (!cash.search(Maja.get_name()) && cash.search(Jana.get_name()))
        cout << "Time for deleting is working";


    return 0;
}

