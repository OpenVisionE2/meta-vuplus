do_configure_prepend() {
	cp -av ${WORKDIR}/xbmc-support/gles_init.* ${S}/xbmc/windowing/egl/
}

do_install_append(){
	install -d ${D}${bindir}
	install -m 0755 ${WORKDIR}/xbmc-support/xbmc.helper ${D}${bindir}
	install -m 0755 ${WORKDIR}/xbmc-support/libxbmc_base.so ${D}${libdir}
}

FILES_${PN}_append = "${bindir}/xbmc.helper ${libdir}/libxbmc_base.so"

require recipes-mediacenter/kodi/stb-kodi_19.bb

PROVIDES += "virtual/kodi"
RPROVIDES_${PN} += "virtual/kodi"
PROVIDES += "kodi"
RPROVIDES_${PN} += "kodi"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append += "http://code.vuplus.com/download/release/kodi/xbmc-support_${MACHINE}_${GLPR}.tar.gz;name=xbmc-support"

EXTRA_OECMAKE += " \
    -DWITH_PLATFORM=vuplus-mipsel \
    -DWITH_FFMPEG=stb \
"
