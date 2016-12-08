SUMMARY = "Copies WVSNP Dashboard files and Compiles Scripts"
DESCRIPTION = "WVSNP Dashboard"
MY_FILES = "${BSPDIR}/sources/meta-wvsnp-pkgs/recipes-packages/dashboard/files"

do_install() {
install -d ${D}/home/root/
install -m 0775 ${MY_FILES} ${D}/home/root/
}
FILES_${PN} += "/home/root/"

$CC buttonfunctions.c -o ../www/CGI/buttonfunctions.cgi cgic.c -lxbee -pthread -lm -I /usr/lib/ -L /usr/lib

