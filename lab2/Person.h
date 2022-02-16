//
// Created by radomir on 08.02.2022.
//

#ifndef HASH_TABLE_PERSON_H
#define HASH_TABLE_PERSON_H
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

#endif //HASH_TABLE_PERSON_H
