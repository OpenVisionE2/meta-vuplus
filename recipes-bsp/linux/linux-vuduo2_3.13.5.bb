require linux-vuplus-3.13.5.inc

SRC_URI += " \
	file://brcm_s3_wol.patch \
"

COMPATIBLE_MACHINE = "vuduo2"
