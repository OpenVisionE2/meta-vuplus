 SRCDATE = "20180213"
SRCDATE_PR = "r1"

SRC_URI[md5sum] = "9ba4be4c4492fa2519ea0347a5c61495"
SRC_URI[sha256sum] = "fe53cebb04a12632c76e9adfdabd61364643e47a8620cee92043a091e792eb6f"

require libvugles2.inc

COMPATIBLE_MACHINE = "vuzero4k"

SRC_URI = "http://archive.vuplus.com/download/build_support/vuplus/libvugles2-0.1.1-${MACHINE}-${PR}.tar.gz file://LICENSE-CLOSE"
