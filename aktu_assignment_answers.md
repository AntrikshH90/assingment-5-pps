# AKTU Assignment Answers
**Course Instructor:** Mr. Ravi Kumar  
**Last Date for Submission:** 15th Dec, 2025

---

## SHORT QUESTIONS

### 1. What is linked list? Write the self-referential structure of a node in linked list?

**Answer:**

A **Linked List** is a linear data structure where elements are stored in nodes. Unlike arrays, linked list elements are not stored at contiguous memory locations. Each node contains:
- Data field (to store the value)
- Pointer field (to store the address of the next node)

**Self-Referential Structure:**

```c
struct Node {
    int data;              // Data part
    struct Node* next;     // Pointer to next node (self-referential)
};
```

**Advantages:**
- Dynamic size
- Easy insertion/deletion
- No memory wastage

**Disadvantages:**
- Extra memory for pointers
- No random access
- Sequential access only

---

### 2. What are Header files? Why are they important?

**Answer:**

**Header files** are files with `.h` extension that contain:
- Function declarations
- Macro definitions
- Structure definitions
- Type definitions

**Importance:**

1. **Code Reusability:** Write once, use multiple times
2. **Modularity:** Separate interface from implementation
3. **Readability:** Makes code cleaner and organized
4. **Standard Library Access:** Provides access to standard functions like `printf()`, `scanf()`, etc.
5. **Avoid Redundancy:** Prevents writing same declarations multiple times

**Common Header Files:**
- `stdio.h` - Standard Input/Output
- `stdlib.h` - Standard Library functions
- `string.h` - String manipulation
- `math.h` - Mathematical functions
- `ctype.h` - Character handling

---

### 3. Explain the role of C pre-processor.

**Answer:**

The **C Preprocessor** is a program that processes the source code before compilation. It performs text substitution and file inclusion.

**Main Roles:**

1. **File Inclusion (`#include`)**
   - Includes header files
   - Example: `#include <stdio.h>`

2. **Macro Definition (`#define`)**
   - Defines constants and macros
   - Example: `#define PI 3.14`

3. **Conditional Compilation (`#ifdef`, `#ifndef`, `#endif`)**
   - Compiles code based on conditions
   - Used for debugging and platform-specific code

4. **Macro Expansion**
   - Replaces macro names with their definitions

**Preprocessing Directives:**
- `#include` - File inclusion
- `#define` - Macro definition
- `#undef` - Undefine macro
- `#ifdef` - If defined
- `#ifndef` - If not defined
- `#if`, `#else`, `#elif`, `#endif` - Conditional compilation

**Example:**
```c
#define MAX 100
#define SQUARE(x) ((x)*(x))
```

---

### 4. What do you mean by pointer arithmetic?

**Answer:**

**Pointer Arithmetic** refers to performing arithmetic operations on pointers. Only certain operations are allowed:

**Allowed Operations:**

1. **Increment (`++`)**: Moves pointer to next memory location
2. **Decrement (`--`)**: Moves pointer to previous memory location
3. **Addition (`+`)**: Adds integer to pointer
4. **Subtraction (`-`)**: Subtracts integer from pointer or finds difference between two pointers
5. **Comparison**: Compare two pointers

**Important Points:**

- When you increment a pointer, it moves by the size of the data type it points to
- For `int*` (4 bytes): `ptr++` moves 4 bytes ahead
- For `char*` (1 byte): `ptr++` moves 1 byte ahead

**Example:**
```c
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;

ptr++;      // Now points to arr[1]
ptr = ptr + 2;  // Now points to arr[3]
```

**Invalid Operations:**
- Multiplication
- Division
- Addition of two pointers

---

### 5. Difference between static and dynamic memory allocation.

**Answer:**

| **Aspect** | **Static Memory Allocation** | **Dynamic Memory Allocation** |
|------------|------------------------------|-------------------------------|
| **Time** | Compile time | Runtime |
| **Memory Area** | Stack | Heap |
| **Size** | Fixed, cannot be changed | Can be changed using `realloc()` |
| **Allocation** | Automatic by compiler | Manual using `malloc()`, `calloc()` |
| **Deallocation** | Automatic when scope ends | Manual using `free()` |
| **Efficiency** | Faster | Slower |
| **Memory Wastage** | May waste memory if not fully used | Efficient, allocate only needed |
| **Example** | `int arr[10];` | `int *ptr = (int*)malloc(10*sizeof(int));` |
| **Flexibility** | Less flexible | More flexible |
| **Lifetime** | Till end of scope | Till explicitly freed |

