require ffmpeg.inc
LICENSE = "LGPLv2.1+ & GPLv2+"
PR = "r0"
SRC_URI = "git://source.ffmpeg.org/ffmpeg.git"
DEFAULT_PREFERENCE = "1"

SRCREV="7905bd55557323f72c00bf51a6a5cceabd3e81e5"


PV = "git${SRCPV}"
LIC_FILES_CHKSUM = "file://COPYING.GPLv2;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
file://COPYING.LGPLv2.1;md5=bd7a443320af8c812e4c18d1b79df004"


PROVIDES += "libav libpostproc ffmpeg"
EXTRA_OECONF += " \
    --enable-postproc \
"
