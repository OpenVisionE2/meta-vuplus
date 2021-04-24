require libvugles2-${MACHINE}.inc

SRC_URI = "http://code.vuplus.com/download/release/libvugles2/${BPN}-${PV}-${MACHINE}-${PR}.tar.gz"

COMPATIBLE_MACHINE = "^(vusolo4k|vuuno4k|vuuno4kse|vuultimo4k|vuzero4k|vuduo4k|vuduo4kse)$"
