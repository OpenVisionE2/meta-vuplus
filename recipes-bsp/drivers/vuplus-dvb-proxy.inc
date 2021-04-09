DESCRIPTION = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

PV ?= "${KV}"
PR = "${SRCDATE}.${SRCDATE_PR}"

SRC_URI = "http://code.vuplus.com/download/release/vuplus-dvb-proxy/vuplus-dvb-proxy-${MACHINE}-${PV}-${PR}.tar.gz "

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

do_compile() {
}

do_populate_sysroot() {
}

do_install() {
        install -d ${D}${nonarch_base_libdir}/modules/${KV}/extra
        for f in *.ko; do
                install -m 0644 ${WORKDIR}/$f ${D}${nonarch_base_libdir}/modules/${KV}/extra/$f;
        done
}

PACKAGE_ARCH = "${MACHINE_ARCH}"

FILES_${PN} = "/"
