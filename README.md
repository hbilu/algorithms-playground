# Algorithm Playground 🧠 💻

This repository is for implementing and testing algorithms in both **C++** and **Python**.  
The goal is to keep the implementations clean, testable, and easy to compare across languages.

> ✅ All algorithms are unit-tested  
> ⚙️ CI workflows run tests automatically on every push and pull request  
> 🎓 Ideal for learning, experimentation, and language comparison

---

## 🗂️ Project Structure

```yaml
algorithm_playground/
  cpp_playground/                            # C++ algorithm implementations
    # algorithms (cpp and related hpp files) will be added here
  tests/cpp/                                 # C++ unit tests using Catch2
    - catch2/catch.hpp                       # Header-only Catch2 test framework
    - test_main.cpp                          # Main entry point to run all C++ tests
    # unit tests for C++ algorithms (cpp files) will be added here
  python_playground/                         # Python algorithm implementations
    # algorithms (py files) will be added here
  tests/python/                              # Python unit tests using pytest
    # unit tests for Python algorithms (py files) will be added here
  .github/workflows/                         # GitHub Actions CI setup
    - python-ci.yml                  
    - cpp-ci.yml                            
  CMakeLists.txt                             # C++ build configuration using CMake
  requirements.txt                           # Python dependencies
```
---
##  📦 Prerequisites
```markdown
Make sure the following tools are installed on your system:
🐍 For Python:
- Python 3.x 
- pip (usually included with Python) 
- (Optional) virtualenv for isolated environments
🦾 For C++:
- C++ compiler (e.g., g++, clang++, or MSVC for Windows)
- CMake
- Make (or Visual Studio/MSBuild on Windows)
```
---
## 🐍 Python Setup for Local Testing:
```markdown
  (Optional) Create a virtual environment
  - python -m venv venv
  - source venv/bin/activate    # On MacOS

  Install required packages
  - pip install -r requirements.txt

  Run all tests
  - pytest tests/python/
```

## 🦾 C++ Setup for Local Testing:
```markdown
  Create a build directory and compile
  - mkdir -p build
  - cd build
  - cmake ..
  - make

  Run all tests
  - ./cpp_tests     # On MacOS
```