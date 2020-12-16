#build all
all:library
#	app
#build lib
library:lib.c
	gcc -fPIC -shared -o libtest.so lib.c
#clean all
clean:
	rm -rf  *.so
