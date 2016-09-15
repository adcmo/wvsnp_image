DESCRIPTION = "Mongoose is the most easy to use web server on the planet"
SECTION = "libs"
LICENSE = "GPLv2"
HOMEPAGE = "http://code.google.com/p/mongoose"

LIC_FILES_CHKSUM ="file://${COREBASE}/meta/COPYING.GPLv2;md5=751419260aa954499f7abaabaa882bbe"

PR = "r0"
SRC_URI = "git://github.com/cesanta/mongoose.git"
SRCREV = "b28662362de16dfc86ab46123e0ce963e8106916"
 
S = "${WORKDIR}/git"
 
CFLAGS += "-W -Wall -I.. -pthread -g -pipe -fpic"
 
do_compile() {

      ${CC} ${CFLAGS} -c mongoose.c -o mongoose.o
      ${CC} -shared -o libmongoose.so mongoose.o
      ${AR} rcs libmongoose.a mongoose.o

	    cd 'examples/web_server'
      make
}
 
do_install() {
     install -d ${D}${libdir}
     install -d ${D}${includedir}
     install -d ${D}${bindir}
     install -m 0755 libmongoose.so ${D}${libdir}
     install -m 0755 mongoose.h ${D}${includedir}
     install -m 0755 libmongoose.a ${D}${libdir}
     install -m 0755 examples/web_server/web_server ${D}${bindir}
}

FILES_${PN} = "${libdir}"
FILES_${PN} += "${bindir}"
FILES_${PN}-dev = "${includedir}"
