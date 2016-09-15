SUMMARY = "Copies startup Scripts for the wandboard"
DESCRIPTON = "Startup scripts"
HOMEPAGE = ""
LICENSE = "CLOSED"
PR = "r0"

SRC_URI = "              \
   file://enablebt.sh \
   file://mongoose \
   "

do_install() {
    install -d ${D}${sysconfdir}/init.d
    install -d ${D}${sysconfdir}/rcS.d
    install -d ${D}${sysconfdir}/rc1.d
    install -d ${D}${sysconfdir}/rc2.d
    install -d ${D}${sysconfdir}/rc3.d
    install -d ${D}${sysconfdir}/rc4.d
    install -d ${D}${sysconfdir}/rc5.d
    ln -sf ../init.d/enablebt.sh  ${D}${sysconfdir}/rc5.d/S90enable-bluetooth
    ln -sf ../init.d/mongoose  ${D}${sysconfdir}/rc5.d/S90mongoose
}
