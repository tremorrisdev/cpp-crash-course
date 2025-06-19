#include <algorithm>
#include <cstdlib>
#include <memory>
#include <unistd.h>
#include <vector>
#include <iostream>
#include <termios.h>
#include <csignal>
#include "person.hpp"

void run_timer_example();
void run_person_example();

std::vector<std::string> menu_options = {"Print Group A", "Print group B", "Add person to group A", "Add person to group B", "Swap the top person from Group A to Group B", "Exit"};

void wipe_menu() {
  std::cout << "\033[" << menu_options.size() << "A" << "\033[?25l";
  std::cout.flush();
}

void print_menu(termios &term, int &selection) {
  term.c_lflag &= ~(ICANON | ECHO);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
  for(int i = 0; i < menu_options.size(); i += 1)
  {
    std::string selector = i == selection ? "\033[0;36m◉" : "\033[0m○";
    std::cout << "  " << selector << "\033[0   " << menu_options[i] << "\n";
  }

  wipe_menu();
}

termios term;
void on_menu_exit() {  
  std::cout << "\033[?25h";
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void on_sigint(int signum) {
  on_menu_exit();
  exit(0);
}

void add_person(std::vector<std::unique_ptr<Person>> &group) {
  std::string first_name;
  std::string last_name;

  std::cout << "" << "Add Person" << std::endl << "First Name > ";
  std::cin >> first_name;
  std::cout << std::endl << "Last Name > ";
  std::cin >> last_name;

  group.push_back(std::make_unique<Person>(first_name, last_name));
}

void swap_first_person(std::unique_ptr<Person> &p, std::vector<std::unique_ptr<Person>> &group) {
  group.push_back(std::move(p));
}

int main() {
  run_timer_example();
  run_person_example();
  std::cout << std::endl;
  signal(SIGINT, on_sigint);
  tcgetattr(STDIN_FILENO, &term);
  termios copy = term;
  std::atexit(on_menu_exit);
  std::vector<std::unique_ptr<Person>> group_A;
  std::vector<std::unique_ptr<Person>> group_B;
  int selection = 0;
  while(true) {
    print_menu(copy, selection);
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) continue;
    if (c == '\033') {
      char seq[2];
      if (read(STDIN_FILENO, &seq[0], 1) != 1) continue;
      if (read(STDIN_FILENO, &seq[1], 1) != 1) continue;

      if (seq[0] == '[') {
        if (seq[1] == 'A') selection = std::max(selection - 1, 0);
        else if (seq[1] == 'B') selection = std::min(selection + 1, (int)menu_options.size() - 1);
      }
    } else if (c == '\n') {
      std::cout << "\033[" << menu_options.size() << "B" << std::endl;
      on_menu_exit();
      switch(selection) {
        case 0:
        case 1: {
          auto &group = selection == 0 ? group_A : group_B;
          if (group.size() == 0) std::cout << "No members in group" << std::endl;
          for (int i = 0; i < group.size(); i += 1) {
            std::cout << *group[i] << std::endl;
          }
          break;
        }
        case 2:
          add_person(group_A);
          break;
        case 3:
          add_person(group_B);
          break;
        case 4:
          swap_first_person(group_A[0], group_B);
          break;
        case 5:
          on_sigint(0);
          break;
      }

      selection = 0;
      std::cout << std::endl;
    }
  }
}
