CC=g++
CFLAGS= -Wall -pedantic
INCDIR=inc
OBJDIR=obj
SRCDIR=src

SRCS=$(wildcard src/*.cpp)
DEPS=$(wildcard inc/*.h)
OBJS= $(subst $(SRCDIR),$(OBJDIR),$(SRCS:.cpp=.o ))

all: $(OBJDIR) $(OBJS)
		$(CC) $(CFLAGS) -o Sort.out $(OBJS)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

run:
	./Sort.out

.PHONY: clean

clean:
	rm $(OBJDIR)/*.o
