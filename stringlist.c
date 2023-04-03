/*! \file stringlist.c
	\brief Implementations of the functions declared in stringlist.h
	\author Paolo Gastaldo

	Details.
*/

//#define _CRT_SECURE_NO_WARNINGS
#include "stringlist.h"

/*! @brief add an item at the end of the dynamic list
	@parameter listPtr pointer to the head of the dynamic list
	@parameter str the string to be addedd
	@returns pointer to the head of the dynamic list
*/
strtoken* AddItem(strtoken* listPtr, char* str) {

	strtoken* lp = listPtr;


	if (listPtr != NULL) {
		/* add at the end of the list */

		while (listPtr->next != NULL)
			listPtr = listPtr->next;
		listPtr->next = (strtoken*)malloc(sizeof(strtoken));
		listPtr = listPtr->next;
		listPtr->next = NULL;
		strcpy(listPtr->token, str);

		return lp;
	}
	else {
		/* first item of the list */

		listPtr = (strtoken*)malloc(sizeof(strtoken));
		listPtr->next = NULL;
		strcpy(listPtr->token, str);

		return listPtr;
	}


}

/*! @brief delete all the items of a dynamic list
	@parameter listPtr pointer to the head of the dynamic list
*/
void ClearList(strtoken* listPtr) {

	strtoken* temp;
	while (listPtr != NULL) {
		temp = listPtr->next;
		free(listPtr);
		listPtr = temp;
	}
}


/*! @brief print all the strings in a dynamic list
	@parameter listPtr pointer to the head of the dynamic list
	@parameter filePtr pointer to a FILE
	@returns 1 if everything is ok, -1 if something went wrong
*/
int PrintList(strtoken* listPtr, FILE* filePtr) {

	if (filePtr == NULL) {
		printf("\n PrintList - ");
		printf("ERROR: null pointer to File\n");
		return -1;
	}

	if (listPtr == NULL) {
		if (fprintf(filePtr, "the list is empty!\n") < 0) {
			printf("\n PrintList - ");
			printf("ERROR: unable to write\n");
			return -1;
		}
	}
	else {
		while (listPtr != NULL) {
			if (fprintf(filePtr, "%s\n", listPtr->token) < 0) {
				printf("\n PrintList - ");
				printf("ERROR: unable to write\n");
				return -1;
			}
			listPtr = listPtr->next;
		}
	}

	return 1;
}
