xdp_redir_kern:xdp_redir_kern.c
	clang -target bpf -g -Wall -O2 -c xdp_redir_kern.c -o xdp_redir_kern