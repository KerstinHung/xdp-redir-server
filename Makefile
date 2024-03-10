.PONHY: clean

KERN_TARGET := xdp_redir_kern.o

CLANG = clang

$(KERN_TARGET):xdp_redir_kern.c
	$(CLANG) -target bpf -g -Wall -O2 -c xdp_redir_kern.c -o $@
clean:
	rm -f xdp_redir_kern.o