SUMMARY = "libgles for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

PV = "15.1"

PR = "${SRCDATE}.${SRCDATE_PR}"

PROVIDES = "virtual/libgles2 virtual/egl"
PROVIDES += "libgles"
RPROVIDES_${PN} += "libgles"

SRC_URI = "http://code.vuplus.com/download/release/libgles/libgles-${MACHINE}-${PV}-${PR}.tar.gz"

S = "${WORKDIR}/libgles-${MACHINE}"

INHIBIT_PACKAGE_STRIP = "1"
PRIVATE_LIBS_${PN} = "libEGL.so \
libv3ddriver.so \
libGLESv2.so"

do_install() {
	install -d ${D}${libdir}
	install -m 0755 ${S}${base_libdir}/*.so ${D}${libdir}
	ln -s libv3ddriver.so ${D}${libdir}/libEGL.so
	ln -s libv3ddriver.so ${D}${libdir}/libGLESv2.so
	install -d ${D}${includedir}
	cp -fa ${S}/include/* ${D}${includedir}/
}

do_package_qa() {
}

FILES_${PN} = "${libdir}/*"
FILES_${PN}-dev = "${incdir}/*"
