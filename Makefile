CFLAGS=-Wall -Werror
CFLAGS=-I./include
#LDFLAGS=-luv -lssl
LDFLAGS= libuv.a -lssl -lpthread -lrt

EXEC=server.exe
OBJS=utils.o engine.o

all: server
server:	$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(CFLAGS) $(LDFLAGS)
clean:
	rm *.o $(EXEC) -rf
