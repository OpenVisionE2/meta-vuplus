SRCDATE = "20181109"
SRCDATE_PR = "r1"

SRC_URI[md5sum] = "f1601fc0f7324fbf8a8eedf8f34a9b59"
SRC_URI[sha256sum] = "a2c6d18e970a8d8b390159239f7e8d5bf8b5ec7d55ca14008c90ea4278705242"

require libvugles2.inc

COMPATIBLE_MACHINE = "^(vuduo4k)$"

SRC_URI = "http://archive.vuplus.com/download/build_support/vuplus/libvugles2-0.1.1-${MACHINE}-${PR}.tar.gz file://LICENSE-CLOSE"
