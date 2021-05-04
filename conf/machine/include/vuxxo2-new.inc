require conf/machine/include/vuxxo2.inc

PREFERRED_PROVIDER_virtual/egl ?= "libgles-${MACHINE}"
PREFERRED_PROVIDER_virtual/libgles2 ?= "libgles-${MACHINE}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	libgles-${MACHINE} \
	libvupl-${MACHINE} \
	libvugles2-mipsel \
	"

MACHINE_FEATURES += "transcoding streamproxy blindscan-dvbs ctrlrc ci dvbproxy RCA"
