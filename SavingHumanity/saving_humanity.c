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
//		printf("char @index:%d is:%d\n",length, (int)*ptr_s);
	}

	return length;
}

int validateInput(char* input, int input_length)
{
    if (input_length > pow(10,5)) {
        //printf("TOO BIG input!\n");
        return 1;
    }

    for(int i = 0; i < input_length; i++) {
        if( (int)input[i] < (int)'a' || (int)input[i] > (int)'z') {
            //printf("inputs must be lowercase english letters!\n");
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

    char *ptr_p = p;
    char *ptr_v = v;

    int length_p = strlen(p);
    int length_v = strlen(v);

    if ( validateInput(p, length_p) ) {
        return ;
    }
    if ( validateInput(v, length_v) ) {
        return ;
    }

    int *index_success = malloc(sizeof(int) * ( length_p - length_v ) );
    // Check mem allocation, if fails return;
    if (!index_success) {
        free(index_success);
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
	const rlim_t kStackSize = 64 * 1024 * 1024L;
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);

    if (result == 0) {
		printf("DEBUG");
        if (rl.rlim_cur < kStackSize) {
			printf("DEBUG");
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }

	//printf("%lu\n", sizeof(size_t));
    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** pv = split_string(readline());

        char* p = pv[0];
		//printf("Len of P:%d\n", findStringLength(p));
        char* v = pv[1];
		//printf("Len of V:%d\n", findStringLength(v));
	
		if (p){ if(v){
        virusIndices(p, v);
		}}
		free(pv);
    }

    return 0;
}

char* readline() 
{
    int alloc_length = 1024;
	printf("alloc_length:%d\n", alloc_length);
    int data_length = 0;
    char* data = malloc( alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { 
			printf("DEBUG1\n");
			break; 
		}

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { 
			printf("DEBUG2\n");
			break;
		 }

        int new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { 
			printf("DEBUG3\n");
			break; 
		}

        alloc_length = new_length;
		printf("data_length is: %d\n", data_length);
		printf("alloc_length is: %d\n", alloc_length);
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
	}

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) 
{
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

