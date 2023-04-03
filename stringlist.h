
/*! \file stringlist.h
    \brief management of a linked list of string tokens 
	\author Paolo Gastaldo

    Details.
*/



#ifndef STRINGLIST_H 
#define STRINGLIST_H

#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>

/*the lenght of a string token*/
#define TOKENL 5000

/*! @struct node 
	@brief core element for a dynamic list of strings
*/
typedef struct node {
	
	char token[TOKENL];
	struct node *next;

} strtoken; 

strtoken* AddItem (strtoken* listPtr, char* str);
void ClearList (strtoken* listPtr);
int PrintList (strtoken* listPtr, FILE* filePtr);

#endif