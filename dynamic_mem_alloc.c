#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
	char* string;

	string = (char*) malloc(11*sizeof(char));
	printf(" \n string after malloc :: %s ",string);
	printf(" \n string address :: %u ",*string);
	strcpy(string,"this is str");
	printf(" \n After malloc :: %s ", string);
	
	string = (char*) realloc(string,3*sizeof(char));
	printf(" \n string address after realloc :: %u ",*string);
	printf(" \n string after realloc before strcat :: %s ",string);
	strcat(string,"ing");
	printf(" \n After realloc :: %s \n", string);
	
	free(string);	
	return 0;

}

