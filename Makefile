.PONHY: clean link unlink

KERN_TARGET := xdp_redir_kern.o

CLANG = clang

CFLAGS ?= -g -Wall -O2

$(KERN_TARGET):xdp_redir_kern.c
	$(CLANG) -target bpf $(CFLAGS) -c $^ -o $@

clean:
	rm -f xdp_redir_kern.o