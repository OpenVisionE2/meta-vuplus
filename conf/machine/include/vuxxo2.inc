# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

KERNELVERSION = "3.13.5"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	vuplus-dvb-modules-${MACHINE} \
	gstreamer1.0-libav \
	kernel-module-rtl8192cu \
	firmware-rtl8192cu \
	firmware-rtl8192cufw \
	vuplus-tuner-turbo \
	vuplus-shutdown \
	gstreamer1.0-plugin-dvbmediasink \
	"

EXTRA_IMAGEDEPENDS += "\
	enigma2-plugin-systemplugins-firmwareupgrade \
	enigma2-plugin-systemplugins-remotecontrolcode \
	vuplus-hbbtv-dumpait \
	vuplus-tuner-turbo \
	"

MTD_KERNEL = "mtd2"
MTD_ROOTFS = "mtd0"
KERNEL_FILE = "kernel_cfe_auto.bin"
ROOTFS_FILE = "root_cfe_auto.bin"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

DVBMEDIASINK_CONFIG = "--with-wmv --with-pcm --with-eac3 --with-amr"

PREFERRED_VERSION_linux-vuplus = "${KERNELVERSION}"

PREFERRED_PROVIDER_virtual/kernel = "linux-vuplus"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "vuplus-blindscan-utils-${MACHINE}"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "vuplus-blindscan-utils-${MACHINE}"

PREFERRED_PROVIDER_virtual/egl = "libgles-${MACHINE}"
PREFERRED_PROVIDER_virtual/libgles2 = "libgles-${MACHINE}"

IMAGE_FSTYPES ?= "ubi"

MKUBIFS_ARGS = "-m 2048 -e 126976 -c ${MKFS_UBI_MAX_ERASE_BLK_COUNT}"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

EXTRA_IMAGECMD_COMPAT = " --eraseblock=0x20000 -n -l "

IMAGE_CMD_ubi_prepend = " \
	cp -f ${IMAGE_ROOTFS}/tmp/vmlinux.gz ${IMGDEPLOYDIR}/${IMAGE_NAME}.vmlinux.gz; \
	cp -f ${IMAGE_ROOTFS}/boot/initrd_cfe_auto.bin ${IMGDEPLOYDIR}/${IMAGE_NAME}.initrd_cfe_auto.bin; \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	rm -rf ${IMAGE_ROOTFS}/boot/initrd_cfe_auto.bin; \
	"

FORCE_REBOOT_OPTION ?= "reboot"

IMAGEDIR = "vuplus/${UPDATE_DIR}"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${IMGDEPLOYDIR}/${IMAGEDIR}; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${IMGDEPLOYDIR}/${IMAGEDIR}/root_cfe_auto.bin; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}.vmlinux.gz ${IMGDEPLOYDIR}/${IMAGEDIR}/kernel_cfe_auto.bin; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}.initrd_cfe_auto.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/initrd_cfe_auto.bin; \
	touch ${IMGDEPLOYDIR}/${IMAGEDIR}/${FORCE_REBOOT_OPTION}.update; \
	rm -f ${IMGDEPLOYDIR}/*.zip; \
	cd ${IMGDEPLOYDIR}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
	rm -rf vuplus; \
	"

MACHINE_FEATURES += "alsa usbhost switchoff osdposition hdmicec fan blindscan-tbs vuplus HDMI"

require conf/machine/include/tune-mips32.inc

HOSTTOOLS += "sshpass"

BOX_BRAND = "vuplus"

STB_PLATFORM = "vu2gen"

EXTRA_ALSA = "vuplus"

BLINDSCAN_BINARY = "vuplus_blindscan"

RCNAME ?= "vu"
