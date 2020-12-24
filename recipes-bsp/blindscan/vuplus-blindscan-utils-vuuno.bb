require vuplus-blindscan-utils.inc

do_install() {
        install -d "${D}${bindir}"
        for f in ${PLUGABLE_MODEL_BLINDSCAN}; do
                install -m 0755 "${S}/$f" "${D}${bindir}"
        done
}

COMPATIBLE_MACHINE = "^(vuuno)$"
