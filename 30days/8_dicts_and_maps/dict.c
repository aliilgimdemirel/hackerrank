#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STR_LEN 700

char** split_string(char* str);
char* readline();

struct Person{
    int number;
    char *name;
};

struct PhoneBook{
	struct Person **person;
};

struct PhoneBook *create_phoneBook(int n)
{
	struct PhoneBook* pBook = malloc( sizeof(struct PhoneBook) ); 
	if (!pBook) {
		// exit condition, malloc failed !
		printf("exit condition, malloc failed !\n");
	}

	pBook->person = malloc(sizeof(struct Person*) * n);

	for (int i = 0; i < n; i++)	{
		// first create a space for new Person
		struct Person *pers = malloc(sizeof(struct Person));
		pBook->person[i] = pers;
		// 49 char long names
		pBook->person[i]->name = malloc(sizeof(char) * MAX_STR_LEN );
		memset(pBook->person[i]->name, 0, MAX_STR_LEN);
		pBook->person[i]->number = 0;
	}

	return pBook;
}

void addToPhoneBook(struct PhoneBook *pBook, int cursor, char *name, int number)
{
	char * res = strncpy(pBook->person[cursor]->name, name, MAX_STR_LEN-1);
	if(!res) {
		printf("strcpy FAIL!\n");	
	}
	pBook->person[cursor]->number = number;
}

void querryPhoneBook(struct PhoneBook *pBook, char *name, int pBookLen)
{
	int flag_found = 0;
	
	for (int i = 0; i < pBookLen; i++) {
		if(!strcmp(name, pBook->person[i]->name)) {
			flag_found = 1;
			printf("%s=%d\n",pBook->person[i]->name, pBook->person[i]->number);
		}
	}
	
	if(flag_found == 0) {
		printf("Not found\n");
	}
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    // Read the first line that tells the # of entries in the Phone Book
	int T;
	int rc;
	char buffer[7];
    fgets(buffer,7,stdin) ;
    buffer[strcspn(buffer,"\n")] = 0;
    T = atoi(buffer);
 
	struct PhoneBook* pBook = create_phoneBook(T);

	for (int i = 0; i < T; i++) {
		char *str = malloc(sizeof(char) * MAX_STR_LEN);
		char **person_input = split_string(readline(str));
		addToPhoneBook(pBook, i, person_input[0], strtol(person_input[1], NULL, 10));
		
//		printf("%s=%d\n",pBook->person[i]->name, pBook->person[i]->number);
		free(str);	
	}

	for(int i = 0; i < 20; i++) {
		printf("%d'th entry is %s with value %d\n", i, pBook->person[i]->name, \
				 pBook->person[i]->number);
	}

	qsort(pBook->person, T, 1, strcmp);

	for(int i = 0; i < 20; i++) {
		printf("%d'th entry is %s with value %d\n", i, pBook->person[i]->name, \
				 pBook->person[i]->number);
	}


	while(1) {
		char *str = malloc(sizeof(char) * MAX_STR_LEN);
		querryPhoneBook(pBook, readline(str), T);
		if(strlen(str) == 0) { 
			free(str);
			// Call exit seq
		}
		free(str);	
	}


   return 0;
}

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

char *readline(char *str)
{
    char buffer[MAX_STR_LEN+2];
	memset(buffer, 0, MAX_STR_LEN+2);
    fgets(buffer, MAX_STR_LEN+2, stdin);
    buffer[strcspn(buffer,"\n")] = '\0';
    strncpy(str, buffer, MAX_STR_LEN);
	return str;
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

