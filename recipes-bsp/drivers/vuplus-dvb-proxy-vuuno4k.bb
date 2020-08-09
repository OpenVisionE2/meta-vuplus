require vuplus-dvb-proxy.inc

SRCDATE = "20190424"
SRCDATE_PR = "r0"

pkg_postinst_${PN}_append () {
	if [ ! -f $D${base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko ]; then
		ln -s ${base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm7252s.ko $D${base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko
	fi
}

SRC_URI[md5sum] = "8235ee080aa92adb86004d2e4f7130c6"
SRC_URI[sha256sum] = "d3be31f502b4477091022717f1f48f7e3cae9c75be7f74ec796fb1458bc6882f"

COMPATIBLE_MACHINE = "^(vuuno4k)$"
