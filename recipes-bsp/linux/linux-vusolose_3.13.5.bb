require linux-vuplus-3.13.5.inc

SRC_URI += " \
	file://brcm_s3_wol.patch \
	file://linux_mtd_bbt_maxblock.patch \
"

COMPATIBLE_MACHINE = "vusolose"
