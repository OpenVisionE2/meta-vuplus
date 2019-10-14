require vuplus-dvb-proxy.inc

KV = "4.1.45"

SRCDATE = "20191014"
SRCDATE_PR = "r0"

pkg_postinst_${PN}_append () {
	if [ ! -f $D/lib/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko ]; then
		ln -s /lib/modules/${KERNEL_VERSION}/extra/dvb-bcm7278.ko $D/lib/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko
	fi
}

SRC_URI[md5sum] = "1164965d7320771be5759ee5529a4356"
SRC_URI[sha256sum] = "aa29212c412eb538ad7897701589f5b8f692b660b9d0d2ca4be9a08118b5eece"

COMPATIBLE_MACHINE = "vuduo4k"
