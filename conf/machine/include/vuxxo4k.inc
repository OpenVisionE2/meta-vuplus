# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	${@bb.utils.contains("MACHINE_FEATURES", "dvbproxy", "vuplus-dvb-proxy-${MACHINE} libgles-${MACHINE} vuplus-platform-util-${MACHINE}", "vuplus-dvb-modules-${MACHINE}", d)} \
	gstreamer1.0-libav \
	kernel-module-rtl8192cu \
	firmware-rtl8192cu \
	firmware-rtl8192cufw \
	vuplus-tuner-turbo \
	"


MACHINE_EXTRA_RRECOMMENDS += "\
	vuplus-shutdown \
	gstreamer1.0-plugin-dvbmediasink \
	"

EXTRA_IMAGEDEPENDS += "\
	enigma2-plugin-systemplugins-remotecontrolcode \
	vuplus-tuner-turbo \
	${@bb.utils.contains("MACHINE_FEATURES", "bluetooth", "enigma2-plugin-systemplugins-bluetoothsetup-${MACHINE}", "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "bcmwifi", "vuplus-wifi-util-${MACHINE}", "", d)} \
	"

IMAGE_INSTALL_append = " \
	vuplus-initrd-${MACHINE} \
	enigma2-plugin-systemplugins-bluetoothsetup-${MACHINE} \
	vuplus-bluetooth-util-${MACHINE} \
	"

#IMAGE_FSTYPES += "ext4"

TARGET_ARCH = "arm"
DEFAULTTUNE = "armv7ahf-neon"

DVBMEDIASINK_CONFIG = "--with-wmv --with-pcm --with-eac3 --with-h265 --with-dtsdownmix --with-amr --with-dts"

PREFERRED_PROVIDER_virtual/kernel = "linux-vuplus"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "vuplus-blindscan-utils-${MACHINE}"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "vuplus-blindscan-utils-${MACHINE}"

PREFERRED_PROVIDER_virtual/egl = "libgles-${MACHINE}"
PREFERRED_PROVIDER_virtual/libgles2 = "libgles-${MACHINE}"

IMAGE_FSTYPES ?= "tar.bz2"

FORCE_REBOOT_OPTION ?= "reboot"

IMAGEDIR = "vuplus/${UPDATE_DIR}"

IMAGE_CMD_tar_prepend = " \
        mkdir -p ${IMGDEPLOYDIR}/${IMAGEDIR}; \
        cp -f ${IMAGE_ROOTFS}/tmp/zImage ${IMGDEPLOYDIR}/${IMAGEDIR}/kernel_auto.bin; \
        cp -f ${IMAGE_ROOTFS}/boot/initrd_auto.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/initrd_auto.bin; \
	touch ${IMGDEPLOYDIR}/${IMAGEDIR}/${FORCE_REBOOT_OPTION}.update; \
	touch ${IMGDEPLOYDIR}/${IMAGEDIR}/mkpart.update; \
        rm -rf ${IMAGE_ROOTFS}/tmp/zImage; \
        rm -rf ${IMAGE_ROOTFS}/boot/initrd_auto.bin; \
        cd ${IMAGE_ROOTFS}; \
        tar -cvf ${IMGDEPLOYDIR}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
        mv -f ${IMGDEPLOYDIR}/rootfs.tar ${IMGDEPLOYDIR}/${IMAGEDIR}/rootfs.tar; \
        bzip2 ${IMGDEPLOYDIR}/${IMAGEDIR}/rootfs.tar; \
	rm -f ${IMGDEPLOYDIR}/*.zip; \
        cd ${IMGDEPLOYDIR}; \
        zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.tar.bz2; \
        rm -rf vuplus; \
"

MACHINE_FEATURES += "alsa usbhost switchoff osdposition hdmicec ci uianimation dvbproxy blindscan-tbs vuplus emmc mmc dvb-c blindscan-dvbc blindscan-dvbs ctrlrc bluetooth HDMI"

KERNEL_FILE = "kernel_auto.bin"
ROOTFS_FILE = "rootfs.tar.bz2"
MTD_BLACK  = "mmcblk0"

require conf/machine/include/arm/arch-armv7a.inc

BOX_BRAND = "vuplus"

STB_PLATFORM = "vu4kgen"

EXTRA_ALSA = "vuplus"

EXTRA_OECONF_append_pn-transtreamproxy = " --enable-ext-pid"
