# Secured

![secured banner.png](bonus/assets/secured%20banner.png)
**Secured** is a C library for creating and managing hash tables, providing fast and secure storage for your data. It's designed for students and developers looking to explore hashing concepts while ensuring high performance and reliability.

---

## Features

- **Custom Hash Function**: Create your own hashing mechanism with full control over distribution and efficiency.
- **Hash Table Management**: Easily create, insert, search, and delete entries.
- **Collision Resolution**: Uses **separate chaining** for effective collision handling.
- **Lightweight and Fast**: Optimized for minimal memory usage and quick lookups.
- **Error Handling**: Robust error messages with appropriate return codes.

---

## Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Implemented Functions](#implemented-functions)
    - [Hash Table Functions](#hash-table-functions)
    - [Handle Table Functions](#handle-table-functions)
- [Usage Examples](#usage-examples)
- [Build System](#build-system)
- [Contributing](#contributing)
- [License](#license)

---

## Getting Started

Clone the repository:
```bash
git clone https://github.com/EpitechPGEPromo2029/B-CPE-110-PAR-1-1-secured-valentin.mine
cd Secured
```

Build the project using the included `Makefile`:
```bash
make
```

Run the tests or examples to ensure everything is working:
```bash
libhashtable.a
gcc main.c -L../.. -lhashtable  -iquote../../include
```

---

## Project Structure

The project is organized as follows:

```
Secured
├── bonus
│   ├── test_dev
│   │   ├── main.c
│   │   └── secured.c
│   └── tests
│       ├── compile.bash
│       └── main.c
├── include
│   ├── hashtable.h
│   ├── my.h
│   ├── secured.h
│   └── sha_256.h
├── lib
│   └── my
│       └── ... (utility functions)
├── Makefile
├── src
│   ├── create_hashtable.c
│   ├── dump
│   │   └── dump.c
│   ├── hash
│   │   ├── final_sha_hash.c
│   │   ├── hash.c
│   │   └── ... (other hashing functions)
│   ├── lib_linked_list
│   │   └── linked_lists.c
│   └── manager
│       ├── delete.c
│       ├── insert.c
│       └── ... (other management functions)
└── tests
    └── test_secured.c
```

This structure separates different functionalities into distinct directories:
- `include/`: Header files.
- `src/`: Implementation files.
    - `dump/`, `hash/`, and `manager/` provide specialized functionality for the hash table.
- `lib/`: Utility functions and libraries.
- `bonus/`: Additional testing and development files.
- `tests/`: Unit tests for the project.

---

## Implemented Functions

### Hash Table Functions

1. **Create a Hash Table**
   ```c
   hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
   ```
    - Creates a new hash table.
    - Takes a pointer to a hash function and the desired table size.

2. **Destroy a Hash Table**
   ```c
   void delete_hashtable(hashtable_t *ht);
   ```
    - Frees the memory used by the hash table.

---

### Handle Table Functions

1. **Insert an Entry**
   ```c
   int ht_insert(hashtable_t *ht, char *key, char *value);
   ```
    - Adds a new key-value pair to the table.

2. **Delete an Entry**
   ```c
   int ht_delete(hashtable_t *ht, char *key);
   ```
    - Removes a value based on its key.

3. **Search for a Value**
   ```c
   char *ht_search(hashtable_t *ht, char *key);
   ```
    - Returns the value associated with the given key.

4. **Dump Table Contents**
   ```c
   void ht_dump(hashtable_t *ht);
   ```
    - Displays the current state of the hash table.

---

## Usage Examples

### Creating and Managing a Hash Table
```c
#include "hashtable.h"

int main(void) {
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision", "./Documents/Vision");
    ht_insert(ht, "Kratos", "./Trash/Kratos.ai");

    ht_dump(ht);

    printf("Search result: %s\n", ht_search(ht, "Kratos"));

    ht_delete(ht, "Vision");
    ht_dump(ht);

    delete_hashtable(ht);
    return 0;
}
```

---

## Build System

The project uses a robust `Makefile` to simplify compilation and testing processes. Here is an overview of the Makefile's key features:

### Main Targets

- **`all`**: Builds the static library (`libhashtable.a`) by compiling all source files in the project.
- **`dev`**: Builds the development executable (`secured`), linking the necessary files for testing or debugging.
- **`clean`**: Removes all object files generated during compilation.
- **`fclean`**: Performs a `clean` and also deletes the compiled library and executables.
- **`re`**: Cleans and recompiles the entire project from scratch.
- **`unit_tests`**: Compiles unit tests using `criterion` and includes coverage tracking.
- **`tests_run`**: Runs the compiled unit tests and displays the results.

### Advanced Targets

- **`debug`**: Compiles the development executable with `-g3` `-ggdb3` for debugging with tools like `gdb`.
- **`asan`**: Builds the executable with AddressSanitizer enabled (`-fsanitize=address`) for memory issue detection.
- **`lib_build`**: Compiles the `libmy.a` static library from utility functions in the `lib/` directory.

### Example Commands

1. **Build the Static Library of seured**:
   ```bash
   make all
   ```
2. **Compile and Run Unit Tests**:
   ```bash
   make tests_run
   ```
3. **Rebuild the Entire Project**:
   ```bash
   make re
   ```
4. **Debugging**:
   ```bash
   make debug
   ```

The Makefile ensures efficient management of dependencies and supports advanced use cases like debugging and memory analysis, making it an essential tool for developers working on **Secured**.

---

## Contributing

We welcome contributions! To get started:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Submit a pull request with a clear explanation of your changes.

---

Made with ❤️ by **[Chloé BELIN](https://github.com/chloe-bln)** & **[Valentin MINÉ](https://github.com/chezrush)**

For any questions or suggestions, feel free to open an igithubssue or contact the maintainer.
