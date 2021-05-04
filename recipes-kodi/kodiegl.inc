SECTION = "base"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PR = "${PKGDATE}"

PROVIDES += "kodiegl"
RPROVIDES_${PN} += "kodiegl"

SRC_URI = "http://code.vuplus.com/download/release/kodi/KodiGLESPL_${MACHINE}_${PKGDATE}.tar.gz"

S = "${WORKDIR}/KodiGLESPL_${MACHINE}"

do_install() {
	install -d ${D}${bindir}
	install -m 0755 ${S}/bin/* ${D}${bindir}

	install -d ${D}${libdir}
	install -m 0755 ${S}/lib/*.so ${D}${libdir}

	install -d ${D}${incdir}
	install -m 0755 ${S}/include/*.h ${D}${incdir}
}

do_package_qa() {
}

INHIBIT_PACKAGE_STRIP = "1"

FILES_${PN}="${libdir} ${bindir}"
FILES_${PN}-dev = "${includedir}"

PACKAGE_ARCH = "${MACHINE}"
