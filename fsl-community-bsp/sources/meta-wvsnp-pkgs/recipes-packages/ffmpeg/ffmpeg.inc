DESCRIPTION = "FFmpeg is a complete solution to record, convert and stream audio and video"
HOMEPAGE = "http://ffmpeg.mplayerhq.hu/"
AUTHOR = "Fabrice Bellard ffmpeg-devel@mplayerhq.hu"
SECTION = "libs"
PRIORITY = "optional"
LICENSE = "GPLv2+ & LGPLv2.1+"


ARM_INSTRUCTION_SET = "arm"
DEPENDS = "zlib libogg yasm-native"
INC_PR = "r8"


inherit autotools pkgconfig


S = "${WORKDIR}/git"


FULL_OPTIMIZATION_armv7a = "-fexpensive-optimizations -fomit-frame-pointer -O4 -ffast-math"
BUILD_OPTIMIZATION = "${FULL_OPTIMIZATION}"


EXTRA_FFCONF_armv7a = "--cpu=cortex-a9"
EXTRA_FFCONF ?= ""


PACKAGECONFIG ??= "bzip2 x264 theora ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11', '', d)}"
PACKAGECONFIG[bzip2] = "--enable-bzlib,--disable-bzlib,bzip2"
PACKAGECONFIG[faac] = "--enable-libfaac,--disable-libfaac,faac"
PACKAGECONFIG[gsm] = "--enable-libgsm,--disable-libgsm,libgsm"
PACKAGECONFIG[jack] = "--enable-indev=jack,--disable-indev=jack,jack"
PACKAGECONFIG[libvorbis] = "--enable-libvorbis,--disable-libvorbis,libvorbis"
PACKAGECONFIG[mp3lame] = "--enable-libmp3lame,--disable-libmp3lame,lame"
PACKAGECONFIG[openssl] = "--enable-openssl,--disable-openssl,openssl"
PACKAGECONFIG[schroedinger] = "--enable-libschroedinger,--disable-libschroedinger,schroedinger"
PACKAGECONFIG[speex] = "--enable-libspeex,--disable-libspeex,speex"
PACKAGECONFIG[theora] = "--enable-libtheora,--disable-libtheora,libtheora"
PACKAGECONFIG[vpx] = "--enable-libvpx,--disable-libvpx,libvpx"
PACKAGECONFIG[x11] = "--enable-x11grab,--disable-x11grab,virtual/libx11 libxfixes libxext xproto virtual/libsdl"
PACKAGECONFIG[x264] = "--enable-libx264,--disable-libx264,x264"


# Check codecs that require --enable-nonfree
USE_NONFREE = "${@bb.utils.contains_any('PACKAGECONFIG', [ 'faac', 'openssl' ], 'yes', '', d)}"


EXTRA_OECONF = " \
    --enable-shared \
    --enable-pthreads \
    --enable-gpl \
    ${@bb.utils.contains('USE_NONFREE', 'yes', '--enable-nonfree', '', d)} \
    --enable-avfilter \
    \
    --cross-prefix=${TARGET_PREFIX} \
    --prefix=${prefix} \
    \
    --enable-ffserver \
    --enable-ffplay \
    --ld="${CCLD}" \
    --arch=${TARGET_ARCH} \
    --target-os="linux" \
    --enable-cross-compile \
    --extra-cflags="${TARGET_CFLAGS} ${HOST_CC_ARCH}${TOOLCHAIN_OPTIONS}" \
    --extra-ldflags="${TARGET_LDFLAGS}" \
    --sysroot="${STAGING_DIR_TARGET}" \
    --enable-hardcoded-tables \
    ${EXTRA_FFCONF} \
    --libdir=${libdir} \
    --shlibdir=${libdir} \
"


do_configure() {
    # We don't have TARGET_PREFIX-pkgconfig
    ${S}/configure ${EXTRA_OECONF}
}


do_install_append() {
    #install -m 0644 ${S}/libavfilter/*.h ${D}${includedir}/libavfilter/
}


FFMPEG_LIBS = "libavcodec libavdevice libavformat \
               libavutil libpostproc libswscale libavfilter"


PACKAGES += "${PN}-vhook-dbg ${PN}-vhook ffmpeg-x264-presets"


RSUGGESTS_${PN} = "mplayer"
FILES_${PN} = "${bindir}"
FILES_${PN}-dev = "${includedir}/${PN}"


FILES_${PN}-vhook = "${libdir}/vhook"
FILES_${PN}-vhook-dbg += "${libdir}/vhook/.debug"


FILES_ffmpeg-x264-presets = "${datadir}/*.avpreset"


LEAD_SONAME = "libavcodec.so"


FILES_${PN}-dev = "${includedir}"


python populate_packages_prepend() {
    av_libdir = d.expand('${libdir}')
    av_pkgconfig = d.expand('${libdir}/pkgconfig')


    # Runtime package
    do_split_packages(d, av_libdir, '^lib(.*)\.so\..*',
                      output_pattern='lib%s',
                      description='libav %s library',
                      extra_depends='',
                      prepend=True,
                      allow_links=True)


    # Development packages (-dev, -staticdev)
    do_split_packages(d, av_libdir, '^lib(.*)\.so$',
                      output_pattern='lib%s-dev',
                      description='libav %s development package',
                      extra_depends='${PN}-dev',
                      prepend=True,
                      allow_links=True)
    do_split_packages(d, av_pkgconfig, '^lib(.*)\.pc$',
                      output_pattern='lib%s-dev',
                      description='libav %s development package',
                      extra_depends='${PN}-dev',
                      prepend=True)
    do_split_packages(d, av_libdir, '^lib(.*)\.a$',
                      output_pattern='lib%s-staticdev',
                      description='libav %s development package - static library',
                      extra_depends='${PN}-dev',
                      prepend=True,
                      allow_links=True)


    if d.getVar('TARGET_ARCH', True) == 'i586':
        # libav can't be build with -fPIC for 32-bit x86
        pkgs = d.getVar('PACKAGES', True).split()
        for pkg in pkgs:
            d.appendVar('INSANE_SKIP_%s' % pkg, ' textrel')
}


PACKAGES_DYNAMIC += "^lib(av(codec|device|filter|format|util)|postproc|swscale).*"
