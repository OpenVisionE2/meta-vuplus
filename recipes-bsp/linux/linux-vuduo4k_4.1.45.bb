require linux-vuplus-4.1.45.inc

KSRC_VER = "4.1-1.17"

SRC_URI += " \
	file://bcmsysport_4_1_45.patch \
	file://linux_usb_hub.patch \
"

COMPATIBLE_MACHINE = "vuduo4k"
