// SPDX-License-Identifier: GPL-2.0+

#include <asm/io.h>
#include <asm/arch-rockchip/sdram_rk3128.h>

#if IS_ENABLED(CONFIG_TPL_BUILD)
void get_dram_config(enum rk3128_dram_config *dram_config)
{
	*dram_config = DRAM_DDR3_456_MHZ;
}
#endif
