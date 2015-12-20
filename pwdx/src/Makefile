CC = gcc
LIBDIR = /lib

all: pwdx envx

.c.o:
	$(CC) -c -o $@ $<

ak_pwdx_pwdenv.so:
	$(CC) -fPIC -shared -o ak_pwdx_pwdenv.so ak_pwdx_pwdenv.c

pwdx: pwdx.c ak_pwdx_pwdenv.so
	$(CC) -o pwdx $^

envx: envx.c ak_pwdx_pwdenv.so
	$(CC) -o envx $^
clean:
	rm -f *.so *.o

install-lib: ak_pwdx_pwdenv.so
	mkdir -p $(LIBDIR)
	install ak_pwdx_pwdenv.so $(LIBDIR)
	ldconfig