**Example:**

**Static:**
```c
int arr[100];  // Fixed size, allocated at compile time
```

**Dynamic:**
```c
int *arr = (int*)malloc(n * sizeof(int));  // Size decided at runtime
free(arr);  // Must free manually
```

---

### 6. What is the difference between `#include <filename.h>` and `#include "file_name.h"`?

**Answer:**

| **Aspect** | **`#include <filename.h>`** | **`#include "filename.h"`** |
|------------|----------------------------|----------------------------|
| **Search Location** | System/standard directories | Current directory first, then system directories |
| **Usage** | Standard library headers | User-defined headers |
| **Search Order** | Only in predefined paths | 1. Current directory<br>2. Compiler's include path |
| **Example** | `#include <stdio.h>`<br>`#include <stdlib.h>` | `#include "myheader.h"`<br>`#include "functions.h"` |
| **Speed** | Faster (searches fewer locations) | Slightly slower (searches current dir first) |

**When to Use:**

- **Angle brackets `< >`**: For standard library headers
- **Double quotes `" "`**: For your own header files in the project

**Example:**
```c
#include <stdio.h>      // Standard library
#include <math.h>       // Standard library
#include "mylib.h"      // User-defined header
#include "helper.h"     // User-defined header
```

---

## LONG QUESTIONS

### 1. Define various file operations. Write a program to Count and print the number of characters in a file.

**Answer:**

**File Operations in C:**

1. **Opening a file** - `fopen()`
2. **Closing a file** - `fclose()`
3. **Reading from file** - `fgetc()`, `fgets()`, `fscanf()`, `fread()`
4. **Writing to file** - `fputc()`, `fputs()`, `fprintf()`, `fwrite()`
5. **Seeking** - `fseek()`, `ftell()`, `rewind()`
6. **Error handling** - `feof()`, `ferror()`

**File Opening Modes:**

| Mode | Description |
|------|-------------|
| `r` | Read only (file must exist) |
| `w` | Write only (creates new or overwrites) |
| `a` | Append (adds to end) |
| `r+` | Read and write (file must exist) |
| `w+` | Read and write (creates new or overwrites) |
| `a+` | Read and append |

**Program to count characters in a file:**

See `count_characters.c` for implementation.

---

### 2. What is dynamic memory allocation? Explain the Calloc, malloc(), free(), realloc() functions in details.

**Answer:**

**Dynamic Memory Allocation:**

Dynamic memory allocation is the process of allocating memory at runtime (during program execution) rather than at compile time. Memory is allocated from the heap.

**Advantages:**
- Flexible memory usage
- Memory allocated as per requirement
- Can be resized
- Efficient memory utilization

**Functions:**

#### 1. `malloc()` - Memory Allocation

**Syntax:**
```c
void* malloc(size_t size);
```

**Description:**
- Allocates specified number of bytes
- Returns pointer to first byte
- Memory contains garbage values
- Returns NULL if allocation fails

**Example:**
```c
int *ptr = (int*)malloc(5 * sizeof(int));
if(ptr == NULL) {
    printf("Memory allocation failed\n");
}
```

#### 2. `calloc()` - Contiguous Allocation

**Syntax:**
```c
void* calloc(size_t n, size_t size);
```

**Description:**
- Allocates memory for n elements of given size
- Initializes all bytes to zero
- Returns pointer to first byte
- Returns NULL if allocation fails

**Example:**
```c
int *ptr = (int*)calloc(5, sizeof(int));
// All 5 integers initialized to 0
```

**Difference between malloc() and calloc():**

| malloc() | calloc() |
|----------|----------|
| Takes 1 argument | Takes 2 arguments |
| Doesn't initialize | Initializes to zero |
| Faster | Slower (due to initialization) |
| `malloc(n*sizeof(int))` | `calloc(n, sizeof(int))` |

#### 3. `free()` - Deallocate Memory

**Syntax:**
```c
void free(void* ptr);
```

**Description:**
- Frees previously allocated memory
- Prevents memory leaks
- Pointer should be set to NULL after freeing

**Example:**
```c
int *ptr = (int*)malloc(5 * sizeof(int));
// Use the memory
free(ptr);
ptr = NULL;  // Good practice
```

#### 4. `realloc()` - Reallocate Memory

**Syntax:**
```c
void* realloc(void* ptr, size_t new_size);
```

**Description:**
- Changes size of previously allocated memory
- Can increase or decrease size
- Preserves existing data
- May move memory to new location
- Returns NULL if reallocation fails

