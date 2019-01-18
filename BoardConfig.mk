#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include device/motorola/msm8916-common/BoardConfigCommon.mk

-include vendor/motorola/lux/BoardConfigVendor.mk

DEVICE_PATH := device/motorola/lux

# Asserts
TARGET_OTA_ASSERT_DEVICE := lux,lux_uds,xt1562,xt1563

# Camera
TARGET_PROCESS_SDK_VERSION_OVERRIDE := \
    /system/bin/cameraserver=25 \
    /system/bin/mediaserver=25 \
    /vendor/bin/mm-qcamera-daemon=25

# Display
TARGET_SCREEN_DENSITY := 480

# HIDL Manifest
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Kernel
TARGET_KERNEL_CONFIG := lux_defconfig

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 33554432	# 32768 * 1024 mmcblk0p31
BOARD_CACHEIMAGE_PARTITION_SIZE := 805306368	# 786432 * 1024 mmcblk0p40
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 33554432	# 32768 * 1024 mmcblk0p32
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2852126720	# 2785280 * 1024 mmcblk0p41
BOARD_PERSISTIMAGE_PARTITION_SIZE := 8388608	# 8192 * 1024 mmcblk0p29
BOARD_USERDATAIMAGE_PARTITION_SIZE := 11815223296 # 11538304 * 1024 mmcblk0p42

# SELinux
BOARD_SEPOLICY_DIRS += $(DEVICE_PATH)/sepolicy

# Sensors
BOARD_USES_STML0XX_SENSOR_HUB := true

# SHIMS
TARGET_LD_SHIM_LIBS += \
    /vendor/lib/libmot_sensorlistener.so|libshims_sensorlistener.so
