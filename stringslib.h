/*! \file stringslib.h
	\brief Library of functions for extracting infos from a string

	Details.
*/


#ifndef STRINGSLIB_H 
#define STRINGSLIB_H
#include <stdio.h> 
#include <stdlib.h> 

#define HIST_BINS 256 /* Number of bins in the char histogram */


int* Shist(char* instr, int length);
int MOSstring(int* hist, char* mos, int* occurrences);
int SOstring(int* hist, char tosearch);
int DOstring(int* hist);
int AOstring(int* hist);

#endif