**Example:**
```c
int *ptr = (int*)malloc(5 * sizeof(int));
// Need more space
ptr = (int*)realloc(ptr, 10 * sizeof(int));
```

**Memory Leak Prevention:**
Always free dynamically allocated memory to prevent memory leaks.

---

### 7. What do you mean by macro? What are application of macros? Explain types of macro with suitable examples in C.

**Answer:**

**Macro:**

A macro is a fragment of code that has been given a name. When the name is used, it is replaced by the contents of the macro by the preprocessor.

**Syntax:**
```c
#define MACRO_NAME replacement_text
```

**Characteristics:**
- Processed by preprocessor before compilation
- Simple text replacement
- No type checking
- No memory allocation
- Faster than functions (no function call overhead)

**Applications of Macros:**

1. **Define Constants**
   ```c
   #define PI 3.14159
   #define MAX_SIZE 100
   ```

2. **Code Readability**
   ```c
   #define SQUARE(x) ((x)*(x))
   ```

3. **Conditional Compilation**
   ```c
   #ifdef DEBUG
       printf("Debug mode\n");
   #endif
   ```

4. **Platform Independence**
   ```c
   #ifdef WINDOWS
       // Windows specific code
   #else
       // Linux specific code
   #endif
   ```

5. **Code Optimization**
   - Avoids function call overhead
   - Inline expansion

**Types of Macros:**

#### 1. Object-like Macros (Simple Macros)

Defines constants or simple replacements.

**Examples:**
```c
#define PI 3.14159
#define MAX 100
#define TRUE 1
#define FALSE 0
#define NEWLINE '\n'
```

**Usage:**
```c
float area = PI * r * r;
int arr[MAX];
```

#### 2. Function-like Macros (Parameterized Macros)

Takes arguments like functions.

**Examples:**
```c
#define SQUARE(x) ((x)*(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define ISEVEN(n) ((n)%2==0)
```

**Usage:**
```c
int result = SQUARE(5);        // Expands to ((5)*(5))
int maximum = MAX(10, 20);     // Expands to ((10)>(20)?(10):(20))
```

**Important: Use parentheses to avoid precedence issues**

**Wrong:**
```c
#define SQUARE(x) x*x
int result = SQUARE(2+3);  // Expands to 2+3*2+3 = 11 (Wrong!)
```

**Correct:**
```c
#define SQUARE(x) ((x)*(x))
int result = SQUARE(2+3);  // Expands to ((2+3)*(2+3)) = 25 (Correct!)
```

#### 3. Chain Macros

One macro uses another macro.

**Example:**
```c
#define PI 3.14159
#define CIRCLE_AREA(r) (PI*(r)*(r))
```

#### 4. Multi-line Macros

Uses backslash `\` for continuation.

**Example:**
```c
#define PRINT_ARRAY(arr, n) \
    do { \
        for(int i=0; i<n; i++) { \
            printf("%d ", arr[i]); \
        } \
        printf("\n"); \
    } while(0)
```

**Predefined Macros in C:**

| Macro | Description |
|-------|-------------|
| `__DATE__` | Current date (MMM DD YYYY) |
| `__TIME__` | Current time (HH:MM:SS) |
| `__FILE__` | Current file name |
| `__LINE__` | Current line number |
| `__STDC__` | 1 if compiler follows ANSI C |

**Example:**
```c
printf("File: %s\n", __FILE__);
printf("Line: %d\n", __LINE__);
printf("Date: %s\n", __DATE__);
printf("Time: %s\n", __TIME__);
```

**Macros vs Functions:**

| Macros | Functions |
|--------|-----------|
| Preprocessor replacement | Actual function call |
| No type checking | Type checking |
| Faster (no overhead) | Slower (function call overhead) |
| Code size increases | Code size remains same |
| No debugging | Can be debugged |
| `#define SQUARE(x) ((x)*(x))` | `int square(int x) { return x*x; }` |

**Advantages of Macros:**
- Faster execution
- Type independent
- Can be used for constants

**Disadvantages of Macros:**
- No type checking
- Difficult to debug
- Can cause side effects
- Increases code size

---

## Summary

This assignment covers fundamental concepts of C programming including:
- Data structures (Linked Lists)
- File handling and preprocessing
- Memory management (Static vs Dynamic)
- Pointer operations
- Macros and their applications

All concepts are explained with examples suitable for AKTU examination standards.

---

**Prepared by:** Student  
**Date:** December 3, 2025  
**Submission Deadline:** December 15, 2025
