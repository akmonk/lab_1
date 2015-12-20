CC = gcc
LIBDIR = /lib

all: pwdx envx

.c.o:
	$(CC) -c -o $@ $<

ak_pwdx_envx.so:
	$(CC) -fPIC -shared -o ak_pwdx_envx.so ak_pwdx_envx.c

pwdx: pwdx.c ak_pwdx_envx.so
	$(CC) -o pwdx $^

envx: envx.c ak_pwdx_envx.so
	$(CC) -o envx $^
clean:
	rm -f *.so *.o

install-lib: ak_pwdx_envx.so
	mkdir -p $(LIBDIR)
	install ak_pwdx_envx.so $(LIBDIR)
	ldconfig
