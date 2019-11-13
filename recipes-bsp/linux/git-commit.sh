#!/bin/sh

find -name "*defconfig*" -type f -exec sed -i 's/# CONFIG_RTL8192CU is not set/CONFIG_RTL8192CU=m/g' {} \; > /dev/null 2>&1
find -name "*defconfig*" -type f -exec sed -i 's/CONFIG_RTL8192CU=y/CONFIG_RTL8192CU=m/g' {} \; > /dev/null 2>&1
find -name "*defconfig*" -type f -exec sed -i 's/CONFIG_BLK_DEV_SR=m/CONFIG_BLK_DEV_SR=y/g' {} \; > /dev/null 2>&1
