OBJS = src/createreport.o src/createevent.o src/addevent.o src/generatereport.o

static: $(OBJS)
	mkdir -p lib
	ar rcs lib/libtaccreport.a $(OBJS)

dynamic: $(OBJS)
	mkdir -p lib
	gcc -shared -Wl,-soname,lib/libtaccreport.so.1 -o lib/libtaccreport.so.1.0 $(OBJS)

all: static dynamic

src/%.o: src/%.c
	gcc -c -fPIC -Iinclude -o $@ $<

.PHONY: clean

clean:
	rm -f src/*.o lib/*
