SECTION = "base"
LICENSE = "CLOSED"
PRIORITY = "required"

SRC_URI = "http://code.vuplus.com/download/release/kernel/vmlinuz-initrd_${MACHINE}_${SRCDATE}.tar.gz"

FILES_${PN} = "/boot"

INHIBIT_PACKAGE_STRIP = "1"
PACKAGE_ARCH = "${MACHINE_ARCH}"
