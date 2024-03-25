#include <stdlib.h>
#include <net/if.h>

/* use libbpf-devel and libxdp-devel*/
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <xdp/libxdp.h>

/* define the global variables */

/* interface index */
static int ifindex;

/* xdp program */
struct xdp_program *prog = NULL;

int main(int argc, char *argv[])
{
    /* get the interface index by name */
    ifindex = if_nametoindex(argv[1]);
    if (!ifindex) {
        printf("get ifname from interface name failed\n");
        return 1;
    }

    /* load XDP object by libxdp */
    prog = xdp_program__open_file("xdp_redir_kern.o", "xdp_redir_kern", NULL);
}