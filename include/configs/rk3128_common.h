/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 */

#ifndef __CONFIG_RK3128_COMMON_H
#define __CONFIG_RK3128_COMMON_H

#include "rockchip-common.h"

#define CFG_SYS_HZ_CLOCK		24000000

#define CFG_IRAM_BASE		0x10080000

#define CFG_SYS_SDRAM_BASE		0x60000000
#define SDRAM_MAX_SIZE			0x80000000

#ifndef CONFIG_XPL_BUILD

#ifndef ROCKCHIP_DEVICE_SETTINGS
#define ROCKCHIP_DEVICE_SETTINGS
#endif

#define ENV_MEM_LAYOUT_SETTINGS \
	"scriptaddr=0x60500000\0" \
	"script_offset_f=0xffe000\0" \
	"script_size_f=0x2000\0" \
	"pxefile_addr_r=0x60600000\0" \
	"fdt_addr_r=0x61e00000\0" \
	"fdtoverlay_addr_r=0x61f00000\0" \
	"kernel_addr_r=0x62080000\0" \
	"ramdisk_addr_r=0x66000000\0" \
	"kernel_comp_addr_r=0x68000000\0" \
	"kernel_comp_size=0x2000000\0"

#define CFG_EXTRA_ENV_SETTINGS \
	ENV_MEM_LAYOUT_SETTINGS \
	"fdt_file=" CONFIG_DEFAULT_FDT_FILE "\0" \
	"fdt_high=0x7fffffff\0" \
	"initrd_high=0x7fffffff\0" \
	"partitions=" PARTS_DEFAULT \
	ROCKCHIP_DEVICE_SETTINGS \
	"boot_targets=" BOOT_TARGETS "\0"

#endif  /* CONFIG_XPL_BUILD */

#endif /* __CONFIG_RK3128_COMMON_H */
