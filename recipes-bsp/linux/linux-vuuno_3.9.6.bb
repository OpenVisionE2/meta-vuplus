require linux-vuplus-3.9.6.inc

SRC_URI += "\
	file://linux-sata_bcm.patch \
	"

COMPATIBLE_MACHINE = "vuuno"
