LICENSE = "CLOSED"
SUMMARY = "Copies WVSNP Dashboard files and Compiles Scripts"
DESCRIPTION = "WVSNP Dashboard"

SRC_URI = "file://wvsnp_dashboard_${PV}.tar.gz"
S = "${WORKDIR}/wvsnp_dashboard_${PV}"
#inherit autotools
INHIBIT_PACKAGE_STRIP = "1"
do_configure_append() {
}

do_compile_append() {
}

do_install_append() {
install -d ${D}/home/root/
cp -r ${S}/ ${D}/home/root/
}
FILES_${PN} += "/home/root/wvsnp_dashboard_${PV}"
