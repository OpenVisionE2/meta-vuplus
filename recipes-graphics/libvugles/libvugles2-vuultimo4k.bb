SRCDATE = "20180213"
SRCDATE_PR = "r1"

SRC_URI[md5sum] = "54e0e745e24fd3a42e1a0993fe59a605"
SRC_URI[sha256sum] = "d0a35911adb933919988c53896e32935b3034b41f2daded2ebd8c167adc21ce2"

require libvugles2.inc

COMPATIBLE_MACHINE = "^(vuultimo4k)$"

SRC_URI = "http://archive.vuplus.com/download/build_support/vuplus/libvugles2-0.1.1-${MACHINE}-${PR}.tar.gz file://LICENSE-CLOSE"
