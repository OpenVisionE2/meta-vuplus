require bluetoothsetup.inc

PROVIDES += "vuplus-bluetooth-util"
RPROVIDES_${PN} += "vuplus-bluetooth-util"

COMPATIBLE_MACHINE = "vuduo4k"

SRCDATE = "20181109"
SRCDATE_PR = "r1"

SRC_URI[md5sum] = "e361db36f21cf1d5a17cc82d720510e2"
SRC_URI[sha256sum] = "2a6c7687f470210f69758fed6240f8b99728a78e4a9283f47c8c57495ee39fb7"
