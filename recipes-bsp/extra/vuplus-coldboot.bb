DESCIPTION = "S3 cold boot"
MAINTAINER = "vuplus team"
LICENSE = "CLOSED"

SRCDATE="20140925_p0"

PR = "${SRCDATE}_r1"
SRC_REV = ""

SRC_URI = "http://archive.vuplus.com/openpli-support/vuplus-coldboot_${SRCDATE}.tar.gz"

do_install() {
	install -d ${D}${sysconfdir}/init.d \
		${D}${bindir} \
        	${D}${sysconfdir}/rc0.d 

	install -m 0755 ${WORKDIR}/${PN}/coldboot.sh ${D}${sysconfdir}/init.d/coldboot.sh
	install -m 0755 ${WORKDIR}/${PN}/ethwol.sh ${D}${sysconfdir}/init.d/ethwol.sh
	install -m 0755 ${WORKDIR}/${PN}/coldboot ${D}${bindir}/coldboot
        ln -sf   ../init.d/coldboot.sh ${D}${sysconfdir}/rc0.d/S30coldboot.sh
	ln -sf   ../init.d/ethwol.sh ${D}${sysconfdir}/rc0.d/K32ethwol.sh
}

SRC_URI[md5sum] = "5473742bec9c267128c453af8d924821"
SRC_URI[sha256sum] = "f6dd256f57a4a417169548dc041acc1bb18c73b193fe8b72503f17c3f436923c"
