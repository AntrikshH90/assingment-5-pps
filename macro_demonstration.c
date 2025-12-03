// Demonstration of Macros in C
// Long Question 7 - Types of Macros with Examples

#include <stdio.h>

// ========== OBJECT-LIKE MACROS (Simple Macros) ==========
#define PI 3.14159
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define NEWLINE '\n'
#define COLLEGE_NAME "AKTU"

// ========== FUNCTION-LIKE MACROS (Parameterized Macros) ==========
#define SQUARE(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define ISEVEN(n) ((n)%2==0)
#define ISODD(n) ((n)%2!=0)

// ========== CHAIN MACROS ==========
#define RADIUS 5
#define CIRCLE_AREA(r) (PI*(r)*(r))
#define CIRCLE_CIRCUMFERENCE(r) (2*PI*(r))

// ========== MULTI-LINE MACROS ==========
#define PRINT_ARRAY(arr, n) \
    do { \
        printf("Array elements: "); \
        for(int i=0; i<n; i++) { \
            printf("%d ", arr[i]); \
        } \
        printf("\n"); \
    } while(0)

#define SWAP(a, b, type) \
    do { \
        type temp = a; \
        a = b; \
        b = temp; \
    } while(0)

// Function prototypes
void demonstrateObjectMacros();
void demonstrateFunctionMacros();
void demonstrateChainMacros();
void demonstrateMultiLineMacros();
void demonstratePredefinedMacros();
void demonstrateMacroApplications();

