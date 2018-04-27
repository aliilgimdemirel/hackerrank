#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(char *a, char *b)
{
	// check for NULL strings
	if (!a) { printf("ERROR\n");}
	if (!b) { printf("ERROR\n");}

	int cmp_result = strcmp(a,b);
	
	// less then
	if(cmp_result == 1) { return 1;} 
	// equal to
	else if(cmp_result == 0) { return 0; }
	// greater than
	else { return -1; }	
}


int main ()
{
	int	cmp_res = 0;
	char *a = "abcdef";	
	char *b = "abcdeg";	
	cmp_res = compare_strings(a,b);
	
	printf("%d\n", cmp_res);
	


	return 0;
}

/*
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}
*/
