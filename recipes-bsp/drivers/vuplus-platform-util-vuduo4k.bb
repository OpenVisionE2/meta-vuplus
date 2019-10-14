require vuplus-platform-util.inc

RDEPENDS_${PN} += "gptfdisk mmc-utils"

PV="18.1"
SRCDATE = "20191014"
SRCDATE_PR = "r0"

SRC_URI += "\
	file://bp3flash.tar.gz \
"

do_install_append() {
	install -m 0755 ${WORKDIR}/bp3flash.py ${D}${bindir}
}

SRC_URI[md5sum] = "72eebdf84230f6eed7bf470c45d8110d"
SRC_URI[sha256sum] = "25a237ca401595b4ee765f8839dd86d696df34d9f60b23aac84f69ac102fbb25"

COMPATIBLE_MACHINE = "^(vuduo4k)$"
