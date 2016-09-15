SUMMARY = "A minimum image with all required packages for WVSNP video-streaming."

LICENSE = "MIT"

inherit core-image

DISTRO_FEATURES += " \
    pulseaudio \
    bluetooth \
    wifi \
"

IMAGE_FEATURES += " \
    hwcodecs \
    tools-debug \
"

CORE_IMAGE_EXTRA_INSTALL += " \
    wvsnp-startupscripts \
    btpkg \
    packagegroup-fsl-gstreamer1.0 \
    packagegroup-fsl-gstreamer1.0-full \
    packagegroup-fsl-tools-gpu \
    packagegroup-fsl-tools-gpu-external \
    packagegroup-wandboard-ap-test \
    screen \
    openssh \
    vsftpd \
    bash \
    imx-test \
    x264 \
    nano \
    libxbee \
    libmongoose \
"
