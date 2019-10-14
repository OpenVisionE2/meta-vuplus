SRCDATE = "20180213"
SRCDATE_PR = "r1"

SRC_URI[md5sum] = "a29664f4237b76c127e39d65324708f2"
SRC_URI[sha256sum] = "4de339d696b6326c1ac7702fef4ab15784ce2f8b2a2fcf98fceb9a598f1dc537"

require libvugles2.inc

COMPATIBLE_MACHINE = "^(vusolo4k)$"

SRC_URI = "http://archive.vuplus.com/download/build_support/vuplus/libvugles2-0.1.1-${MACHINE}-${PR}.tar.gz file://LICENSE-CLOSE"
