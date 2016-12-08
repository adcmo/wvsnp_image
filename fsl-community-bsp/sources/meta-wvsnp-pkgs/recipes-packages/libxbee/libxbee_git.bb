DDESCRIPTION = "A C/C++ library to aid the use of Digi XBee radios in API mode."
SECTION = "base"
HOMEPAGE = "http://code.google.com/p/libxbee/"
LICENSE = "LGPLv3"
LIC_FILES_CHKSUM = "file://COPYING;md5=d32239bcb673463ab874e80d47fae504"

SRC_URI = "git://github.com/attie/libxbee3.git;protocol=git"
SRCREV = "76d63381f85fad014a5b858256aa4c9d1905ad98"

S = "${WORKDIR}/git/"

PR = "r1"
export CROSS_COMPILE="${TARGET_PREFIX}"
export GCC="${CC} -fPIC"
export GXX="${CXX} -fPIC"

do_configure() {

  oe_runmake configure
}

do_compile() {
  oe_runmake all
}

do_install () {
	install -d ${D}/usr/share/man/man3
	install -d ${D}${libdir}
	install -m 0755 ${S}/xbee.h ${D}${libdir}
	oe_runmake install SYS_ROOT=${D}
}

FILES_${PN} += "/usr/share/man/man3/"
FILES_${PN} += "${libdir}/"

