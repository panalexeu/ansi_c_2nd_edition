/*
 * This is a multi-line comment at the top
 * A simple program to calculate and display numbers
 * Created for testing comment removal tool
 */
#include <stdio.h>   // Standard input/output library
#include <stdlib.h>  // Standard library

// Function declaration
int add(int a, int b); // This function adds two numbers

/*
 * Main function - entry point of the program
 * This function demonstrates various operations
 */
int main() {
    // Variable declarations
    int x = 10; // First number
    int y = 20; // Second number
    int result; // Result variable

    // EDGE CASE: comment symbols inside a string literal -- must NOT be stripped
    char *s1 = "this // is not a comment";
    char *s2 = "neither /* is this */ a comment";
    char *s3 = "slashes and stars: //*/ stay put";

    // EDGE CASE: comment symbols inside a char literal -- must NOT be stripped
    char c1 = '/';
    char c2 = '*';

    // EDGE CASE: escaped quote inside a string, followed by comment symbols
    char *s4 = "he said \"// not a comment\" to me"; // this part IS a comment

    // Print welcome message
    printf("=== Simple Calculator Program ===\n");

    /* Call the add function and store result */
    result = add(x, y);

    // Display the result
    printf("Result of adding %d and %d: %d\n", x, y, result);

    // EDGE CASE: comment-like sequence inside printf string
    printf("URL: http://example.com /* keep this */\n");

    // Loop to print numbers from 1 to 5
    printf("\nNumbers from 1 to 5:\n");
    for (int i = 1; i <= 5; i++) { // Loop variable declaration with comment
        printf("%d ", i); // Print each number with a space
    }
    printf("\n");

    /*
     * Multi-line comment explaining the next section
     * We're going to calculate the square of x
     * and display it
     */
    int square = x * x; // Calculate square by multiplying x with itself
    printf("Square of %d is: %d\n", x, square);

    // Conditional statement
    if (result > 25) { // Check if sum is greater than 25
        printf("The sum is greater than 25\n"); // Print message
    } else { // If not greater than 25
        printf("The sum is 25 or less\n"); // Alternative message
    }

    // Return success code
    return 0; // Program ends successfully
}

// Function definition
// This function takes two integers and returns their sum
int add(int a, int b) { // Parameters: a and b
    int sum = a + b; // Calculate sum
    return sum; // Return the result
}

/*
 * End of file
 * This program is complete
 */
