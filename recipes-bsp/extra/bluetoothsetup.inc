DESCRIPTION = "Vuplus bluetooth plugin"

LICENSE = "CLOSED"

DEPENDS = "python-native"
RDEPENDS_${PN} = "vuplus-bluetooth-util-${MACHINE} libusb-compat"

PR = "${SRCDATE}.${SRCDATE_PR}"

SRC_URI = " \
    http://archive.vuplus.com/download/build_support/vuplus/enigma2-plugin-bluetoothsetup-${MACHINE}-${PR}.tar.gz \
"

S = "${WORKDIR}/plugin"

BLUETOOTH_PLUGIN_PATH = "${libdir}/enigma2/python/Plugins/SystemPlugins/BluetoothSetup"

do_compile() {
	python2 -O -m compileall ${S}
}

do_install() {
	install -d  ${D}${BLUETOOTH_PLUGIN_PATH}
	cp -r --preserve=mode,links ${S}/* ${D}${BLUETOOTH_PLUGIN_PATH}
}

FILES_${PN} = "${BLUETOOTH_PLUGIN_PATH}"

do_populate_sysroot[noexec] = "1"

PACKAGE_ARCH = "${MACHINE_ARCH}"

