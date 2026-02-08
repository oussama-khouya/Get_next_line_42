# 📄 get_next_line

## Description

**get_next_line** is a function that reads a file descriptor **line by line**. Each call to the function returns the next line from the given file descriptor, including the newline character (`\n`) if it exists.

This project focuses on **static variables**, **buffer management**, and **careful memory handling** in C.

---

## 🧠 What You Learn

* How file descriptors work in C
* Reading files incrementally using buffers
* Managing memory dynamically
* Using static variables
* Handling edge cases (EOF, errors, long lines)

---

## 🔧 Prototype

```c
char *get_next_line(int fd);
```

---

## ⚙️ Behavior

* Returns the next line read from the file descriptor
* Includes the newline character (`\n`) if present
* Returns `NULL` when there is nothing more to read or on error
* Works with any valid file descriptor

---

## 🛠️ Compilation

Compile with your desired `BUFFER_SIZE`:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

---

## 🚀 Usage Example

```c
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## 🧪 Bonus Part

* Supports **multiple file descriptors** simultaneously
* Uses one static buffer per file descriptor

---

## 📌 Rules & Constraints

* Written in **C**
* Follows **42 Norm**
* No memory leaks
* Uses only allowed functions
* No global variables

---

## 👤 Author

**Oussama Khouya**
42 Student

---

## ✅ Status

✔️ Project completed and validated

---

> get_next_line teaches patience: read carefully, free carefully, and never lose a byte 🔥
