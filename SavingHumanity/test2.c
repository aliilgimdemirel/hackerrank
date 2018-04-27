#include <sys/resource.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);
int validateInput(char* input, int input_length);

int findStringLength(char *str)
{
    int length = 0; 
    char *ptr_s = str;

    while (*ptr_s != '\0') {
        ptr_s++;
        length++;   
//      printf("char @index:%d is:%d\n",length, (int)*ptr_s);
    }

    return length;
}

int validateInput(char* input, int input_length)
{
    if (input_length > pow(10,5)) {
        printf("TOO BIG input!\n");
        return 1;
    }

    for(int i = 0; i < input_length; i++) {
        if( (int)input[i] < (int)'a' || (int)input[i] > (int)'z') {
            printf("inputs must be lowercase english letters!\n");
            return 1;
        }
    }

    return 0;
}





void virusIndices(char* p, char* v)
{
    /*
     * Print the answer for this test case in a single line
     */

		printf("DEBUG");
    char *ptr_p = p;
    char *ptr_v = v;

    int length_p = strlen(p);
    int length_v = strlen(v);

    if ( validateInput(p, length_p) ) {
		printf("DEBUGvalid");
        return ;
    }
    if ( validateInput(v, length_v) ) {
		printf("DEBUGvalid");
        return ;
    }

    int *index_success = malloc(sizeof(int) * ( length_p - length_v ) );
    // Check mem allocation, if fails return;
    if (!index_success) {
        free(index_success);
		printf("DEBUGmem_check");
        return ;
    }

    int *ptr_index_success = index_success;
    int success_count = 0;

    for (int i = 0; i <= ( length_p - length_v ); i++) {
        ptr_p = &p[i];
        ptr_v = &v[0];

        int error_flag = 0;
        int iteration = 0;
        do  {


            if (*ptr_p != *ptr_v) {
                error_flag += 1;
            }

            ptr_p++;
            ptr_v++;

            iteration++;
        } while ( iteration < length_v && error_flag < 2) ;
        // save success_index if error_flag < 2
        if (error_flag < 2) {
            *ptr_index_success = i;
            *ptr_index_success++;
            success_count++;
        }


    }

    // For each matching starting adress print that success_index, and append a space.
    // At the end of the print there will be an extra space !!!
    // Maybe could have concatenated the results and then printfed them only once \
    // and corrected the trailing space. ???  TODO
    //  printf("DEBUG. success_count: %d\n", success_count);

    ptr_index_success = index_success;
    if ( success_count < 1 ) { printf("No Match!\n"); }
    else {
        for(int i = 0; i < success_count; i++) {
            printf("%d ", index_success[i]);
        }
        printf("\n");
    }

    free(index_success);

    return ;
}




int main() 
{
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        char* p = malloc(100000 * sizeof(char));
        char* v = malloc(100000 * sizeof(char));
        scanf("%s %s", p, v);
		printf("DEBUG");
        virusIndices(p, v);
	}
}
