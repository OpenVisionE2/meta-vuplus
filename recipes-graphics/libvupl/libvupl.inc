DESCRIPTION = "Vu+ API for EGL/OpenGLES"
SECTION = "libs"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

SRCDATE_PR = "r1"
PV = "0.1.0"

RDEPENDS_${PN} = "libgles-${MACHINE}"

PROVIDES += "libvupl"
RPROVIDES_${PN} += "libvupl"

PR = "${SRCDATE}.${SRCDATE_PR}"

SRC_URI = "http://code.vuplus.com/download/release/libvupl/libvupl-${PV}-${MACHINE}-${PR}.tar.gz"

INHIBIT_PACKAGE_STRIP = "1"

S = "${WORKDIR}/libvupl-${PV}-${MACHINE}"

inherit pkgconfig

do_install() {
	install -d ${D}${includedir}
	install -m 644 ${S}/include/* ${D}${includedir}/
	install -d ${D}${libdir}
	install -m 755 ${S}/lib/*.so ${D}${libdir}/
	install -d ${D}${libdir}/pkgconfig
	cp -r ${S}/lib/pkgconfig/*.pc ${D}${libdir}/pkgconfig/
}

do_package_qa() {
}

PACKAGES = "${PN}"
FILES_${PN}="${libdir} ${incdir}"
