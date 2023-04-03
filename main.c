/** \file main.c
	\brief reading a string and computing some stats

	Details.
*/

#define MAXL 20000
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "stringslib.h"
#include "stringlist.h"
#include "fileIO.h"

#define STR_SIZE 1000


int main() {


	char str[STR_SIZE];
	int* hist;
	char mos;
	int occurrences;
	char tosearch;
	int rv;
	int counter = 1;
	int stringnumber=0;
	char PathDir[MAXL];
	printf("Insert here the directory path: ");
	gets_s(PathDir,MAXL);
	printf("%s", PathDir);
	strtoken* startlist = ReadLinesFromFile(PathDir);
	
	strtoken* temp = startlist;
	if (startlist == NULL)
	{
		printf("\n *ERROR* \n The list returned NULL");
		return -1;
	}
	while (temp != NULL)
	{
		printf("\n%d) %s", counter, temp->token);
		counter++;
		temp = temp->next;
		
	}
	printf("\n Enter the string you would like to count characthers of: ");
	scanf_s(" %d", &stringnumber);
	
	if (stringnumber <= 0 || stringnumber > counter)
	{
		printf("\n *ERROR* \n you've chosen an impossible number, choose again");
		return -1;
	}
	counter = 1;
	getchar();
	while (counter < stringnumber)
	{
		startlist = startlist->next;
		counter++;
	}


	printf("\nstring: %s\n", startlist->token);
		

	hist = Shist(startlist->token, STR_SIZE);
	if (hist == NULL) {
		printf("ERROR in Main: cannot compute histogram\n");
		return -1;

	}

	rv = MOSstring(hist, &mos, &occurrences);
	if (rv < 0) {
		printf("ERROR in Main: cannot compute most occurring symbol\n");
		return -1;
	}

	printf("The most occurring symbol is '%c' = %d times\n", mos, occurrences);

	occurrences = AOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of alphabet symbols\n");
		return -1;
	}
	printf("The string includes %d alphabet characters\n", occurrences);

	occurrences = DOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of digits\n");
		return -1;
	}
	printf("The string includes %d digits\n", occurrences);


	printf("Enter a symbol: ");
	tosearch = getchar();
	occurrences = SOstring(hist, tosearch);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of the symbol\n");
		return -1;

	}

	printf("Symbol -%c- appears %d times.", tosearch, occurrences);

	if (hist != NULL)
		free(hist);

	return 0;
}