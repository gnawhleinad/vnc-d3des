all: vnc-d3des

vnc-d3des: vnc.c d3des.o
	gcc -O3 -Werror=format-security -Wall -o $@ $^
	chmod +x vnc-d3des

d3des.o: d3des.c
	gcc -o $@ -c $^

.PHONY: clean
clean:
	@rm -f d3des.o
	@rm -f vnc-d3des
