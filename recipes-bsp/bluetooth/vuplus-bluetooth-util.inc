SECTION = "base"
LICENSE = "CLOSED"
#require conf/license/license-close.inc

PR="${SRCDATE}.${SRCDATE_PR}"

SRC_URI = " \
    http://archive.vuplus.com/download/build_support/vuplus/vuplus-bluetooth-util-${MACHINE}-${PR}.tar.gz \
"

S="${WORKDIR}/vuplus-bluetooth-util-${MACHINE}"

do_install() {
	install -d ${D}${bindir}
	install -m 0755 ${S}/* ${D}${bindir}
}

do_package_qa() {
}

PACKAGE_ARCH := "${MACHINE_ARCH}"
FILES_${PN}="/"

do_install() {
	install -d ${D}${bindir}
	install -m 0755 ${S}/bsa_server ${D}${bindir}

	install -d ${D}${prefix}/local/modules
	install -m 0644 ${S}/btusb.ko ${D}${prefix}/local/modules/btusb.ko
	install -m 0644 ${S}/bthid.ko ${D}${prefix}/local/modules/bthid.ko

	if [ -n "${FIRMWARE_FILE}" ]; then
		install -d ${D}${base_libdir}/firmware/${FIRMWARE_PATH}
		install -m 0644 ${S}/${FIRMWARE_FILE} ${D}${base_libdir}/firmware/${FIRMWARE_PATH}
	fi
}

