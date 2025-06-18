# 🚀 Accelerated C++ Learning Plan with Daily Projects
---

## 📅 Day 1: Syntax, Types & Functions
**Goal:** Master references, value semantics, and core syntax

### 🧩 Challenges
- Write a function that swaps two integers using references.
- Create a `constexpr` function to compute factorial at compile time.
- Write a function that takes a `const std::string&` and counts vowels.

### 💡 Project: Unit Converter
- Build a CLI unit converter (e.g., meters to feet, Celsius to Fahrenheit).
- Practice: references, value vs reference semantics, input/output, type aliases.

---

## 📅 Day 2: Classes, Structs & Smart Pointers
**Goal:** Understand object-oriented C++ and memory management

### 🧩 Challenges
- Write a `Timer` class that starts on construction and prints elapsed time on destruction (RAII).
- Create a `Person` class with constructor, `getFullName()`, and overloaded `<<`.
- Use `std::unique_ptr` to manage a dynamically allocated `Person`.

### 💡 Project: Contact Manager
- CLI app that manages `Person` objects in a vector using smart pointers.
- Support add/list/delete/search functionality.

---

## 📅 Day 3: STL Containers & Algorithms
**Goal:** Work fluently with `vector`, `map`, iterators, and lambdas

### 🧩 Challenges
- Count word frequencies in a string using `std::unordered_map`.
- Remove duplicates from a `std::vector<int>` using `std::set` or `std::unique`.
- Write a lambda to filter even numbers from a vector.

### 💡 Project: Student Gradebook
- Store students and their grades using `map<string, vector<int>>`.
- Add functions to compute average, max, and print leaderboard.

---

## 📅 Day 4: Templates & Modern Idioms
**Goal:** Use templates, type deduction, and modern utilities idiomatically

### 🧩 Challenges
- Write a templated `min()` function using `auto` and `decltype`.
- Use `std::optional<int>` to represent a "maybe result" from a search.
- Use `std::variant` to model a setting value (e.g., `int`, `float`, `string`).

### 💡 Project: Generic Stack Library
- Implement a templated `Stack<T>` class with push/pop/peek.
- Throw a custom exception on underflow.
- Use `std::optional<T>` for `peek()`.

---

## 📅 Day 5: CMake, Structure & Final Project
**Goal:** Build a full mini-project using idiomatic C++, CMake, and all learned tools

### 💡 Final Project Ideas
1. **Simple Todo CLI**
   - Features: add/remove/list todos
   - Data: `std::vector<Todo>`, use `std::optional`, `std::filesystem`
   - CLI parsing using `std::string_view`

2. **Mini JSON Parser**
   - Parse a JSON-like syntax into a `std::variant`
   - Practice: `std::map`, `std::vector`, `std::visit`, recursion

3. **File Word Frequency Analyzer**
   - Read from file, tokenize text, count frequencies with `unordered_map`
   - Sort and display most common words using `std::vector<pair>` + `std::sort`

### 📦 Tools to Use
- CMake for build
- Project layout: `include/`, `src/`, `tests/`
- `Catch2` or `doctest` for unit testing

---

## 🧠 Pro Tips
- Prefer **RAII** and **value semantics**
- Use `const&` and `auto` to avoid copies
- Avoid raw pointers; use `std::unique_ptr`
- Use STL algorithms over raw loops
- Annotate constructors/operators with `= default` / `= delete`

---

Let me know if you want a CMake template or repo starter for any of these projects!

