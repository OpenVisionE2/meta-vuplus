require linux-vuplus-3.14.28.inc

SRC_URI += "\
	file://linux_rpmb_not_alloc.patch \
"

COMPATIBLE_MACHINE = "vusolo4k"
