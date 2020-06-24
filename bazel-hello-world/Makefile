libgreeting.a: greeting.cc
	g++ -c -o -v greeting.o $<
	ar rcs $@ greeting.o

hello: libgreeting.a greeting.hh hello.cc
	g++ -static hello.cc -L. -lgreeting -o $@