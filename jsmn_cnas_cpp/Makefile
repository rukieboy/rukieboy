CFLAGS+=-Wall  -std=gnu99 -O2 
LDFLAGS+=`curl-config --libs`

TARGETS= jsmn_cnas
OBJS=buf.o log.o json.o jsmn.o

all: $(TARGETS) .gitignore

clean:
	$(RM) $(TARGETS)
	$(RM) $(OBJS)

jsmn_cnas: $(OBJS) jsmn_cnas.o
	$(CXX) -o $@ $^ $(LDFLAGS) 

.PHONY: all clean




