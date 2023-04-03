/*! \file stringslib.c
    \brief Implementations of the functions declared in stringslib.h

    Details.
*/



#include "stringslib.h"

/*!	@brief computes the histogram of the ASCII symbol in a string
    @param instr input string
    @param length string length
    @return pointer to the array that collects the occurrencies (the histogram), NULL if something went wrong

    the histogram is an array of size HIST_BINS that should be deallocated before leaving the program 

 */
int* Shist(char* instr, int length) {

    int i;
    int* hist;
    unsigned int ascii;

    if (instr == NULL) {
        printf("Error in Shist: null pointer");
        return NULL;

    }

    hist = (int*)malloc(HIST_BINS * sizeof(int));
    if (hist == NULL) {
        printf("Error in Shist: cannot allocate histogram");
        return NULL;
    }

    

    /* Initializes frequency of all symbols to 0 */
    for (i = 0; i < HIST_BINS; i++)
        hist[i] = 0;

    /* Finds frequency of each symbol */
    i = 0;
    while (instr[i] != '\0' && i < length)
    {
        ascii = (unsigned char)instr[i];
        hist[ascii] += 1;

        i++;
    }

    return hist;
}

/*! @brief finds most occurent ASCII symbol in a string by processing its histogram
    @param hist pointer to the histogram computed on the string of interest
    @param mos  most occurring symbol
    @param occurrences occurrences of mos
	@return 1 if everything is ok, -1 if something went wrong
*/
int MOSstring(int* hist, char* mos, int* occurrences) {

    int i;
    int max = 0;

    if (hist == NULL) {
        printf("Error in MOSstring: null pointer");
        return -1;

    }

    /* Finds maximum frequency */
    max = 0;
    for (i = 0; i < HIST_BINS; i++)
    {
        if (hist[i] > hist[max])
            max = i;
    }

    *mos = (char)max;
    *occurrences = hist[max];

    return 1;

}

/*! @brief finds the occurrences of a given ASCII symbol in a string by processing its histogram
    @param hist pointer to the histogram computed on the string of interest
    @param tosearch the symbol
    @return occurences of the symbol
*/
int SOstring(int* hist, char tosearch) {

    unsigned int ascii;

    if (hist == NULL) {
        printf("Error in SOstring: null pointer");
        return -1;

    }
    ascii = (unsigned char)tosearch;

    return hist[ascii];
}

/*! @brief finds the occurrences of digits in a string by processing its histogram
    @param hist pointer to the histogram computed on the string of interest
    @return occurences of digits
*/
int DOstring(int* hist) {

    int i = 0;
    int occurrences = 0;

    if (hist == NULL) {
        printf("Error in SOstring: null pointer");
        return -1;

    }


    for (i = 47; i < 58; i++)
        occurrences += hist[i];

    return occurrences;
}

/*! @brief finds the occurrences of alphabet characters in a string by processing its histogram
    @param hist pointer to the histogram computed on the string of interest
    @return occurences of alphabet characters
*/
int AOstring(int* hist) {

    int i = 0;
    int occurrences = 0;

    if (hist == NULL) {
        printf("Error in SOstring: null pointer");
        return -1;

    }

    for (i = 65; i < 91; i++)
        occurrences += hist[i];
    for (i = 97; i < 123; i++)
        occurrences += hist[i];

    return occurrences;
}