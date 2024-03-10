.PONHY: clean
xdp_redir_kern.o:xdp_redir_kern.c
	clang -target bpf -g -Wall -O2 -c xdp_redir_kern.c -o $@
clean:
	rm -f xdp_redir_kern.o