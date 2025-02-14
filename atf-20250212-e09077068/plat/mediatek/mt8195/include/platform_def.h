/*
 * Copyright (c) 2021-2024, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLATFORM_DEF_H
#define PLATFORM_DEF_H

#define PLAT_PRIMARY_CPU	0x0

#define MT_GIC_BASE		(0x0C000000)
#define MCUCFG_BASE		(0x0C530000)
#define IO_PHYS			(0x10000000)

/* Aggregate of all devices for MMU mapping */
#define MTK_DEV_RNG0_BASE	IO_PHYS
#define MTK_DEV_RNG0_SIZE	0x10000000
#define MTK_DEV_RNG2_BASE	MT_GIC_BASE
#define MTK_DEV_RNG2_SIZE	0x600000
#define MTK_MCDI_SRAM_BASE	0x11B000
#define MTK_MCDI_SRAM_MAP_SIZE	0x1000

#define APUSYS_BASE			0x19000000
#define APUSYS_SCTRL_REVISER_BASE	0x19021000
#define APUSYS_SCTRL_REVISER_SIZE	0x1000
#define APUSYS_APU_S_S_4_BASE		0x190F2000
#define APUSYS_APU_S_S_4_SIZE		0x1000
#define APUSYS_APU_PLL_BASE		0x190F3000
#define APUSYS_APU_PLL_SIZE		0x1000
#define APUSYS_APU_ACC_BASE		0x190F4000
#define APUSYS_APU_ACC_SIZE		0x1000

#define TOPCKGEN_BASE           (IO_PHYS + 0x00000000)
#define INFRACFG_AO_BASE        (IO_PHYS + 0x00001000)
#define SPM_BASE		(IO_PHYS + 0x00006000)
#define RGU_BASE		(IO_PHYS + 0x00007000)
#define APMIXEDSYS              (IO_PHYS + 0x0000C000)
#define DRM_BASE		(IO_PHYS + 0x0000D000)
#define SSPM_MBOX_BASE          (IO_PHYS + 0x00480000)
#define PERICFG_AO_BASE         (IO_PHYS + 0x01003000)
#define VPPSYS0_BASE            (IO_PHYS + 0x04000000)
#define VPPSYS1_BASE            (IO_PHYS + 0x04f00000)
#define VDOSYS0_BASE            (IO_PHYS + 0x0C01A000)
#define VDOSYS1_BASE            (IO_PHYS + 0x0C100000)
#define DVFSRC_BASE             (IO_PHYS + 0x00012000)

/*******************************************************************************
 * DP/eDP related constants
 ******************************************************************************/
#define EDP_SEC_BASE		(IO_PHYS + 0x0C504000)
#define DP_SEC_BASE		(IO_PHYS + 0x0C604000)
#define EDP_SEC_SIZE		0x1000
#define DP_SEC_SIZE		0x1000

/*******************************************************************************
 * GPIO related constants
 ******************************************************************************/
#define GPIO_BASE		(IO_PHYS + 0x00005000)
#define IOCFG_BM_BASE		(IO_PHYS + 0x01D10000)
#define IOCFG_BL_BASE		(IO_PHYS + 0x01D30000)
#define IOCFG_BR_BASE		(IO_PHYS + 0x01D40000)
#define IOCFG_LM_BASE		(IO_PHYS + 0x01E20000)
#define IOCFG_RB_BASE		(IO_PHYS + 0x01EB0000)
#define IOCFG_TL_BASE		(IO_PHYS + 0x01F40000)

/*******************************************************************************
 * UART related constants
 ******************************************************************************/
#define UART0_BASE			(IO_PHYS + 0x01001100)
#define UART1_BASE			(IO_PHYS + 0x01001200)

#define UART_BAUDRATE			115200

/*******************************************************************************
 * PMIC related constants
 ******************************************************************************/
#define PMIC_WRAP_BASE			(IO_PHYS + 0x00024000)

/*******************************************************************************
 * EMI MPU related constants
 ******************************************************************************/
#define EMI_MPU_BASE		(IO_PHYS + 0x00226000)
#define SUB_EMI_MPU_BASE	(IO_PHYS + 0x00225000)

