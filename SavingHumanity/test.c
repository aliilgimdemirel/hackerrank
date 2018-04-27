#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{

//	FILE *file = fopen("open_file.txt", "w+"); //w+ is R/W, created if did not exist, truncated if it did.
	
//	char *str = malloc(sizeof(char) * 8192 );
//	*(str+8191) = '\0';

//	for (int i = 0; i < 65536-1; i++) {
//		fprintf(file, "%c", 'a');
//	}
//	rewind(file);

//	for (int i = 0; i < 8192-1; i++) {
//		printf("@index:%d is :%c", i, str[i]);
//	}

	int alloc_length = 1024;
	int received_length = 0;

	char *data = malloc(alloc_length);
	char *token = NULL;

	int more_data = 1;

	while ( more_data ) {
		data = fgets(data, alloc_length, stdin);
		printf("Length of data : %lu\n", strlen(data));

		if ( token = strchr(data, '\n' ) ) {
			more_data = 0;
//			data = realloc(data, token - data);
//			strncpy(data, data, token - data);
			printf("\\n found\n");
//		} else if ( token = strchr(data, '\0' ) ) {
//			more_data = 0;
//			data = realloc(data, token - data);
//			strncpy(data, data, token - data);
//			printf("\\0 found\n");
		} else {
			alloc_length = alloc_length<<1;
			data = realloc(data, alloc_length);
		}
		

			printf("DEBUG\n");

	}

	char * ptr_data = data;
	printf("Length of data : %lu\n", strlen(ptr_data));
//	for (int i = 0; i < 10000-1; i++) {
//		if ( *ptr_data == '\0') { break;}
//		printf("@index:%d is :%d\t", i, (int)data[i]);
//	}

	//fclose(file);

	return 0;
}


