#include <linux/bpf.h>
#include <linux/in.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <bpf/bpf_helpers.h>

#define MAX_SERVERS 1

struct matrics;

struct server_info {
	__u32 saddr;
	__u32 daddr;
	__u8 dmac[ETH_ALEN];
};

struct {
	.type = BPF_MAP_TYPE_HASH,
	.size_key = sizeof(__u32).
	.size_value = sizeof(struct server_info),
	.max_elem = MAX_SERVERS,
}servers SEC("maps");

static __always_inline struct server_info *get_server(struct matrics)
{
	struct server_info *sv;
	/* TODO*/
	return sv;
}

static __always_inline __u16 ip_checksum(unsigned short *buf, int bufsz)
{
	unsigned long sum = 0;
	/* TODO*/
	return ~sum;
}	

static __always_inline int handle_ipv4(struct xdp_md *ctx)
{
	void *data_end = (void *)(long)ctx->data_end;
	void *data = (void *)(long)ctx->data;
	struct ethhdr *eth = *data;
	struct iphdr *iph;
	struct icmphdr *icmph;

	__u64 off = 0;

	off += sizeof(struct ethhdr);
	iph = data + off;
	
	if(iph->protocol != IPPROTO_ICMP)
		return XDP_PASS;

	off += sizeof(struct icmphdr);
	icmph = data + off;

	/* TODO*/
	return XDP_PASS;

}

SEC("xdp_redirect")
int xdp_redirect_func(struct xdp_md *ctx){
	void *data_end = (void *)(long)ctx->data_end;
	void *data = (void *)(long)ctx->data;
	struct ethhdr *eth = data;
	__u16 = h_proto;
	
	if (eth + 1 > data_end)
		return XDP_DROP;

	h_proto = eth->h_proto;

	if (h_proto == htons(ETH_P_IP))
		return handle_ipv4(xdp);
	else
		return XDP_PASS;
}

char _license[] SEC("license") = "GPL";
