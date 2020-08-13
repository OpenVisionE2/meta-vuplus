require vuplus-dvb-proxy.inc

SRCDATE = "20190429"
SRCDATE_PR = "r0"

pkg_postinst_${PN}_append () {
	if [ ! -f $D${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko ]; then
		ln -s ${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm7424.ko $D${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/dvb-bcm.ko
	fi
}

SRC_URI[md5sum] = "42b7bcba72ea9313ba80e8dd769c5c15"
SRC_URI[sha256sum] = "2cbbf91b7659de762182e8a6ee7b7ab0f6389a67fec13df21fb508dce92a7fdf"

COMPATIBLE_MACHINE = "^(vuduo2)$"