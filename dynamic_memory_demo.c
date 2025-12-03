// Demonstration of Dynamic Memory Allocation Functions
// Long Question 2 - malloc(), calloc(), realloc(), free()

#include <stdio.h>
#include <stdlib.h>

void demonstrateMalloc();
void demonstrateCalloc();
void demonstrateRealloc();
void compareMallocCalloc();

int main() {
    int choice;
    
    printf("=== Dynamic Memory Allocation Demonstration ===\n\n");
    printf("1. malloc() demonstration\n");
    printf("2. calloc() demonstration\n");
    printf("3. realloc() demonstration\n");
    printf("4. Compare malloc() and calloc()\n");
    printf("5. All demonstrations\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            demonstrateMalloc();
            break;
        case 2:
            demonstrateCalloc();
            break;
        case 3:
            demonstrateRealloc();
            break;
        case 4:
            compareMallocCalloc();
            break;
        case 5:
            demonstrateMalloc();
            printf("\n");
            demonstrateCalloc();
            printf("\n");
            demonstrateRealloc();
            printf("\n");
            compareMallocCalloc();
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

// Demonstrate malloc()
void demonstrateMalloc() {
    int n, i;
    int *ptr;
    
    printf("\n--- malloc() Demonstration ---\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory using malloc
    ptr = (int*)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Memory allocated successfully using malloc()\n");
    printf("Memory contains garbage values:\n");
    
    // Display garbage values
    for(i = 0; i < n; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    // Initialize values
    printf("\nEnter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }
    
    // Display values
    printf("\nElements entered:\n");
    for(i = 0; i < n; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    // Free the memory
    free(ptr);
    printf("\nMemory freed successfully!\n");
}

// Demonstrate calloc()
void demonstrateCalloc() {
    int n, i;
    int *ptr;
    
    printf("\n--- calloc() Demonstration ---\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory using calloc
    ptr = (int*)calloc(n, sizeof(int));
    
    // Check if memory allocation was successful
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Memory allocated successfully using calloc()\n");
    printf("Memory initialized to zero:\n");
    
    // Display initialized values (all zeros)
    for(i = 0; i < n; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    // Assign values
    printf("\nEnter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }
    
    // Display values
    printf("\nElements entered:\n");
    for(i = 0; i < n; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    // Free the memory
    free(ptr);
    printf("\nMemory freed successfully!\n");
}

// Demonstrate realloc()
void demonstrateRealloc() {
    int n, new_n, i;
    int *ptr;
    
    printf("\n--- realloc() Demonstration ---\n");
    printf("Enter initial number of elements: ");
    scanf("%d", &n);
    
    // Initial allocation using malloc
    ptr = (int*)malloc(n * sizeof(int));
    
    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Memory allocated for %d elements\n", n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }
    
    printf("\nOriginal elements:\n");
    for(i = 0; i < n; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    // Reallocate memory
    printf("\nEnter new size: ");
    scanf("%d", &new_n);
    
    ptr = (int*)realloc(ptr, new_n * sizeof(int));
    
    if(ptr == NULL) {
        printf("Reallocation failed!\n");
        return;
    }
    
    printf("Memory reallocated for %d elements\n", new_n);
    
    // If size increased, enter new elements
    if(new_n > n) {
        printf("Enter %d more elements:\n", new_n - n);
        for(i = n; i < new_n; i++) {
            scanf("%d", &ptr[i]);
        }
    }
    
    // Display all elements
    printf("\nAll elements after reallocation:\n");
    for(i = 0; i < new_n; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    // Free the memory
    free(ptr);
    printf("\nMemory freed successfully!\n");
}

// Compare malloc() and calloc()
void compareMallocCalloc() {
    int n = 5, i;
    int *ptr1, *ptr2;
    
    printf("\n--- Comparing malloc() and calloc() ---\n");
    
    // Allocate using malloc
    ptr1 = (int*)malloc(n * sizeof(int));
    
    // Allocate using calloc
    ptr2 = (int*)calloc(n, sizeof(int));
    
    printf("\nValues after malloc() (garbage values):\n");
    for(i = 0; i < n; i++) {
        printf("ptr1[%d] = %d\n", i, ptr1[i]);
    }
    
    printf("\nValues after calloc() (initialized to 0):\n");
    for(i = 0; i < n; i++) {
        printf("ptr2[%d] = %d\n", i, ptr2[i]);
    }
    
    // Free both
    free(ptr1);
    free(ptr2);
    
    printf("\nKey Differences:\n");
    printf("1. malloc() - Contains garbage values\n");
    printf("2. calloc() - Initialized to zero\n");
    printf("3. malloc() - Takes 1 argument\n");
    printf("4. calloc() - Takes 2 arguments\n");
}

/*
OUTPUT SAMPLE:

=== Dynamic Memory Allocation Demonstration ===

1. malloc() demonstration
2. calloc() demonstration
3. realloc() demonstration
4. Compare malloc() and calloc()
5. All demonstrations

Enter your choice: 1

--- malloc() Demonstration ---
Enter number of elements: 3
Memory allocated successfully using malloc()
Memory contains garbage values:
ptr[0] = 32767
ptr[1] = 0
ptr[2] = 4196640

Enter 3 elements:
10
20
30

Elements entered:
ptr[0] = 10
ptr[1] = 20
ptr[2] = 30

Memory freed successfully!

EXPLANATION:
1. malloc(size) - Allocates 'size' bytes, returns void pointer
2. calloc(n, size) - Allocates n*size bytes, initializes to 0
3. realloc(ptr, new_size) - Changes size of allocated memory
4. free(ptr) - Deallocates memory
5. Always check if allocation was successful (ptr != NULL)
6. Always free allocated memory to prevent memory leaks
*/
