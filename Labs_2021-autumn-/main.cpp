#include <iostream>
#include "HashTable.h"
#include <cassert>


int main() {

    //Janko, Maja, Petra;
    Person Marko(28, "Marko Sobic", "Crna Gora");
    Person Janko (18, "Janko Karic", "Srbija");
    Person Maja (8, "Maja Raznatovic", "Bosna");
    Person Jana (78, "Jana Kuc", "Crna Gora");

    HashTable<std::string, Person> hash_table(10);

    std::cout << "Enter value and key:\n";

    hash_table.add(Maja.get_name(), Maja);
    hash_table.add(Jana.get_name(), Jana);
    hash_table.add("dfjhfdhfd", Janko);

    //hash_table.find("nsdnd");
    hash_table.print_table();
    std::cout << "\n\n\n";
    hash_table.remove(Jana.get_name());
    hash_table.print_table();


    assert(hash_table.get_element("dfjhfdhfd") == Janko);
    assert(hash_table.get_element(Maja.get_name()) == Maja);






    return 0;
}

