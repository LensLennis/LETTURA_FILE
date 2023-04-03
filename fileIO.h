/*! @file fileIO.h
	@brief Library of functions for I/O on files 
	@author Paolo Gastaldo

	Details.
*/


#ifndef FILEIO_H 
#define FILEIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringlist.h"



FILE* OpenFile(char* filePath,char* mode);
int CloseFile(FILE* fPtr);
int AppendToFile (char* filePath, strtoken* listPtr);
int WriteToFile (char* filePath, strtoken* listPtr);
strtoken* ReadLinesFromFile(char* filePath);

#endif