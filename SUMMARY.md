# AKTU Assignment 5 - Quick Summary

## 📋 Assignment Overview

**Course:** Programming for Problem Solving (PPS)  
**Instructor:** Mr. Ravi Kumar  
**Deadline:** 15th December, 2025  
**Total Questions:** 9 (6 Short + 3 Long)

---

## ✅ Completed Files

| # | File Name | Purpose | Question |
|---|-----------|---------|----------|
| 1 | `aktu_assignment_answers.md` | All written answers | All questions |
| 2 | `count_characters.c` | File operations demo | Long Q1 |
| 3 | `dynamic_memory_demo.c` | Memory allocation demo | Long Q2 |
| 4 | `macro_demonstration.c` | Macro types demo | Long Q7 |
| 5 | `linked_list_demo.c` | Linked list demo | Short Q1 |
| 6 | `pointer_arithmetic_demo.c` | Pointer operations demo | Short Q4 |
| 7 | `README.md` | Complete documentation | - |
| 8 | `test.txt` | Sample file for testing | - |

---

## 📝 Questions & Answers Summary

### SHORT QUESTIONS

#### Q1: What is linked list? Write the self-referential structure.
**Answer:** Linked list is a linear data structure with nodes containing data and pointer to next node.
```c
struct Node {
    int data;
    struct Node* next;
};
```
**Program:** `linked_list_demo.c`

---

#### Q2: What are Header files? Why are they important?
**Answer:** Files with `.h` extension containing function declarations, macros, and structures.
**Importance:**
- Code reusability
- Modularity
- Access to standard library functions
- Avoid redundancy

---

#### Q3: Explain the role of C pre-processor.
**Answer:** Processes source code before compilation.
**Main roles:**
1. File inclusion (`#include`)
2. Macro definition (`#define`)
3. Conditional compilation (`#ifdef`, `#ifndef`)
4. Macro expansion

---

#### Q4: What do you mean by pointer arithmetic?
**Answer:** Performing arithmetic operations on pointers.
**Operations:**
- Increment (`++`), Decrement (`--`)
- Addition (`+`), Subtraction (`-`)
- Comparison (`<`, `>`, `==`)

**Program:** `pointer_arithmetic_demo.c`

---

#### Q5: Difference between static and dynamic memory allocation.

| Static | Dynamic |
|--------|---------|
| Compile time | Runtime |
| Stack | Heap |
| Fixed size | Flexible size |
| Automatic | Manual (malloc/free) |
| `int arr[10];` | `int *arr = malloc(10*sizeof(int));` |

---

#### Q6: Difference between `#include <file.h>` and `#include "file.h"`

| `<file.h>` | `"file.h"` |
|------------|------------|
| System directories | Current directory first |
| Standard library | User-defined headers |
| `#include <stdio.h>` | `#include "myheader.h"` |

---

### LONG QUESTIONS

#### Q1: File operations + Program to count characters
**Answer:** File operations include:
- Opening (`fopen`)
- Closing (`fclose`)
- Reading (`fgetc`, `fgets`, `fscanf`)
- Writing (`fputc`, `fputs`, `fprintf`)
- Seeking (`fseek`, `ftell`)

**Program:** `count_characters.c`
- Opens file in read mode
- Counts characters using `fgetc()`
- Displays total count

---

#### Q2: Dynamic memory allocation - malloc, calloc, realloc, free
**Answer:**

**malloc()** - Allocates memory with garbage values
```c
int *ptr = (int*)malloc(n * sizeof(int));
```

**calloc()** - Allocates and initializes to 0
```c
int *ptr = (int*)calloc(n, sizeof(int));
```

**realloc()** - Changes size of allocated memory
```c
ptr = (int*)realloc(ptr, new_size * sizeof(int));
```

**free()** - Deallocates memory
```c
free(ptr);
```

**Program:** `dynamic_memory_demo.c`
- Interactive demonstrations
- Compares malloc vs calloc
- Shows realloc functionality

---

#### Q7: Macros - types and applications
**Answer:**

**Types of Macros:**

1. **Object-like (Simple)**
```c
#define PI 3.14159
#define MAX 100
```

2. **Function-like (Parameterized)**
```c
#define SQUARE(x) ((x)*(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
```

3. **Chain Macros**
```c
#define PI 3.14159
#define CIRCLE_AREA(r) (PI*(r)*(r))
```

4. **Multi-line Macros**
```c
#define SWAP(a,b,type) \
    do { \
        type temp = a; \
        a = b; \
        b = temp; \
    } while(0)
```

