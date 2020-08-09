require vuplus-dvb-proxy.inc

SRCDATE = "20190424"
SRCDATE_PR = "r0"

pkg_postinst_${PN}_append () {
	if [ ! -f $D${base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko ]; then
		ln -s ${base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm72604.ko $D${base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko
	fi
}

SRC_URI[md5sum] = "c5f4bcc8607e40f10ee13b57edda679c"
SRC_URI[sha256sum] = "7bb60699a9f3db7dc70d11559157cb07c0a6288785eb612096a472edb2004ea2"

COMPATIBLE_MACHINE = "^(vuzero4k)$"
