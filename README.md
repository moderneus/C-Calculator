# C-Calculator

A modern, console-based calculator written in C++.  
Created for self-study and practical exploration of C++ features, code structure, and best practices.

---

## Features

- **Basic arithmetic operations:** addition, subtraction, multiplication, division, exponentiation.
- **Advanced math functions:** factorial, square root, sin, cos, tan, ctan.
- **Input validation:** robust checks and informative error messages for invalid input, division by zero, overflow, and undefined values.
- **Calculation history:** all operations are saved to `history.txt`. Clear history with a single command.
- **Colorful and user-friendly output:** leveraging [fmt](https://github.com/fmtlib/fmt) for colored messages (Windows only).
- **Extensible architecture:** clean separation between logic, UI, and utilities for easy maintenance and future development.
- **Cross-platform support:** runs on Windows and Linux (minor tweaks for color support on Linux).

---

## Requirements

- **C++ Standard:** C++20 or newer
- **CMake:** Version 3.20 or newer
- **Dependencies:**
  - [fmt](https://github.com/fmtlib/fmt) (version 8.32 or newer recommended)
- **(Optional) Windows console:** for full color support via ANSI codes.

### Installing Dependencies

#### Windows 
- Use vcpkg or download fmt from GitHub:
  ```sh
  vcpkg install fmt
  ```
- Or, build fmt from source:
  ```sh
  git clone https://github.com/fmtlib/fmt.git
  cd fmt
  mkdir build && cd build
  cmake ..
  cmake --build . --config Release
  ```

#### Linux 
- Install fmt via package manager:
  ```sh
  sudo apt install libfmt-dev
  ```
- Or build from source as above.

---

## Build Instructions

### Using CMake

1. **Clone the repository:**
   ```sh
   git clone https://github.com/moderneus/C-Calculator.git
   cd C-Calculator
   ```

2. **Create a build directory and configure the project:**
   ```sh
   mkdir build
   cd build
   cmake ..
   ```

   > If fmt is installed in a custom location, you may need to specify its path:
   > ```sh
   > cmake .. -DCMAKE_PREFIX_PATH=/path/to/fmt
   > ```

3. **Build the executable:**
   ```sh
   cmake --build .
   ```

---

## Usage

1. **Run the calculator:**
   - Windows: `calculator.exe`
   - Linux: `./calculator`

2. **Follow the menu:**
   - The program displays a numbered list of operations.
   - Type the number or command (e.g. `1` for addition, `exit` to quit, `clear` to clear history).

3. **Enter the required values:**
   - For binary operations, you will be prompted for two values.
   - For unary operations (factorial, sqrt, etc.), enter a single value.

4. **View results and history:**
   - Results are shown in the console (with color on Windows).
   - All calculations are saved to `history.txt` in the project directory.

### Example

```
The history of your calculations is saved in the file history.txt. To clear it, enter the command 'clear'.

Enter a number of operation you want to use:
1. Addition
2. Subtraction
3. Multiplication
4. Division
...

Operation number: 1
Enter a first value: 8
Enter a second value: 15
Value equals: 23

Operation number: clear
History cleared.
```

---

## Commands

| Command      | Description             |
|--------------|-------------------------|
| 1            | Addition                |
| 2            | Subtraction             |
| 3            | Multiplication          |
| 4            | Division                |
| 5            | Exponentiation          |
| 6            | Factorial               |
| 7            | Square Root             |
| 8            | Sin                     |
| 9            | Cos                     |
| 10           | Tan                     |
| 11           | Ctan                    |
| clear        | Clear history file      |
| exit         | Exit calculator         |

---

## Project Structure

```
C-Calculator/
├── headers/
│   ├── History.hpp
│   ├── Operations.hpp
│   ├── CommandMap.hpp
│   └── Utils/
│       ├── PrintUtils.hpp
│       ├── RequestUtils.hpp
│       ├── Constants.hpp
│       ├── CheckUtils.hpp
│       └── Utils.hpp
├── src/
│   ├── Calculator.cpp
│   ├── CommandMap.cpp
│   ├── History.cpp
│   ├── Operations.cpp
│   └── Utils/
│       ├── PrintUtils.cpp
│       ├── RequestUtils.cpp
│       ├── CheckUtils.cpp
│       └── Utils.cpp
├── history.txt
└── README.md
```

---

## Contribution

Feedback, ideas, and code reviews are welcome!  
If you find a bug or have suggestions, feel free to open an issue or pull request.

---

## License

This project is released under the MIT License.

---

## Author

Created by [moderneus](https://github.com/moderneus)  
If you stumbled upon this project, I'd love to hear your feedback about the code, structure, or anything else!
