# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

KERNELVERSION = "3.13.5"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	vuplus-dvb-modules-${MACHINE} \
	kernel-module-extrawlan-rtl8192cu \
	firmware-rtl8192cu \
	firmware-rtl8192cufw \
	vuplus-tuner-turbo \
	vuplus-tuner-turbo2 \
	vuplus-shutdown \
	"

EXTRA_IMAGEDEPENDS += "\
	vuplus-hbbtv-dumpait \
	vuplus-tuner-turbo \
	vuplus-tuner-turbo2 \
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

IMAGE_FSTYPES ?= "ubi"

MKUBIFS_ARGS = "-m 2048 -e 126976 -c ${MKFS_UBI_MAX_ERASE_BLK_COUNT}"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

EXTRA_IMAGECMD_COMPAT = " --eraseblock=0x20000 -n -l "

IMAGE_CMD_ubifs_prepend = " \
	cp -f ${IMAGE_ROOTFS}/tmp/vmlinux.gz ${IMGDEPLOYDIR}/${IMAGE_NAME}.vmlinux.gz; \
	cp -f ${IMAGE_ROOTFS}/boot/initrd_cfe_auto.bin ${IMGDEPLOYDIR}/${IMAGE_NAME}.initrd_cfe_auto.bin; \
	rm -rf ${IMAGE_ROOTFS}/boot/*; \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	"

FORCE_REBOOT_OPTION ?= "reboot"

IMAGEDIR = "vuplus/${UPDATE_DIR}"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${IMGDEPLOYDIR}/${IMAGEDIR}; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${IMGDEPLOYDIR}/${IMAGEDIR}/root_cfe_auto.bin; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}.vmlinux.gz ${IMGDEPLOYDIR}/${IMAGEDIR}/kernel_cfe_auto.bin; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}.initrd_cfe_auto.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/initrd_cfe_auto.bin; \
	touch ${IMGDEPLOYDIR}/${IMAGEDIR}/${FORCE_REBOOT_OPTION}.update; \
	echo ${IMAGE_NAME} > ${IMGDEPLOYDIR}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${IMGDEPLOYDIR}/${IMAGEDIR}/donate.txt; \
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

DISPLAY_BRAND = "Vu+"