/*******************************************************************************
 * System counter frequency related constants
 ******************************************************************************/
#define SYS_COUNTER_FREQ_IN_TICKS	13000000
#define SYS_COUNTER_FREQ_IN_MHZ		13

/*******************************************************************************
 * GIC-600 & interrupt handling related constants
 ******************************************************************************/
/* Base MTK_platform compatible GIC memory map */
#define BASE_GICD_BASE			MT_GIC_BASE
#define MT_GIC_RDIST_BASE		(MT_GIC_BASE + 0x40000)
#define DEV_IRQ_ID			580

#define PLAT_MTK_G1S_IRQ_PROPS(grp) \
	INTR_PROP_DESC(DEV_IRQ_ID, GIC_HIGHEST_SEC_PRIORITY, grp, \
			GIC_INTR_CFG_LEVEL)

#define SYS_CIRQ_BASE			(IO_PHYS + 0x204000)
#define CIRQ_REG_NUM			23
#define CIRQ_IRQ_NUM			730
#define CIRQ_SPI_START			96
#define MD_WDT_IRQ_BIT_ID		141
/*******************************************************************************
 * Platform binary types for linking
 ******************************************************************************/
#define PLATFORM_LINKER_FORMAT		"elf64-littleaarch64"
#define PLATFORM_LINKER_ARCH		aarch64

/*******************************************************************************
 * Generic platform constants
 ******************************************************************************/
#define PLATFORM_STACK_SIZE		0x800

#define FIRMWARE_WELCOME_STR		"Booting Trusted Firmware\n"

#define PLAT_MAX_PWR_LVL		U(3)
#define PLAT_MAX_RET_STATE		U(1)
#define PLAT_MAX_OFF_STATE		U(9)

#define PLATFORM_SYSTEM_COUNT		U(1)
#define PLATFORM_MCUSYS_COUNT		U(1)
#define PLATFORM_CLUSTER_COUNT		U(1)
#define PLATFORM_CLUSTER0_CORE_COUNT	U(8)
#define PLATFORM_CLUSTER1_CORE_COUNT	U(0)

#define PLATFORM_CORE_COUNT		(PLATFORM_CLUSTER0_CORE_COUNT)
#define PLATFORM_MAX_CPUS_PER_CLUSTER	U(8)

#define SOC_CHIP_ID			U(0x8195)

/*******************************************************************************
 * Platform memory map related constants
 ******************************************************************************/
#define TZRAM_BASE			0x54600000
#define TZRAM_SIZE			0x00040000

/*******************************************************************************
 * BL31 specific defines.
 ******************************************************************************/
/*
 * Put BL3-1 at the top of the Trusted SRAM (just below the shared memory, if
 * present). BL31_BASE is calculated using the current BL3-1 debug size plus a
 * little space for growth.
 */
#define BL31_BASE			(TZRAM_BASE + 0x1000)
#define BL31_LIMIT			(TZRAM_BASE + TZRAM_SIZE)

/*******************************************************************************
 * Platform specific page table and MMU setup constants
 ******************************************************************************/
#define PLAT_PHY_ADDR_SPACE_SIZE	(1ULL << 32)
#define PLAT_VIRT_ADDR_SPACE_SIZE	(1ULL << 32)
#define MAX_XLAT_TABLES			16
#define MAX_MMAP_REGIONS		16

/*******************************************************************************
 * Declarations and constants to access the mailboxes safely. Each mailbox is
 * aligned on the biggest cache line size in the platform. This is known only
 * to the platform as it might have a combination of integrated and external
 * caches. Such alignment ensures that two maiboxes do not sit on the same cache
 * line at any cache level. They could belong to different cpus/clusters &
 * get written while being protected by different locks causing corruption of
 * a valid mailbox address.
 ******************************************************************************/
#define CACHE_WRITEBACK_SHIFT		6
#define CACHE_WRITEBACK_GRANULE		(1 << CACHE_WRITEBACK_SHIFT)
#endif /* PLATFORM_DEF_H */
