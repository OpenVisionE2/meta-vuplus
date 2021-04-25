SUMMARY = "shared library for E2 animation"
SECTION = "libs"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

PV = "0.1.1"

PR = "${SRCDATE}.${SRCDATE_PR}"

INHIBIT_PACKAGE_STRIP = "1"

S = "${WORKDIR}/libvugles2-${PV}"

inherit pkgconfig

do_install() {
	install -d ${D}${includedir}
	cp -r ${S}/include/* ${D}${includedir}/
	install -d ${D}${libdir}
	cp -r ${S}/lib/*.so ${D}${libdir}/
	install -d ${D}${libdir}/pkgconfig
	cp -r ${S}/lib/pkgconfig/*.pc ${D}${libdir}/pkgconfig/
}

PACKAGES = "${PN}"
FILES_${PN}="${libdir} ${incdir}"
