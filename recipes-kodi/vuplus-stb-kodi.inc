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
