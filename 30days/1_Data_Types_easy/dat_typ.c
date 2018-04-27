#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    
    // Declare second integer, double, and String variables.
    int j=0; double e=0.0; char *str= malloc(sizeof(char)*1024);
    // Read and save an integer, double, and String to your variables.
    scanf("%d", &j);
    scanf("%lf\n", &e);
    fgets(str, 1024, stdin);
    // Print the sum of both integer variables on a new line.
    printf("%d", i+j);
    // Print the sum of the double variables on a new line.
    printf("\n%.1lf", d+e);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    printf("\n%s%s", s, str);

	return 0;
}
