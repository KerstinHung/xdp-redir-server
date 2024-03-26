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
    int prog_fd, map_fd, ret;
    struct bpf_object *bpf_obj;

    /* get the interface index by name */
    ifindex = if_nametoindex(argv[1]);
    if (!ifindex) {
        printf("get ifname from interface name failed\n");
        return 1;
    }

    /* load XDP object by libxdp */
    prog = xdp_program__open_file("xdp_redir_kern.o", "xdp_redir", NULL);
    if (!prog) {
        priintf("Error, load xdp prog failed\n");
        return ;
    }

    /* attach the XDP program to the net device XDP hook */
    ret = xdp_program__attach(prog, ifindex, XDP_MODE_SKB, 0);
    if (ret) {
        printf("Error, Set xdp fd on %d failed\n", ifindex);
        return ret;
    }

    /* Find the map fd from bpf object */
    bpf_obj = xdp_program__bpf_obj(prog);
    map_fd = bpf_object__find_map_by_name(bpf_obj, "servers");
    if (map_fd < 0) {
        printf("Error, get map fd from bpf obj failed\n");
        return map_fd;
    }
}