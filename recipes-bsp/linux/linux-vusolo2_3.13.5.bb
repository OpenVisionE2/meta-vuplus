require linux-vuplus-3.13.5.inc

SRC_URI += " \
	file://linux-bcm_ethernet.patch \
"

COMPATIBLE_MACHINE = "vusolo2"
