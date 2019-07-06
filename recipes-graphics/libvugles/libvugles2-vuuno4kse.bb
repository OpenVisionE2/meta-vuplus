 SRCDATE = "20180213"
SRCDATE_PR = "r1"

SRC_URI[md5sum] = "c25f1899127b80475d9454546cf70c3e"
SRC_URI[sha256sum] = "04db596128ca64a3fa429b9f0181254b49867631d11db4803c15972e22311000"

require libvugles2.inc

COMPATIBLE_MACHINE = "vuuno4kse"

SRC_URI = "http://archive.vuplus.com/download/build_support/vuplus/libvugles2-0.1.1-${MACHINE}-${PR}.tar.gz file://LICENSE-CLOSE"
