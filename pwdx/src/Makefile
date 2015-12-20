CC = gcc
LIBDIR = /lib

all: pwdx

.c.o:
	$(CC) -c -o $@ $<

pwdx: pwdx.c ak_pwdx_pwdenv.so
	$(CC) -o pwdx $^

clean:
	rm -f *.so *.o

install-lib: ak_pwdx_pwdenv.so
	mkdir -p $(LIBDIR)
	install ak_pwdx_pwdenv.so $(LIBDIR)
	ldconfig
