#include "person.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

Person::Person(std::string first_name, std::string last_name) {
 _first_name = first_name;
 _last_name = last_name; 
}

std::string Person::get_full_name() const {
  return _first_name + " " + _last_name;
}

std::ostream &operator<<(std::ostream &out, const Person &person) {
  out << person.get_full_name();
  return out;
}

void run_person_example() {
  std::unique_ptr<Person> p(new Person("Doug", "Dimmadome"));
  std::cout << "I'm " << *p << ", owner of the Dimmsdale Dimmadome.\n";

  std::unique_ptr<Person> p2 = std::move(p);
  std::cout << "Now I'm " << *p2 << ", owner of the Dimmsdale Dimmadome.\n";
}
