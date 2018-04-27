#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STR_LEN 10000

void readline(char *str);

void div_and_print( char *inpt_str, char **divded_str, int strlen)
{
	int j = 0;
	for (int i = 0; i < strlen; i++) {
		j = i/2;
//		printf("div index is : %d\n", j);
		if (i%2 == 0) {
			divded_str[0][j] = inpt_str[i];
		} else {
			divded_str[1][j] = inpt_str[i];
		}
	}

}


int main() 
{
	// read 1 line to receive  # of test cases : T
	int T;

//// *** STACK SMASHING DETECTED ***
//	char buf[3]; 
//	readline(buf);
//	sscanf(buf,"%d", &T);
//// *** STACK SMASHING DETECTED ***


	char buffer[4];
	printf("%d\n", (buffer[0]));
	printf("%d\n", (buffer[1]));
	printf("%d\n", (buffer[2]));
	fgets(buffer,4,stdin) ;
	printf("%d\n", (buffer[0]));
	printf("%d\n", (buffer[1]));
	printf("%d\n", (buffer[2]));
	buffer[strcspn(buffer,"\n")] = 0;
	printf("%d\n", (buffer[0]));
	printf("%d\n", (buffer[1]));
	printf("%d\n", (buffer[2]));

	T = atoi(buffer);
	// for i in T read a new line

	char **line = malloc(sizeof(char*) * T);
	char ***div = malloc(sizeof(char **) * T);

	// Initialization for String holders
	for (int i = 0; i < T; i++) {
		line[i] = malloc(sizeof(char) * MAX_STR_LEN + 1);
		div[i] = malloc(sizeof(char*) * 2);
		div[i][0] = malloc(sizeof(char) * ((MAX_STR_LEN / 2) + 1));
		div[i][0][MAX_STR_LEN / 2 ] = '\0';
		div[i][1] = malloc(sizeof(char) * (( MAX_STR_LEN / 2) + 1));
		div[i][1][MAX_STR_LEN / 2 ] = '\0';
	}
	
	// store read lines 
	for (int i = 0; i < T; i++) {
		readline(line[i]);
	}

	// then process the data;
	// for i in T send a line to the **div_and_print( char *line[i], strlen(char *line[i]);** )
	for (int i = 0; i < T; i++) {
		div_and_print(line[i], div[i] , strlen(line[i]));
		printf("%s %s\n", div[i][0], div[i][1]);
	}


	// return

	// Initialization for String holders
	for (int i = 0; i < T; i++) {
		free(div[i][0]);
		free(div[i][1]);
		free(div[i]);
		free(line[i]);
	}

    free(div);
    free(line);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}


/*
 * Assumes the newline size is MAX 1000;
 */
void readline(char *str)
{
	char buffer[MAX_STR_LEN+2];
	fgets(buffer, MAX_STR_LEN+2, stdin);
	buffer[strcspn(buffer,"\n")] = '\0';
	strncpy(str, buffer, MAX_STR_LEN);
}
