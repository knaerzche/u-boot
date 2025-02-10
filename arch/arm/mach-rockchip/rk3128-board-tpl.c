// SPDX-License-Identifier: GPL-2.0+

#include <debug_uart.h>
#include <init.h>
#include <ram.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/sdram_rk3128.h>
#include <asm/arch-rockchip/timer.h>

#if CONFIG_IS_ENABLED(BANNER_PRINT) && !IS_ENABLED(CONFIG_RAM_ROCKCHIP_DEBUG)
#include <timestamp.h>
#include <version.h>
#endif

__weak void get_dram_config(enum rk3128_dram_config *dram_config)
{
	printascii("\nDefine get_dram_config!\n");
	*dram_config = DRAM_INVALID;
}

__weak void tpl_board_init(void)
{
}

void board_init_f(ulong dummy)
{
#if IS_ENABLED(CONFIG_DEBUG_UART) && CONFIG_IS_ENABLED(SERIAL)
	/*
	 * Debug UART can be used from here if required:
	 *
	 * debug_uart_init();
	 * printch('a');
	 * printhex8(0x1234);
	 * printascii("string");
	 */
	debug_uart_init();

#if CONFIG_IS_ENABLED(BANNER_PRINT) && !IS_ENABLED(CONFIG_RAM_ROCKCHIP_DEBUG)
	printascii("\nU-Boot TPL " PLAIN_VERSION " (" U_BOOT_DATE " - " U_BOOT_TIME ")\n");
#endif
#endif

	/* Init secure timer */
	rockchip_stimer_init();

	/* Init ARM arch timer */
	timer_init();

	if (CONFIG_IS_ENABLED(BOARD_INIT))
		tpl_board_init();

	if (CONFIG_IS_ENABLED(RAM)) {
		enum rk3128_dram_config dram_config = DRAM_INVALID;

		get_dram_config(&dram_config);

		if (dram_config >= DRAM_INVALID ||
		    rk3128_sdram_init(dram_config))
			printascii("\nDRAM init failed\n");
	}

	/* Return to bootrom */
	back_to_bootrom(BROM_BOOT_NEXTSTAGE);
}
