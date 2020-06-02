# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS = " \
	vuplus-dvb-modules-${MACHINE} \
	gstreamer1.0-libav \
	kernel-module-rtl8192cu \
	firmware-rtl8192cu \
	firmware-rtl8192cufw \
	vuplus-tuner-turbo \
"

KERNEL_MODULE_AUTOLOAD += "xfs"

MACHINE_EXTRA_RRECOMMENDS = " \
	vuplus-shutdown \
	gstreamer1.0-plugin-dvbmediasink \
"

EXTRA_IMAGEDEPENDS += "\
	vuplus-hbbtv-dumpait \
	vuplus-tuner-turbo \
"

MTD_KERNEL = "mtd1"
MTD_ROOTFS = "mtd0"
KERNEL_FILE = "kernel_cfe_auto.bin"
ROOTFS_FILE = "root_cfe_auto.jffs2"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

DVBMEDIASINK_CONFIG = "--with-wmv --with-pcm --with-eac3 --with-amr"

PREFERRED_VERSION_linux-vuplus = "3.9.6"

PREFERRED_PROVIDER_virtual/kernel = "linux-vuplus"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "vuplus-blindscan-utils-${MACHINE}"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "vuplus-blindscan-utils-${MACHINE}"

IMAGE_FSTYPES ?= "ubi"

UBI_VOLNAME = "rootfs"
MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096 -F"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

IMAGEDIR ?= "${MACHINE}"
IMGDEPLOYDIR ?= "${DEPLOY_DIR_IMAGE}"
EXTRA_IMAGECMD_COMPAT = " --eraseblock=0x20000 -n -l "

IMAGE_CMD_ubi_prepend = " \
	rm -rf ${IMAGE_ROOTFS}/boot/*; \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${IMGDEPLOYDIR}/vuplus/${UPDATE_DIR}; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${IMGDEPLOYDIR}/vuplus/${UPDATE_DIR}/root_cfe_auto.jffs2; \
	gzip -f -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${IMGDEPLOYDIR}/vuplus/${UPDATE_DIR}/kernel_cfe_auto.bin; \
	rm -f ${IMGDEPLOYDIR}/*.zip; \
	cd ${IMGDEPLOYDIR}; \
	zip ${IMAGE_NAME}_usb.zip vuplus/${UPDATE_DIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
	rm -rf vuplus; \
"

MACHINE_FEATURES += "alsa usbhost kernelwifi externalwifi 3dtv switchoff osdposition hdmicec ci blindscan-tbs vuplus"

require conf/machine/include/tune-mips32.inc

BOX_BRAND = "vuplus"
