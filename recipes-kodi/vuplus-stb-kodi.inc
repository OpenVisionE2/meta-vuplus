require recipes-mediacenter/kodi/stb-kodi_19.bb

DEPENDS += "kodiegl"
RDEPENDS_${PN} += "kodiegl"

PROVIDES += "virtual/kodi"
RPROVIDES_${PN} += "virtual/kodi"
PROVIDES += "kodi"
RPROVIDES_${PN} += "kodi"

EXTRA_OECMAKE += " \
    -DWITH_PLATFORM=vuplus-cortexa15 \
    -DWITH_FFMPEG=stb \
"

SRC_URI_append = " file://KodiGLESPL.h"

do_compile_prepend() {
	install -m 0644 ${WORKDIR}/KodiGLESPL.h ${S}/xbmc/windowing/egl/
}
