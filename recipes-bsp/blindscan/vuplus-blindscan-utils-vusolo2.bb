require vuplus-blindscan-utils.inc

do_install() {
	install -d "${D}${bindir}"
	install -m 0755 "${S}/tda1002x" "${D}${bindir}"
	install -m 0755 "${S}/vuplus_bcm7346_blindscan" "${D}${bindir}"
}

BLINDSCAN_BINARY = "vuplus_bcm7346_blindscan"
