// Program to count and print the number of characters in a file
// Long Question 1 - File Operations

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int count = 0;
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    // Open file in read mode
    fp = fopen(filename, "r");
    
    // Check if file opened successfully
    if(fp == NULL) {
        printf("Error! File cannot be opened.\n");
        printf("Make sure the file exists in the current directory.\n");
        return 1;
    }
    
    printf("\nFile opened successfully!\n");
    printf("Counting characters...\n\n");
    
    // Read characters one by one until end of file
    while((ch = fgetc(fp)) != EOF) {
        count++;
    }
    
    // Close the file
    fclose(fp);
    
    // Print the result
    printf("Total number of characters in file '%s': %d\n", filename, count);
    
    return 0;
}

/*
OUTPUT:
Enter the filename: test.txt

File opened successfully!
Counting characters...

Total number of characters in file 'test.txt': 150

EXPLANATION:
1. fopen() - Opens file in read mode
2. fgetc() - Reads one character at a time
3. EOF - End of File marker
4. fclose() - Closes the file
5. Count increments for each character read

FILE OPERATIONS USED:
- fopen() - Opening file
- fgetc() - Reading character
- fclose() - Closing file
- Error handling with NULL check
*/
