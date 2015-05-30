#ifndef _NFNL_ACCT_H_
#define _NFNL_ACCT_H_

#ifndef NFACCT_NAME_MAX
#define NFACCT_NAME_MAX		32
#endif

enum nfnl_acct_msg_types {
	NFNL_MSG_ACCT_NEW,
	NFNL_MSG_ACCT_GET,
	NFNL_MSG_ACCT_GET_CTRZERO,
	NFNL_MSG_ACCT_DEL,
	NFNL_MSG_ACCT_OVERQUOTA,
	NFNL_MSG_ACCT_MAX
};

enum nfnl_acct_flags {
	NFACCT_F_QUOTA_PKTS	= (1 << 0),
	NFACCT_F_QUOTA_BYTES	= (1 << 1),
	NFACCT_F_OVERQUOTA	= (1 << 2), /* can't be set from userspace */
};

enum nfnl_acct_type {
	NFACCT_UNSPEC,
	NFACCT_NAME,
	NFACCT_PKTS,
	NFACCT_BYTES,
	NFACCT_USE,
	NFACCT_FLAGS,
	NFACCT_QUOTA,
	NFACCT_FILTER,
	__NFACCT_MAX
};
#define NFACCT_MAX (__NFACCT_MAX - 1)

enum nfnl_attr_filter_type {
	NFACCT_FILTER_ATTR_UNSPEC,
	NFACCT_FILTER_ATTR_MASK,
	NFACCT_FILTER_ATTR_VALUE,
	__NFACCT_FILTER_ATTR_MAX
};
#define NFACCT_FILTER_ATTR_MAX (__NFACCT_FILTER_ATTR_MAX - 1)

#ifdef __KERNEL__

enum {
	NFACCT_NO_QUOTA		= -1,
	NFACCT_UNDERQUOTA,
	NFACCT_OVERQUOTA,
};
struct nf_acct;

extern struct nf_acct *nfnl_acct_find_get(const char *filter_name);
extern void nfnl_acct_put(struct nf_acct *acct);
extern void nfnl_acct_update(const struct sk_buff *skb, struct nf_acct *nfacct);
extern int nfnl_acct_overquota(const struct sk_buff *skb,
			      struct nf_acct *nfacct);

#endif /* __KERNEL__ */

#endif /* _NFNL_ACCT_H */
