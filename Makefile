

all:
	gcc wrapper.c -o wrapper
	mkdir -p libnss_m
	gcc -fPIC -shared lib.c -o 'libnss_m/au bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb.so.2'
