SUMMARY = "Copies bluetooth scripts and firmware"
DESCRIPTION = "BTPKG"
HOMEPAGE = ""
LICENSE = "CLOSED"
MY_FILES = "${BSPDIR}/sources/meta-wvsnp-pkgs/recipes-packages/btpkg/files/brcm_patchram_plus \
${BSPDIR}/sources/meta-wvsnp-pkgs/recipes-packages/btpkg/files/simple-agent \
"

MY_FILES1 = "${BSPDIR}/sources/meta-wvsnp-pkgs/recipes-packages/btpkg/files/bcm4330.hcd \
"

do_install() {
install -d ${D}${bindir}
install -m 0755 ${MY_FILES} ${D}${bindir}
install -d ${D}${base_libdir}/firmware/brcm/
install -m 0644 ${MY_FILES1} ${D}${base_libdir}/firmware/brcm/
}
FILES_${PN} += "${bindir}"
FILES_${PN} += "${base_libdir}/firmware/brcm/"
