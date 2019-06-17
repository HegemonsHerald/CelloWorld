#### Example 1

```
; <<>> DiG 9.10.6 <<>> www.example.com +trace
;; global options: +cmd
.			82328	IN	NS	d.root-servers.net.
.			82328	IN	NS	f.root-servers.net.
.			82328	IN	NS	e.root-servers.net.
.			82328	IN	NS	a.root-servers.net.
.			82328	IN	NS	g.root-servers.net.
.			82328	IN	NS	k.root-servers.net.
.			82328	IN	NS	c.root-servers.net.
.			82328	IN	NS	b.root-servers.net.
.			82328	IN	NS	j.root-servers.net.
.			82328	IN	NS	m.root-servers.net.
.			82328	IN	NS	h.root-servers.net.
.			82328	IN	NS	i.root-servers.net.
.			82328	IN	NS	l.root-servers.net.
;; Received 540 bytes from 192.168.2.1#53(192.168.2.1) in 29 ms

com.			172800	IN	NS	g.gtld-servers.net.
com.			172800	IN	NS	e.gtld-servers.net.
com.			172800	IN	NS	m.gtld-servers.net.
com.			172800	IN	NS	i.gtld-servers.net.
com.			172800	IN	NS	j.gtld-servers.net.
com.			172800	IN	NS	b.gtld-servers.net.
com.			172800	IN	NS	l.gtld-servers.net.
com.			172800	IN	NS	c.gtld-servers.net.
com.			172800	IN	NS	a.gtld-servers.net.
com.			172800	IN	NS	k.gtld-servers.net.
com.			172800	IN	NS	d.gtld-servers.net.
com.			172800	IN	NS	h.gtld-servers.net.
com.			172800	IN	NS	f.gtld-servers.net.
;; Received 1175 bytes from 192.33.4.12#53(c.root-servers.net) in 38 ms

example.com.		172800	IN	NS	a.iana-servers.net.
example.com.		172800	IN	NS	b.iana-servers.net.
example.com.		86400	IN	DS	31589 8 1 3490A6806D47F17A34C29E2CE80E8A999FFBE4BE
example.com.		86400	IN	DS	31589 8 2 CDE0D742D6998AA554A92D890F8184C698CFAC8A26FA59875A990C03 E576343C
example.com.		86400	IN	DS	43547 8 1 B6225AB2CC613E0DCA7962BDC2342EA4F1B56083
example.com.		86400	IN	DS	43547 8 2 615A64233543F66F44D68933625B17497C89A70E858ED76A2145997E DF96A918
example.com.		86400	IN	DS	31406 8 1 189968811E6EBA862DD6C209F75623D8D9ED9142
example.com.		86400	IN	DS	31406 8 2 F78CF3344F72137235098ECBBD08947C2C9001C7F6A085A17F518B5D 8F6B916D
;; Received 507 bytes from 192.26.92.30#53(c.gtld-servers.net) in 139 ms

www.example.com.	86400	IN	A	93.184.216.34
;; Received 231 bytes from 2001:500:8f::53#53(a.iana-servers.net) in 158 ms
```

In lines 2 through 16 `dig` queries the nameservers at the root level.  

The root domain servers tell `dig` to go look for the target server on the
`.com` top level domain servers, which it promptly does in lines 18 through 31.

From one of these `dig` is refered to the nameservers handling the subdomains
of the `example.com` domain in the lines 33 through 41.

Lastly `dig` finally connects with the server for the 'www' subdomain of
`example.com` in line 43.


#### Example 2

```
; <<>> DiG 9.10.6 <<>> www.youtube.de +trace
;; global options: +cmd
.			81757	IN	NS	d.root-servers.net.
.			81757	IN	NS	f.root-servers.net.
.			81757	IN	NS	e.root-servers.net.
.			81757	IN	NS	a.root-servers.net.
.			81757	IN	NS	g.root-servers.net.
.			81757	IN	NS	k.root-servers.net.
.			81757	IN	NS	c.root-servers.net.
.			81757	IN	NS	b.root-servers.net.
.			81757	IN	NS	j.root-servers.net.
.			81757	IN	NS	m.root-servers.net.
.			81757	IN	NS	h.root-servers.net.
.			81757	IN	NS	i.root-servers.net.
.			81757	IN	NS	l.root-servers.net.
;; Received 540 bytes from 192.168.2.1#53(192.168.2.1) in 128 ms

de.			172800	IN	NS	a.nic.de.
de.			172800	IN	NS	s.de.net.
de.			172800	IN	NS	n.de.net.
de.			172800	IN	NS	f.nic.de.
de.			172800	IN	NS	z.nic.de.
de.			172800	IN	NS	l.de.net.
;; Received 720 bytes from 2001:500:2::c#53(c.root-servers.net) in 37 ms

youtube.de.		86400	IN	NS	ns3.google.com.
youtube.de.		86400	IN	NS	ns2.google.com.
youtube.de.		86400	IN	NS	ns4.google.com.
youtube.de.		86400	IN	NS	ns1.google.com.
;; Received 608 bytes from 2001:678:2::53#53(a.nic.de) in 37 ms

www.youtube.de.		86400	IN	CNAME	youtube-ui.l.google.com.
youtube-ui.l.google.com. 300	IN	A	172.217.16.142
youtube-ui.l.google.com. 300	IN	A	172.217.22.46
youtube-ui.l.google.com. 300	IN	A	172.217.22.78
youtube-ui.l.google.com. 300	IN	A	172.217.22.110
youtube-ui.l.google.com. 300	IN	A	216.58.210.14
youtube-ui.l.google.com. 300	IN	A	172.217.16.206
youtube-ui.l.google.com. 300	IN	A	172.217.18.110
youtube-ui.l.google.com. 300	IN	A	172.217.23.174
youtube-ui.l.google.com. 300	IN	A	216.58.205.238
youtube-ui.l.google.com. 300	IN	A	172.217.22.14
youtube-ui.l.google.com. 300	IN	A	216.58.206.14
youtube-ui.l.google.com. 300	IN	A	216.58.207.46
youtube-ui.l.google.com. 300	IN	A	172.217.16.174
youtube-ui.l.google.com. 300	IN	A	216.58.208.46
;; Received 304 bytes from 216.239.36.10#53(ns3.google.com) in 41 ms
```

Just as with the first example `dig` first deals with the root domain servers
in the lines 2 through 16.

From them it's refered to the `de` top level domain in the lines 18 through 24.

After that the nameservers handling the `youtube.de` domain in the lines 26
through 30.

Now something more interesting happens: `dig` reaches the target server in line
32 with the `www` subdomain on `youtube.de`, but the output continues. Turns
out, 'www.youtube.de' isn't actually the domain name of the server we're
looking for.  `dig` outputs `CNAME` in line 32, which tells us the "canonical
name" of the domain we query. So the domain `youtube-ui.l.google.com` is the
actual name of `www.youtube.de`, and that's where `dig` starts looking around
in the lines 32 through 47. It seems as though `dig` is talking to google's own
domain name servers here, until it finds the ip address of a server hosting
youtube, that it's satisfied with (one for `.de`-youtube).
