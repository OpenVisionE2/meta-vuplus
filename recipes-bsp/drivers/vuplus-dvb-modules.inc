DESCRIPTION = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

PV = "${KV}+${SRCDATE}"

SRC_URI = "http://code.vuplus.com/download/release/vuplus-dvb-modules/vuplus-dvb-modules-${MACHINETYPE}-${KV}-${SRCDATE}.tar.gz"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

FILES_${PN} = "/"

do_install() {
	install -d ${D}${nonarch_base_libdir}/modules/${KV}/extra
	for f in *.ko; do
		install -m 0644 ${WORKDIR}/$f ${D}${nonarch_base_libdir}/modules/${KV}/extra/$f;
	done
	install -d ${D}${sysconfdir}/modules-load.d
	for i in `ls | grep \\.ko | sed -e 's/.ko//g'`; do
		echo $i >> ${D}${sysconfdir}/modules-load.d/_vuplus.conf
	done
}

pkg_postinst_${PN} () {
        if [ -d /proc/stb ]; then
		depmod -a
        fi
        true
}

FILESEXTRAPATHS_prepend := "${THISDIR}/vuplus-dvb-modules:"
