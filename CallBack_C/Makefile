########  CONFIG    ####################
CROSS_COMPILE =
CFLAGS = -Wall -g
CC = ${CROSS_COMPILE}gcc
LIBS = -lpthread
########################################

TARGET= CallBack

OBJS = callback.o

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean: 
	rm -f *.o *.a core tags *.bak $(TARGET) $(OBJS) 

#depend:
#	$(MAKEDEPEND) -- $(CFLAGS) -- *.c