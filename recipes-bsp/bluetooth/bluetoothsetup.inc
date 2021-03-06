DESCRIPTION = "Vuplus bluetooth plugin"
PRIORITY = "required"
LICENSE = "CLOSED"

inherit compile_python_pyo

DEPENDS = "python-native"
RDEPENDS_${PN} = "vuplus-bluetooth-util-${MACHINE} libusb-compat"

PR = "${SRCDATE}.${SRCDATE_PR}"

SRC_URI = " \
    http://code.vuplus.com/download/release/bt/enigma2-plugin-bluetoothsetup-${MACHINE}-${PR}.tar.gz \
"

S = "${WORKDIR}/plugin"

BLUETOOTH_PLUGIN_PATH = "${libdir}/enigma2/python/Plugins/SystemPlugins/BluetoothSetup"

do_install() {
	install -d  ${D}${BLUETOOTH_PLUGIN_PATH}
	cp -fr --preserve=mode,links ${S}/* ${D}${BLUETOOTH_PLUGIN_PATH}
}

FILES_${PN} = "${BLUETOOTH_PLUGIN_PATH}"

do_populate_sysroot[noexec] = "1"

PACKAGE_ARCH = "${MACHINE_ARCH}"
