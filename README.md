# Library Management System (C - Terminal)

This project is a **Library Management System** built in C for the terminal.  
It provides a simple way to manage users, books, and loans through file-based storage.

---

## Features
- **User Management**
  - Register new users
  - View the list of users
- **Book Management**
  - Register new books
  - View the list of books
- **Loan Management**
  - Register a new loan
  - Return an existing loan
  - View the list of loans

---

## Notes
- All data (users, books, loans) is stored in `.txt` files.
- The system runs entirely in the terminal.

---

## 📌 Requirements
C compiler (like GCC)

---

## 📦 How to compile and run

### How to compile: Linux / Mac / Git Bash / Windows:
```bash
gcc main.c home.c system.c book.c loans.c user.c -o main
```

### How to run: Linux / Mac / Git Bash:
```bash
./main
```

### How to run: Windows (CMD ou PowerShell):
```cmd
main.exe
```
---

### Locale Configuration (Portuguese - pt_BR.utf8)

To ensure proper display of special characters (accents and cedillas) in the terminal, you may need to configure the locale to `pt_BR.utf8`.  
If it is not available, use `C.UTF-8` as a fallback.

```bash
### ------------ Linux ------------
# List available locales
locale -a

# If "pt_BR.utf8" is listed, you’re ready to go.
# Otherwise, install it (Debian/Ubuntu example):
sudo locale-gen pt_BR.UTF-8
sudo update-locale


### ------------ macOS ------------
# Check current locale
locale

# If "pt_BR.UTF-8" is not available, use "C.UTF-8".


### ------------ Git Bash ------------
# List available locales
locale -a

# If "pt_BR.utf8" is listed, you’re ready.
# Otherwise, use "C.UTF-8".


### ------------ Windows (PowerShell) ------------
# Show current culture
Get-Culture

# Temporarily set environment variables
$env:LC_ALL="pt_BR.UTF-8"
$env:LANG="pt_BR.UTF-8"

# If not supported, use "C.UTF-8".
```
---

### Locale Fallback

If your system does not support **pt_BR.utf8**, you should use **C.UTF-8** as a fallback in the code.  
This ensures that the program still handles special characters correctly (such as accents and cedillas).

Example in C:
```c
#include <locale.h>

int main() {
    // Preferred
    setlocale(LC_ALL, "pt_BR.utf8");

    // Fallback if pt_BR.utf8 is not available
    setlocale(LC_ALL, "C.UTF-8");

    return 0;
}
```

---

## 📄 License
This project is licensed under the MIT License. See the LICENSE file for more details.

---

## 👨‍💻 Author
Made by Michael Rocha