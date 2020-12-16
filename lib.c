#include "lib.h"
#include "string.h"
//#include "stdio.h"


//check content in source string; return size if ok or error code
//size - is number of symbols,
//if error in size - return -1
//if error in content - return -2
//if sequence OK - return number of characters
int
checkStr(const char *src, int sizeSimb)
{
    int s = 0;



  	for (; ((*(src) != '\0')&&(s <= sizeSimb-3)) ; src += 3, s += 3)
  	{
        //check letter in identifier
//        printf("s = %d\n",s);
        if ((*src < 'A') || (*src > 'Z'))
        {
//            printf("err content 1, i = %d, src = %d\n",s,*src);
            return ERR_CONTENT;
        }
        else
        {
            switch (*src){
            case 'D':
            case 'F':
            case 'G':
            case 'J':
            case 'M':
            case 'Q':
            case 'V':
//                printf("err content 2\n");
                return ERR_CONTENT;
                break;
            }

        }
        //check digit in identifier
        if ((*(src+1) < 0x31) || (*(src+1) > 0x39))
        {
//            printf("err content 3\n");
            return ERR_CONTENT;
        }
        //check separator
        if (*(src+2) != '-')
        {
            if (s > MAX_SIZE )
            {
//                printf("err size 1, s = %d\n",s);
                return ERR_SIZE;
            }
            //check last symbol
            else if (*(src+2) != '\0')
            {
//                printf("err content 4\n");
                return ERR_CONTENT;
            }
        }
    }
    if (*(src-1) != '\0')
    {
//        printf("err content 5, src = %d, s = %d\n",*(src-1),s);
        return ERR_CONTENT;
    }
//string ok
    return s;
}

//check size of buffer
int checkBufferSize(char *str, int sizeBuf)
{
    int sizeOfStr = strlen(str)+1;

    for (int i = 0; i < sizeOfStr; i+=3)
    {
        if (str[i] != 'Z'){
//            printf("not Z, %X\n",str[i]);
            return 0;
            }
        if (str[i+1]!='9'){
            return 0;
//            printf("not 9, %X\n", str[i+1]);
            }
    }

    if (sizeOfStr+3 <= sizeBuf){
//        printf ("All ok, sizeBuf = %d, sizeJfStr = %d\n", sizeBuf, sizeOfStr);
        return 0;
    }
    else if ((sizeOfStr == 30) && (sizeBuf == 30)){
//        printf("size30\n");
        return 0;
    }
//    printf("problems, sizeofstr = %d, sizeofbuf = %d\n",sizeOfStr,sizeBuf);
    return -2;
}


//generate next identificator in sequency
//size - in number of characters
int
genNextId (char *src, int sizeOfBuf, int pos, int sizeFull)
{
    char *s;
    int sizeOfStr = strlen(src)+1;
    s = src;
    if (pos > 0)
    {
        int tmp_pos = pos;
        if (s[pos-2] < '9')
        {
//            printf("add num\n");
            s[pos-2] = *(s+pos-2)+1;
        }
        else
        {
//            printf("add letter\n");
            s[pos-2] = '1';
            s[pos-3] = *(s+pos-3)+1;
            switch(s[pos-3])
            {
                case 'D':
                case 'F':
                case 'G':
                case 'J':
                case 'M':
                case 'Q':
                case 'V':
                    s[pos-3] = *(s+pos-3)+1;
                    break;
                case ('Z'+1):
                    s[pos-3] = 'A';
                    genNextId(src,sizeOfStr,pos-3,sizeFull);
                    break;
            }
        }
    }
    else
    {
//        printf ("pos 0, out string = %s, sizeFull = %d\n",src,sizeFull);
        if (sizeFull <= MAX_SIZE-3)
        {
            s[sizeOfStr-1] = '-';
            s[sizeOfStr] = 'A';
            s[sizeOfStr+1] = '1';
            s[sizeOfStr+2] = '\0';
		    return sizeOfStr+2;
        }
        else
        {
	        int i;
            s[0] = 'A';
            s[1] = '1';
            for (i = 2;i<sizeFull;i++)
                s[i] = '\0';
            return i;
        }
    }
//    printf ("out string = %s\n",src);

    return sizeOfStr;
}

//save function with size check and input string check
int
funcSafe (char *str, int size)
{
	char *save = str;
	int s;
//	printf("funcSafe\n");
	int bufSize = checkBufferSize(str, size);
	if (bufSize != 0)
        return bufSize;
	int strSize = checkStr(str, strlen(str)+1);
//	printf("checkResult = %d\n",strSize);
	if (strSize+3 <= MAX_SIZE)
        size = strSize+3;
    if (strSize >= 0)
    {
    	int outSize = genNextId(str, strSize, strSize, size);
//    	printf ("output size = %d\n",outSize);
        return outSize;
    }
    else
    {
        return strSize;
    }
}

