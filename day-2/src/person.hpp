#pragma once

#include <ostream>
#include <string>

class Person {
  public:
    Person(std::string first_name, std::string last_name);
    std::string get_full_name() const;

  private:
    std::string _first_name;
    std::string _last_name;
};

std::ostream &operator<<(std::ostream &out, const Person &p);
