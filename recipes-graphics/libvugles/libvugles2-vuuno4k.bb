SRCDATE = "20180213"
SRCDATE_PR = "r1"

SRC_URI[md5sum] = "e3dca0a7889a71ffbd13e69504c9f4ca"
SRC_URI[sha256sum] = "42e6adb2670ac1268a481a0e6dc043e173b79ff856e6d3a1ec9a982e235b1a42"

require libvugles2.inc

COMPATIBLE_MACHINE = "vuuno4k"

SRC_URI = "http://archive.vuplus.com/download/build_support/vuplus/libvugles2-0.1.1-${MACHINE}-${PR}.tar.gz"
