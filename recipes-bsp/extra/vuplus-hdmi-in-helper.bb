SUMMARY = "VuPlus HDMI-In helper"
PRIORITY = "required"
LICENSE = "CLOSED"
LIC_FILES_CHKSUM = "file://update_systemconfig_arm;md5=39018f970452e01743a00a4ff642c099"

COMPATIBLE_MACHINE = "^(vuuno4kse|vuultimo4k|vuduo4k|vuduo4kse)$"


SRC_URI = " \
    file://update_systemconfig_arm \
    file://update_systemconfig.sh \
"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${sysconfdir}/init.d/
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/update_systemconfig_arm -f ${D}${bindir}/update_systemconfig
    install -m 0755 ${WORKDIR}/update_systemconfig.sh ${D}${sysconfdir}/init.d/
}

inherit update-rc.d

INITSCRIPT_NAME = "update_systemconfig.sh"
INITSCRIPT_PARAMS = "start 90 3 ."
