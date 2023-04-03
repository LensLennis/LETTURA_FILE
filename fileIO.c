/*! @file fileIO.c
	@brief Definitions of the functions declared in fileIO.h
	@author Paolo Gastaldo

	Details.
*/

//#define _CRT_SECURE_NO_WARNINGS
#include "fileIO.h"

/*! @brief Opens a file
	@param filePath the path to the file
	@param mode a string with the mode
	@return the FILE* (NULL if something went wrong)
*/
FILE* OpenFile(char* filePath, char* mode) {

	FILE* fPtr;

	if ((filePath == NULL) || (mode == NULL)) {
		printf("\n OpenFile - ");
		printf("ERROR: null string in input\n");
		return NULL;
	}


	fPtr = fopen(filePath, mode);
	if (fPtr == NULL) {
		printf("\n OpenFile - ");
		printf("ERROR: Unable to open file %s in (%s) mode\n", filePath, mode);
		printf("\n==== %s ===\n", strerror(errno));
		return NULL;
	}

	return fPtr;

}

/*! @brief close a FILE*
	@param fPtr the FILE pointer
	@return 1 means that everyting is ok, -1 means that something went wrong
*/
int CloseFile(FILE* fPtr) {

	if (fPtr != NULL)
		if (fclose(fPtr) != 0) {
			printf("\n CloseFile - ");
			printf("Error closing file \n");
			printf("\n==== %s ===\n", strerror(errno));
			return -1;
		}

	return 1;

}

/*! @brief write on a file (mode: w) all the strings included in the dynamic list of strtoken
	@param filePath file name with path
	@param listPtr pointer to the dynamic list of strtoken
	@return 1 means that everyting is ok, -1 means that something went wrong
*/
int WriteToFile(char* filePath, strtoken* listPtr) {

	FILE* fPtr = OpenFile(filePath, "w");
	if (fPtr == NULL) {
		printf("\n WriteToFile - ");
		printf("Unable to open the file\n");
		return -1;
	}

	if (listPtr != NULL)
		if (PrintList(listPtr, fPtr) == -1) {
			printf("\n WriteToFile - ");
			printf("Unable to write\n");
			return -1;
		}

	CloseFile(fPtr);
	return 1;
}

/*! @brief write on a file (mode: wa) all the strings included in the dynamic list of strtoken
	@param filePath file name with path
	@param listPtr pointer to the dynamic list of strtoken
	@return 1 means that everyting is ok, -1 means that something went wrong
*/
int AppendToFile(char* filePath, strtoken* listPtr) {

	FILE* fPtr = OpenFile(filePath, "wa");
	if (fPtr == NULL) {
		printf("\n WriteToFile - ");
		printf("Unable to open the file\n");
		return -1;
	}

	if (listPtr != NULL)
		if (PrintList(listPtr, fPtr) == -1) {
			printf("\n WriteToFile - ");
			printf("Unable to write\n");
			return -1;
		}

	CloseFile(fPtr);
	return 1;
}



/*! @brief read all lines from a file; the lines are collected as dynamic list of strtoken
	@param filePath file name with path
	@return the pointer to the dynamic list (NULL means that something went wrong)
*/
strtoken* ReadLinesFromFile(char* filePath) {

	char str[TOKENL];
	strtoken* theList = NULL;

	FILE* fPtr = OpenFile(filePath, "r");
	if (fPtr == NULL) {
		printf("\n ReadStringFromFile - ");
		printf("Unable to open the file\n");
		return NULL;

	}


	while (fgets(str, TOKENL, fPtr)) {
		if (!feof(fPtr)) {
			str[strcspn(str, "\n")] = 0; /* removing end of line */
			theList = AddItem(theList, str);
		}

	}

	if (feof(fPtr)) {
		CloseFile(fPtr);
		return theList;
	}
	else {
		CloseFile(fPtr);
		printf("\n ReadStringFromFile - ");
		printf("Unable to read the whole file\n");
		ClearList(theList);
		return NULL;
	}

}