**Applications:**
- Define constants
- Code readability
- Conditional compilation
- Platform independence
- Performance optimization

**Program:** `macro_demonstration.c`
- Shows all macro types
- Predefined macros
- Practical applications

---

## 🚀 Quick Start Guide

### Compile Any Program:
```bash
gcc filename.c -o filename
filename.exe
```

### Test File Operations:
```bash
gcc count_characters.c -o count_characters
count_characters.exe
# Enter: test.txt
```

### Test Dynamic Memory:
```bash
gcc dynamic_memory_demo.c -o dynamic_memory_demo
dynamic_memory_demo.exe
# Choose option from menu
```

### Test Macros:
```bash
gcc macro_demonstration.c -o macro_demonstration
macro_demonstration.exe
# Choose option from menu
```

### Test Linked List:
```bash
gcc linked_list_demo.c -o linked_list_demo
linked_list_demo.exe
# Choose operations from menu
```

### Test Pointer Arithmetic:
```bash
gcc pointer_arithmetic_demo.c -o pointer_arithmetic_demo
pointer_arithmetic_demo.exe
# Choose demonstration type
```

---

## 📊 Program Statistics

| Program | Lines of Code | Features |
|---------|---------------|----------|
| count_characters.c | ~60 | File I/O, Error handling |
| dynamic_memory_demo.c | ~250 | 4 functions, Menu-driven |
| macro_demonstration.c | ~350 | 6 demos, All macro types |
| linked_list_demo.c | ~200 | Insert, Delete, Display |
| pointer_arithmetic_demo.c | ~250 | 5 demos, All data types |

**Total:** ~1100 lines of well-commented, AKTU-standard code

---

## 💡 Key Takeaways

### For Exams:
1. **Linked List** - Remember self-referential structure
2. **File Operations** - Know all modes (r, w, a, r+, w+, a+)
3. **Dynamic Memory** - malloc vs calloc differences
4. **Pointer Arithmetic** - Size-based movement
5. **Macros** - Always use parentheses in function-like macros

### Common Mistakes:
- ❌ Forgetting to `free()` allocated memory
- ❌ Not checking if `malloc()` returned NULL
- ❌ Missing parentheses in macros
- ❌ Wrong file mode selection
- ❌ Incorrect pointer arithmetic

### Best Practices:
- ✅ Always initialize pointers
- ✅ Check return values
- ✅ Free allocated memory
- ✅ Use meaningful variable names
- ✅ Add comments for clarity

---

## 📚 Study Plan

### Day 1-2: Theory
- Read `aktu_assignment_answers.md`
- Understand concepts
- Make notes

### Day 3-4: Programs
- Run all programs
- Understand code flow
- Modify and experiment

### Day 5-6: Practice
- Write programs from scratch
- Solve variations
- Test different inputs

### Day 7: Revision
- Review all concepts
- Practice writing answers
- Prepare for submission

---

## ✅ Submission Checklist

Before submitting on 15th December:

- [ ] All 6 short questions answered
- [ ] All 3 long questions answered
- [ ] All 5 programs tested and working
- [ ] Code properly commented
- [ ] Output verified
- [ ] Name and roll number added
- [ ] Proper formatting
- [ ] Printed/PDF ready

---

## 🎯 Expected Marks Distribution

| Question Type | Marks Each | Total |
|---------------|------------|-------|
| Short Q (6) | 2-3 marks | 12-18 marks |
| Long Q (3) | 7-10 marks | 21-30 marks |
| **Total** | | **33-48 marks** |

---

## 📞 Need Help?

### If Program Doesn't Compile:
1. Check GCC is installed: `gcc --version`
2. Check file path is correct
3. Look for syntax errors
4. Check all semicolons and braces

### If Program Crashes:
1. Check for NULL pointer access
2. Verify array bounds
3. Check if file exists (for file operations)
4. Add error handling

### Understanding Issues:
1. Read comments in code
2. Check `aktu_assignment_answers.md`
3. Run program step by step
4. Draw diagrams

---

## 🌟 Bonus Tips

1. **For Better Marks:**
   - Write neat code
   - Add meaningful comments
   - Show sample output
   - Explain logic

2. **Time Management:**
   - Short questions: 5-7 minutes each
   - Long questions: 15-20 minutes each
   - Programs: 20-25 minutes each

3. **Presentation:**
   - Use proper headings
   - Underline important points
   - Draw diagrams where needed
   - Write legibly

---

**All the Best! 🎓**

---

*Last Updated: December 3, 2025*  
*Assignment Status: ✅ Complete and Ready for Submission*
