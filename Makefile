.PONHY: clean link unlink

KERN_TARGET := xdp_redir_kern.o

CLANG = clang

CFLAGS ?= -g -Wall -O2
DEV = enp0s3
SEC = xdp

$(KERN_TARGET):xdp_redir_kern.c
	$(CLANG) -target bpf $(CFLAGS) -c $^ -o $@

link:
	sudo ip link set dev $(DEV) xdp obj $(KERN_TARGET) sec $(SEC)
unlink:
	sudo ip link set dev $(DEV) xdp off
clean:
	rm -f xdp_redir_kern.o