CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Werror #-Wa,-aldh="`basename $@`.lst"

SRCS= \
  dumper.c \
  dumper_test.c

OBJS=$(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $?

libdumper.a : dumper.o
	${AR} -r $@ $?

dumper_test: $(OBJS) 
	${CC} -o $@ ${CFLAGS} $? 

clean:
	rm -rf *.o *.a *.lst dumper_test
