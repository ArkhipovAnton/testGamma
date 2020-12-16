#ifndef LIB_H
#define LIB_H
#include <stdlib.h>

#define ERR_CONTENT         -1 //error in input sequence
#define ERR_SIZE            -2 //error in buffer size
#define MAX_SIZE            3*10 //maximum size of sequency - 10 identificators

//check content in source string; return size of ok or error code
//size - in symbols, not number of characters
int checkStr(const char *src, int sizeSimb);

//generate next identificator in sequency
//size - in number of characters in src
int genNextId (char *src, int sizeOfStr, int pos, int sizeFull);

//target function,
//char *str - pointer to the char array with target string
//size of this array;
//return number of significant chars of error code
int funcSafe (char *str, int sizeFull);

int checkBufferSize(char *str, int sizeBuf);

#endif