int main() {
    int choice;
    
    printf("========================================\n");
    printf("   MACRO DEMONSTRATION PROGRAM\n");
    printf("========================================\n\n");
    
    printf("1. Object-like Macros (Simple Macros)\n");
    printf("2. Function-like Macros (Parameterized)\n");
    printf("3. Chain Macros\n");
    printf("4. Multi-line Macros\n");
    printf("5. Predefined Macros\n");
    printf("6. Macro Applications\n");
    printf("7. All Demonstrations\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    printf("\n");
    
    switch(choice) {
        case 1:
            demonstrateObjectMacros();
            break;
        case 2:
            demonstrateFunctionMacros();
            break;
        case 3:
            demonstrateChainMacros();
            break;
        case 4:
            demonstrateMultiLineMacros();
            break;
        case 5:
            demonstratePredefinedMacros();
            break;
        case 6:
            demonstrateMacroApplications();
            break;
        case 7:
            demonstrateObjectMacros();
            printf("\n");
            demonstrateFunctionMacros();
            printf("\n");
            demonstrateChainMacros();
            printf("\n");
            demonstrateMultiLineMacros();
            printf("\n");
            demonstratePredefinedMacros();
            printf("\n");
            demonstrateMacroApplications();
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}

// Demonstrate Object-like Macros
void demonstrateObjectMacros() {
    printf("========== OBJECT-LIKE MACROS ==========\n");
    printf("These are simple constant definitions\n\n");
    
    printf("PI = %f\n", PI);
    printf("MAX_SIZE = %d\n", MAX_SIZE);
    printf("TRUE = %d\n", TRUE);
    printf("FALSE = %d\n", FALSE);
    printf("COLLEGE_NAME = %s\n", COLLEGE_NAME);
    
    // Using in calculations
    float radius = 7.0;
    float area = PI * radius * radius;
    printf("\nArea of circle with radius %.2f = %.2f\n", radius, area);
    
    // Using in array declaration
    int arr[MAX_SIZE];
    printf("Array of size %d created successfully\n", MAX_SIZE);
    
    printf("\nAdvantage: Easy to maintain and modify constants\n");
}

// Demonstrate Function-like Macros
void demonstrateFunctionMacros() {
    printf("========== FUNCTION-LIKE MACROS ==========\n");
    printf("These take parameters like functions\n\n");
    
    int a = 5, b = 10;
    
    printf("a = %d, b = %d\n\n", a, b);
    
    printf("SQUARE(%d) = %d\n", a, SQUARE(a));
    printf("CUBE(%d) = %d\n", a, CUBE(a));
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    
    int negative = -15;
    printf("\nABS(%d) = %d\n", negative, ABS(negative));
    
    int num = 8;
    printf("\nISEVEN(%d) = %d (1=True, 0=False)\n", num, ISEVEN(num));
    printf("ISODD(%d) = %d (1=True, 0=False)\n", num, ISODD(num));
    
    // Demonstrating importance of parentheses
    printf("\n--- Importance of Parentheses ---\n");
    printf("SQUARE(2+3) = %d (Correct due to parentheses)\n", SQUARE(2+3));
    printf("Without parentheses it would be: 2+3*2+3 = 11 (Wrong!)\n");
    
    printf("\nAdvantage: No function call overhead, faster execution\n");
}

// Demonstrate Chain Macros
void demonstrateChainMacros() {
    printf("========== CHAIN MACROS ==========\n");
    printf("One macro uses another macro\n\n");
    
    printf("RADIUS = %d (defined using macro)\n", RADIUS);
    printf("PI = %f (defined using macro)\n\n", PI);
    
    printf("CIRCLE_AREA(%d) = %.2f\n", RADIUS, CIRCLE_AREA(RADIUS));
    printf("CIRCLE_CIRCUMFERENCE(%d) = %.2f\n", RADIUS, CIRCLE_CIRCUMFERENCE(RADIUS));
    
    int r = 10;
    printf("\nFor radius = %d:\n", r);
    printf("Area = %.2f\n", CIRCLE_AREA(r));
    printf("Circumference = %.2f\n", CIRCLE_CIRCUMFERENCE(r));
    
    printf("\nAdvantage: Reusability and modularity\n");
}

// Demonstrate Multi-line Macros
void demonstrateMultiLineMacros() {
    printf("========== MULTI-LINE MACROS ==========\n");
    printf("Macros spanning multiple lines using backslash\n\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    printf("Using PRINT_ARRAY macro:\n");
    PRINT_ARRAY(numbers, size);
    
    printf("\nUsing SWAP macro:\n");
    int x = 100, y = 200;
    printf("Before swap: x = %d, y = %d\n", x, y);
    SWAP(x, y, int);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    printf("\nAdvantage: Complex operations in a single macro\n");
}

// Demonstrate Predefined Macros
void demonstratePredefinedMacros() {
    printf("========== PREDEFINED MACROS ==========\n");
    printf("Built-in macros provided by C compiler\n\n");
    
    printf("__FILE__ = %s\n", __FILE__);
    printf("__LINE__ = %d\n", __LINE__);
    printf("__DATE__ = %s\n", __DATE__);
    printf("__TIME__ = %s\n", __TIME__);
    
    #ifdef __STDC__
        printf("__STDC__ = %d (Compiler follows ANSI C)\n", __STDC__);
    #endif
    
    printf("\nThese macros are useful for:\n");
    printf("- Debugging (file name, line number)\n");
    printf("- Logging (date, time)\n");
    printf("- Conditional compilation\n");
}

// Demonstrate Macro Applications
void demonstrateMacroApplications() {
    printf("========== MACRO APPLICATIONS ==========\n\n");
    
    printf("1. DEFINING CONSTANTS:\n");
    printf("   #define PI 3.14159\n");
    printf("   #define MAX 100\n\n");
    
    printf("2. CODE READABILITY:\n");
    printf("   #define SQUARE(x) ((x)*(x))\n");
    printf("   Instead of: result = num * num\n");
    printf("   Use: result = SQUARE(num)\n\n");
    
    printf("3. CONDITIONAL COMPILATION:\n");
    printf("   #ifdef DEBUG\n");
    printf("       printf(\"Debug mode\");\n");
    printf("   #endif\n\n");
    
    printf("4. PLATFORM INDEPENDENCE:\n");
    printf("   #ifdef WINDOWS\n");
    printf("       // Windows code\n");
    printf("   #else\n");
    printf("       // Linux code\n");
    printf("   #endif\n\n");
    
    printf("5. PERFORMANCE OPTIMIZATION:\n");
    printf("   Macros avoid function call overhead\n");
    printf("   Faster than regular functions\n\n");
    
    printf("6. TYPE-INDEPENDENT CODE:\n");
    printf("   #define MAX(a,b) ((a)>(b)?(a):(b))\n");
    printf("   Works with int, float, double, etc.\n\n");
    
    // Practical example
    printf("--- PRACTICAL EXAMPLE ---\n");
    int marks = 75;
    
    #define PASS_MARKS 40
    #define GRADE_A 80
    #define GRADE_B 60
    #define GRADE_C 40
    
    printf("Student Marks: %d\n", marks);
    
    if(marks >= GRADE_A) {
        printf("Grade: A\n");
    } else if(marks >= GRADE_B) {
        printf("Grade: B\n");
    } else if(marks >= GRADE_C) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F (Fail)\n");
    }
}

/*
========================================
SAMPLE OUTPUT:
========================================

========================================
   MACRO DEMONSTRATION PROGRAM
========================================

1. Object-like Macros (Simple Macros)
2. Function-like Macros (Parameterized)
3. Chain Macros
4. Multi-line Macros
5. Predefined Macros
6. Macro Applications
7. All Demonstrations

Enter your choice: 2

========== FUNCTION-LIKE MACROS ==========
These take parameters like functions

a = 5, b = 10

SQUARE(5) = 25
CUBE(5) = 125
MAX(5, 10) = 10
MIN(5, 10) = 5

ABS(-15) = 15

ISEVEN(8) = 1 (1=True, 0=False)
ISODD(8) = 0 (1=True, 0=False)

--- Importance of Parentheses ---
SQUARE(2+3) = 25 (Correct due to parentheses)
Without parentheses it would be: 2+3*2+3 = 11 (Wrong!)

Advantage: No function call overhead, faster execution

========================================
KEY POINTS:
========================================

1. TYPES OF MACROS:
   - Object-like (Simple constants)
   - Function-like (With parameters)
   - Chain macros (Using other macros)
   - Multi-line macros (Using backslash)
   - Predefined macros (Built-in)

2. ADVANTAGES:
   - Faster execution (no function call)
   - Type independent
   - Code reusability
   - Easy maintenance

3. DISADVANTAGES:
   - No type checking
   - Difficult to debug
   - Can cause side effects
   - Increases code size

4. BEST PRACTICES:
   - Always use parentheses in function-like macros
   - Use uppercase for macro names
   - Use do-while(0) for multi-line macros
   - Be careful with side effects

5. MACROS vs FUNCTIONS:
   - Macros: Preprocessor replacement, faster, no type check
   - Functions: Actual call, slower, type checking

========================================
*/
