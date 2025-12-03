// Demonstration of Pointer Arithmetic
// Short Question 4

#include <stdio.h>

void demonstrateIntPointer();
void demonstrateCharPointer();
void demonstrateFloatPointer();
void demonstrateArrayPointer();
void demonstratePointerComparison();

int main() {
    int choice;
    
    printf("========================================\n");
    printf("   POINTER ARITHMETIC DEMONSTRATION\n");
    printf("========================================\n\n");
    
    printf("1. Integer Pointer Arithmetic\n");
    printf("2. Character Pointer Arithmetic\n");
    printf("3. Float Pointer Arithmetic\n");
    printf("4. Array and Pointer Arithmetic\n");
    printf("5. Pointer Comparison\n");
    printf("6. All Demonstrations\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    printf("\n");
    
    switch(choice) {
        case 1:
            demonstrateIntPointer();
            break;
        case 2:
            demonstrateCharPointer();
            break;
        case 3:
            demonstrateFloatPointer();
            break;
        case 4:
            demonstrateArrayPointer();
            break;
        case 5:
            demonstratePointerComparison();
            break;
        case 6:
            demonstrateIntPointer();
            printf("\n");
            demonstrateCharPointer();
            printf("\n");
            demonstrateFloatPointer();
            printf("\n");
            demonstrateArrayPointer();
            printf("\n");
            demonstratePointerComparison();
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

void demonstrateIntPointer() {
    printf("========== INTEGER POINTER ARITHMETIC ==========\n");
    
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // Points to first element
    
    printf("Array: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    printf("Initial pointer value (address): %p\n", (void*)ptr);
    printf("Value at pointer: %d\n\n", *ptr);
    
    // Increment
    printf("After ptr++:\n");
    ptr++;
    printf("Pointer value: %p\n", (void*)ptr);
    printf("Value at pointer: %d\n", *ptr);
    printf("Moved by %zu bytes (size of int)\n\n", sizeof(int));
    
    // Addition
    printf("After ptr = ptr + 2:\n");
    ptr = ptr + 2;
    printf("Pointer value: %p\n", (void*)ptr);
    printf("Value at pointer: %d\n", *ptr);
    printf("Moved by %zu bytes (2 * size of int)\n\n", 2*sizeof(int));
    
    // Decrement
    printf("After ptr--:\n");
    ptr--;
    printf("Pointer value: %p\n", (void*)ptr);
    printf("Value at pointer: %d\n", *ptr);
    
    printf("\nKey Point: Integer pointer moves by 4 bytes (size of int)\n");
}

void demonstrateCharPointer() {
    printf("========== CHARACTER POINTER ARITHMETIC ==========\n");
    
    char str[] = "AKTU";
    char *ptr = str;
    
    printf("String: %s\n\n", str);
    
    printf("Initial pointer value: %p\n", (void*)ptr);
    printf("Character at pointer: %c\n\n", *ptr);
    
    printf("Traversing string using pointer arithmetic:\n");
    while(*ptr != '\0') {
        printf("Address: %p, Character: %c\n", (void*)ptr, *ptr);
        ptr++;  // Moves by 1 byte
    }
    
    printf("\nKey Point: Character pointer moves by 1 byte (size of char)\n");
}

void demonstrateFloatPointer() {
    printf("========== FLOAT POINTER ARITHMETIC ==========\n");
    
    float arr[4] = {1.5, 2.5, 3.5, 4.5};
    float *ptr = arr;
    
    printf("Array: ");
    for(int i = 0; i < 4; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n\n");
    
    printf("Initial pointer value: %p\n", (void*)ptr);
    printf("Value at pointer: %.1f\n\n", *ptr);
    
    printf("After ptr++:\n");
    ptr++;
    printf("Pointer value: %p\n", (void*)ptr);
    printf("Value at pointer: %.1f\n", *ptr);
    printf("Moved by %zu bytes (size of float)\n", sizeof(float));
    
    printf("\nKey Point: Float pointer moves by 4 bytes (size of float)\n");
}

void demonstrateArrayPointer() {
    printf("========== ARRAY AND POINTER ARITHMETIC ==========\n");
    
    int arr[5] = {100, 200, 300, 400, 500};
    int *ptr = arr;
    
    printf("Array elements using pointer arithmetic:\n\n");
    
    printf("Method 1: Using pointer increment\n");
    for(int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (Address: %p)\n", i, *(ptr + i), (void*)(ptr + i));
    }
    
    printf("\nMethod 2: Using array notation with pointer\n");
    for(int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    printf("\nRelationship:\n");
    printf("arr[i] = *(arr + i) = *(ptr + i) = ptr[i]\n");
    printf("&arr[i] = (arr + i) = (ptr + i)\n");
}

void demonstratePointerComparison() {
    printf("========== POINTER COMPARISON ==========\n");
    
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[3];
    
    printf("ptr1 points to arr[1] = %d\n", *ptr1);
    printf("ptr2 points to arr[3] = %d\n\n", *ptr2);
    
    // Comparison
    if(ptr1 < ptr2) {
        printf("ptr1 < ptr2 (ptr1 comes before ptr2 in memory)\n");
    }
    
    if(ptr2 > ptr1) {
        printf("ptr2 > ptr1 (ptr2 comes after ptr1 in memory)\n");
    }
    
    // Subtraction
    printf("\nptr2 - ptr1 = %ld (number of elements between them)\n", ptr2 - ptr1);
    
    printf("\nValid Operations:\n");
    printf("1. ptr++ (Increment)\n");
    printf("2. ptr-- (Decrement)\n");
    printf("3. ptr + n (Addition)\n");
    printf("4. ptr - n (Subtraction)\n");
    printf("5. ptr1 - ptr2 (Difference)\n");
    printf("6. ptr1 < ptr2, ptr1 > ptr2 (Comparison)\n");
    
    printf("\nInvalid Operations:\n");
    printf("1. ptr1 + ptr2 (Cannot add two pointers)\n");
    printf("2. ptr1 * ptr2 (Cannot multiply pointers)\n");
    printf("3. ptr1 / ptr2 (Cannot divide pointers)\n");
}

/*
OUTPUT SAMPLE:

========================================
   POINTER ARITHMETIC DEMONSTRATION
========================================

1. Integer Pointer Arithmetic
2. Character Pointer Arithmetic
3. Float Pointer Arithmetic
4. Array and Pointer Arithmetic
5. Pointer Comparison
6. All Demonstrations

Enter your choice: 1

========== INTEGER POINTER ARITHMETIC ==========
Array: 10 20 30 40 50 

Initial pointer value (address): 0x7ffd5c8e4a10
Value at pointer: 10

After ptr++:
Pointer value: 0x7ffd5c8e4a14
Value at pointer: 20
Moved by 4 bytes (size of int)

After ptr = ptr + 2:
Pointer value: 0x7ffd5c8e4a1c
Value at pointer: 40
Moved by 8 bytes (2 * size of int)

After ptr--:
Pointer value: 0x7ffd5c8e4a18
Value at pointer: 30

Key Point: Integer pointer moves by 4 bytes (size of int)

EXPLANATION:

1. POINTER ARITHMETIC:
   When you perform arithmetic on pointers, the pointer
   moves by the size of the data type it points to.

2. SIZE MOVEMENT:
   - int* moves by 4 bytes (sizeof(int))
   - char* moves by 1 byte (sizeof(char))
   - float* moves by 4 bytes (sizeof(float))
   - double* moves by 8 bytes (sizeof(double))

3. OPERATIONS:
   ptr++     : Moves to next element
   ptr--     : Moves to previous element
   ptr + n   : Moves n elements forward
   ptr - n   : Moves n elements backward
   ptr1 - ptr2 : Number of elements between pointers

4. FORMULA:
   If ptr is at address A, then:
   ptr + n will be at address: A + (n * sizeof(datatype))

5. ARRAY-POINTER RELATIONSHIP:
   arr[i] is equivalent to *(arr + i)
   &arr[i] is equivalent to (arr + i)
*/
