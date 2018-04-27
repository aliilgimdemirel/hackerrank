#include <stdlib.h>
#include <string.h>
#include <stdio.h>



char *readline()
{
	int alloc_length = 1024;
	int data_length = 0;

	char* data = malloc(sizeof(char) * alloc_length);	

	int iteration = 1;
	int condition = 1;
	do {
		char *cursor = data + data_length;
		char *line = fgets(cursor, ( (alloc_length * iteration) - data_length), stdin);
		
		if (!line) {
			printf("MEMALLOC Problem! Should exit!\n");
		}
		
		data_length +=strlen(cursor);
		printf("data_len is: %d\n", data_length);
		printf("all_len*iter-1: %d\n\n", (alloc_length*iteration)-1);

		if (data[data_length-1] == '\n' || data_length < (alloc_length*iteration)-1 ) {
			printf("The line has been read fully.\n");
			// we should then start leaving ?/
			condition = 0;
			printf("***data_len-1 index:%d***\n", (int)data[data_length-1]);
		} else {
			data = realloc(data, alloc_length * ( iteration+1 ) );
						
			printf("REALLOC: %d\n\n", (alloc_length*(iteration+1)));

			if(!data) {
				printf("MEMALLOC Problem! Should exit!\n");
			}	
		
			//alloc_length = new_alloc_length;
		}

//		printf("alloc_length is: %d\n", alloc_length);
		iteration += 1;
	} while (condition && iteration < 1000);

	return data;
}


int main() 
{
	char *readInData = readline();

	printf("Length of data: %lu\n", strlen(readInData));

	return 0;
}
