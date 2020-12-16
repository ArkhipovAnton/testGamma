import struct
import ctypes

def chech1(strIn, size, sizeFull):
    strBufIn = ctypes.create_string_buffer(str.encode(strIn))
    #genNextId (char *src, size_t sizeOfStr, size_t sizeFull)
    testLib.funcSafe(strBufIn,size,sizeFull)
    return strBufIn.value.decode("utf-8")


testLib = ctypes.CDLL('./libtest.so')

counter = 0

size = 3
inp = "A2\0"
out_Et = "A3"
out = chech1(inp,size,size)
if out_Et!=out:
    print ('problem in ','inp = ',inp, ' out = ',out);
    counter = counter+1;

size = 6
inp = "Z9\0   "
out_Et = "A1-A1"
out = chech1(inp,size,size)
if out_Et!=out:
    print ('problem in ','inp = ',inp, ' out = ',out);
    counter = counter+1;

size = 6
inp = "Z9-Z8\0"
out_Et = "Z9-Z9"
out = chech1(inp,size,size)
if out_Et!=out:
    print ('problem in ','inp = ',inp, ' out = ',out);
    counter = counter+1;

size = 6
inp = "A9-Z9\0"
out_Et = "B1-A1"
out = chech1(inp,size,size)
if out_Et!=out:
    print ('problem in ','inp = ',inp, ' out = ',out);
    counter = counter+1;


size = 30
inp = "A9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9\0"
out_Et = "B1-A1-A1-A1-A1-A1-A1-A1-A1-A1"
out = chech1(inp,size,size)
if out_Et!=out:
    print ('problem in ','inp = ',inp, ' out = ',out);
    counter = counter+1;

size = 30
inp = "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9\0"
out_Et = "A1"
out = chech1(inp,size,size)
if out_Et!=out:
    print ('problem in ','inp = ',inp, ' out = ',out);
    counter = counter+1;

size = 9
inp = "Z9-Z9\0   "
out_Et = "A1-A1-A1"
out = chech1(inp,size,size)
if out_Et!=out:
    print ('problem in ','inp = ',inp, ' out = ',out);
    counter = counter+1;

print ('test passed with ', counter, ' errors')
