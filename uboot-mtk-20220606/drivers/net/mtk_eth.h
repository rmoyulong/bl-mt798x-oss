/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * Author: Weijie Gao <weijie.gao@mediatek.com>
 * Author: Mark Lee <mark-mc.lee@mediatek.com>
 */

#ifndef _MTK_ETH_H_
#define _MTK_ETH_H_

/* Frame Engine Register Bases */
#include <linux/bitops.h>

#if defined(CONFIG_TARGET_MT7986) || defined(CONFIG_TARGET_MT7981)
#define CONFIG_MEDIATEK_NETSYS_V2 1
#endif

#if defined(CONFIG_MEDIATEK_NETSYS_V2)
#define PDMA_BASE                       0x6000
#define FE_GLO_MISC_REG			0x124
#define PDMA_VER_V2			BIT(4)
#else
#define PDMA_BASE			0x0800
#endif
#define GDMA1_BASE			0x0500
#define GDMA2_BASE			0x1500
#define GMAC_BASE			0x10000

/* Ethernet subsystem registers */

#define ETHSYS_SYSCFG0_REG		0x14
#define SYSCFG0_GE_MODE_S(n)		(12 + ((n) * 2))
#define SYSCFG0_GE_MODE_M		0x3
#define SYSCFG0_SGMII_SEL_M		(0x3 << 8)
#define SYSCFG0_SGMII_SEL(gmac)		((!(gmac)) ? BIT(9) : BIT(8))

#define ETHSYS_CLKCFG0_REG		0x2c
#define ETHSYS_TRGMII_CLK_SEL362_5	BIT(11)

/* SYSCFG0_GE_MODE: GE Modes */
#define GE_MODE_RGMII			0
#define GE_MODE_MII			1
#define GE_MODE_MII_PHY			2
#define GE_MODE_RMII			3

/* SGMII subsystem config registers */
#define SGMSYS_PCS_CONTROL_1		0x0
#define SGMII_LINK_STATUS		BIT(18)
#define SGMII_AN_ENABLE			BIT(12)
#define SGMII_AN_RESTART		BIT(9)

#define SGMSYS_SGMII_MODE		0x20
#define SGMII_FORCE_MODE		0x31120019

#define SGMSYS_QPHY_PWR_STATE_CTRL	0xe8
#define SGMII_PHYA_PWD			BIT(4)

#define SGMSYS_QPHY_WRAP_CTRL		0xec
#define SGMII_PN_SWAP_TX_RX		0x03

#define SGMSYS_GEN2_SPEED		0x2028
#define SGMSYS_GEN2_SPEED_V2		0x128
#define SGMSYS_SPEED_2500		BIT(2)

/* Frame Engine Registers */

/* PDMA */
#define TX_BASE_PTR_REG(n)		(0x000 + (n) * 0x10)
#define TX_MAX_CNT_REG(n)		(0x004 + (n) * 0x10)
#define TX_CTX_IDX_REG(n)		(0x008 + (n) * 0x10)
#define TX_DTX_IDX_REG(n)		(0x00c + (n) * 0x10)

#define RX_BASE_PTR_REG(n)		(0x100 + (n) * 0x10)
#define RX_MAX_CNT_REG(n)		(0x104 + (n) * 0x10)
#define RX_CRX_IDX_REG(n)		(0x108 + (n) * 0x10)
#define RX_DRX_IDX_REG(n)		(0x10c + (n) * 0x10)

#define PDMA_GLO_CFG_REG		0x204
#define TX_WB_DDONE			BIT(6)
#define RX_DMA_BUSY			BIT(3)
#define RX_DMA_EN			BIT(2)
#define TX_DMA_BUSY			BIT(1)
#define TX_DMA_EN			BIT(0)

#define PDMA_RST_IDX_REG		0x208
#define RST_DRX_IDX0			BIT(16)
#define RST_DTX_IDX0			BIT(0)

/* GDMA */
#define GDMA_IG_CTRL_REG		0x000
#define GDM_ICS_EN			BIT(22)
#define GDM_TCS_EN			BIT(21)
#define GDM_UCS_EN			BIT(20)
#define STRP_CRC			BIT(16)
#define MYMAC_DP_S			12
#define MYMAC_DP_M			0xf000
#define BC_DP_S				8
#define BC_DP_M				0xf00
#define MC_DP_S				4
#define MC_DP_M				0xf0
#define UN_DP_S				0
#define UN_DP_M				0x0f

#define GDMA_MAC_LSB_REG		0x008

#define GDMA_MAC_MSB_REG		0x00c

/* MYMAC_DP/BC_DP/MC_DP/UN_DP: Destination ports */
#define DP_PDMA				0
#define DP_GDMA1			1
#define DP_GDMA2			2
#define DP_PPE				4
#define DP_QDMA				5
#define DP_DISCARD			7

/* GMAC Registers */

#define GMAC_PIAC_REG			0x0004
#define PHY_ACS_ST			BIT(31)
#define MDIO_REG_ADDR_S			25
#define MDIO_REG_ADDR_M			0x3e000000
#define MDIO_PHY_ADDR_S			20
#define MDIO_PHY_ADDR_M			0x1f00000
#define MDIO_CMD_S			18
#define MDIO_CMD_M			0xc0000
#define MDIO_ST_S			16
#define MDIO_ST_M			0x30000
#define MDIO_RW_DATA_S			0
#define MDIO_RW_DATA_M			0xffff

/* MDIO_CMD: MDIO commands */
#define MDIO_CMD_ADDR			0
#define MDIO_CMD_WRITE			1
#define MDIO_CMD_READ			2
#define MDIO_CMD_READ_C45		3

/* MDIO_ST: MDIO start field */
#define MDIO_ST_C45			0
#define MDIO_ST_C22			1

#define GMAC_PORT_MCR(p)		(0x0100 + (p) * 0x100)
#define MAC_RX_PKT_LEN_S		24
#define MAC_RX_PKT_LEN_M		0x3000000
#define IPG_CFG_S			18
#define IPG_CFG_M			0xc0000
#define MAC_MODE			BIT(16)
#define FORCE_MODE			BIT(15)
#define MAC_TX_EN			BIT(14)
#define MAC_RX_EN			BIT(13)
#define BKOFF_EN			BIT(9)
#define BACKPR_EN			BIT(8)
#define FORCE_RX_FC			BIT(5)
#define FORCE_TX_FC			BIT(4)
#define FORCE_SPD_S			2
#define FORCE_SPD_M			0x0c
#define FORCE_DPX			BIT(1)
#define FORCE_LINK			BIT(0)

/* Values of IPG_CFG */
#define IPG_96BIT			0
#define IPG_96BIT_WITH_SHORT_IPG	1
#define IPG_64BIT			2

/* MAC_RX_PKT_LEN: Max RX packet length */
#define MAC_RX_PKT_LEN_1518		0
#define MAC_RX_PKT_LEN_1536		1
#define MAC_RX_PKT_LEN_1552		2
#define MAC_RX_PKT_LEN_JUMBO		3

/* FORCE_SPD: Forced link speed */
#define SPEED_10M			0
#define SPEED_100M			1
#define SPEED_1000M			2
#define SPEED_2500M			3

#define GMAC_TRGMII_RCK_CTRL		0x300
#define RX_RST				BIT(31)
#define RXC_DQSISEL			BIT(30)

#define GMAC_TRGMII_TD_ODT(n)		(0x354 + (n) * 8)
#define TD_DM_DRVN_S			4
#define TD_DM_DRVN_M			0xf0
#define TD_DM_DRVP_S			0
#define TD_DM_DRVP_M			0x0f

/* MT7530 Registers */

#define PCR_REG(p)			(0x2004 + (p) * 0x100)
#define PORT_MATRIX_S			16
#define PORT_MATRIX_M			0xff0000

#define PVC_REG(p)			(0x2010 + (p) * 0x100)
#define STAG_VPID_S			16
#define STAG_VPID_M			0xffff0000
#define VLAN_ATTR_S			6
#define VLAN_ATTR_M			0xc0

/* AN8855 regs */
#define BITS(m, n)	 (~(BIT(m) - 1) & ((BIT(n) - 1) | BIT(n)))

#define AN8855_CHIP_ID			0x10005000
#define AN8855_CHIP_REV			0x10005004
#define AN8855_EFUSE_DATA0		0x1000a500

#define AN8855_WORD_SIZE		4
#define AN8855_PORT_CTRL_BASE			0x10208000
#define AN8855_PORT_CTRL_PORT_OFFSET	0x200
#define AN8855_PORT_CTRL_REG(p, r)		(AN8855_PORT_CTRL_BASE + \
					(p) * AN8855_PORT_CTRL_PORT_OFFSET +  (r))
#define AN8855_PCR(p)					AN8855_PORT_CTRL_REG(p, 0x04)
#define AN8855_PVC(p)					AN8855_PORT_CTRL_REG(p, 0x10)
#define AN8855_PORTMATRIX(p)			AN8855_PORT_CTRL_REG(p, 0x44)
#define AN8855_PVID(p)					AN8855_PORT_CTRL_REG(p, 0x48)

#define AN8855_PORT_MAC_CTRL_BASE		0x10210000
#define AN8855_PORT_MAC_CTRL_PORT_OFFSET	0x200
#define AN8855_PORT_MAC_CTRL_REG(p, r)		(AN8855_PORT_MAC_CTRL_BASE + \
					(p) * AN8855_PORT_MAC_CTRL_PORT_OFFSET + (r))
#define AN8855_PMCR(p)					AN8855_PORT_MAC_CTRL_REG(p, 0x00)
#define AN8855_PMSR(p)					AN8855_PORT_MAC_CTRL_REG(p, 0x10)

#define AN8855_GMACCR					(AN8855_PORT_MAC_CTRL_BASE + 0x3e00)

#define AN8855_FORCE_TX_FC		BIT(4)
#define AN8855_FORCE_RX_FC		BIT(5)
#define AN8855_FORCE_DPX		BIT(25)
#define AN8855_FORCE_SPD		BITS(28, 30)
#define AN8855_FORCE_LNK		BIT(24)
#define AN8855_FORCE_MODE		BIT(31)

#define AN8855_PMCR_DEFAULT		(AN8855_FORCE_MODE | \
	AN8855_FORCE_DPX | AN8855_FORCE_LNK | AN8855_FORCE_TX_FC | AN8855_FORCE_RX_FC)

#define AN8855_SYS_CTRL			0x100050C0
#define AN8855_SW_SYS_RST			BIT(31)

#define SCU_BASE				0x10000000
#define RG_RGMII_TXCK_C			(SCU_BASE + 0x1d0)
#define RG_GPIO_LED_MODE		(SCU_BASE + 0x0054)
#define RG_GPIO_LED_SEL(i)	(SCU_BASE + (0x0058 + ((i) * 4)))
#define RG_INTB_MODE			(SCU_BASE + 0x0080)
#define RG_GDMP_RAM				(SCU_BASE + 0x10000)
#define RG_GPIO_L_INV			(SCU_BASE + 0x0010)
#define RG_GPIO_CTRL			(SCU_BASE + 0xa300)
#define RG_GPIO_DATA			(SCU_BASE + 0xa304)
#define RG_GPIO_OE			(SCU_BASE + 0xa314)

#define AN8855_PKG_SEL				0x10000094
#define PAG_SEL_AN8855H		0x2

#define AN8855_CKGCR				0x10213E1C
#define CKG_LNKDN_GLB_STOP	0x01
#define CKG_LNKDN_PORT_STOP	0x02

#define QP_PMA_TOP_BASE			0x1022e000
#define PON_RXFEDIG_CTRL_0		(QP_PMA_TOP_BASE + 0x100)
#define PON_RXFEDIG_CTRL_9		(QP_PMA_TOP_BASE + 0x124)

#define SS_LCPLL_PWCTL_SETTING_2	(QP_PMA_TOP_BASE + 0x208)
#define SS_LCPLL_TDC_FLT_2			(QP_PMA_TOP_BASE + 0x230)
#define SS_LCPLL_TDC_FLT_5			(QP_PMA_TOP_BASE + 0x23c)
#define SS_LCPLL_TDC_PCW_1			(QP_PMA_TOP_BASE + 0x248)
#define INTF_CTRL_8			(QP_PMA_TOP_BASE + 0x320)
#define INTF_CTRL_9			(QP_PMA_TOP_BASE + 0x324)
#define INTF_CTRL_10		(QP_PMA_TOP_BASE + 0x328)
#define INTF_CTRL_11		(QP_PMA_TOP_BASE + 0x32c)
#define PLL_CTRL_0			(QP_PMA_TOP_BASE + 0x400)
#define PLL_CTRL_2			(QP_PMA_TOP_BASE + 0x408)
#define PLL_CTRL_3			(QP_PMA_TOP_BASE + 0x40c)
#define PLL_CTRL_4			(QP_PMA_TOP_BASE + 0x410)
#define PLL_CK_CTRL_0		(QP_PMA_TOP_BASE + 0x414)
#define RX_DLY_0			(QP_PMA_TOP_BASE + 0x614)
#define RX_CTRL_2			(QP_PMA_TOP_BASE + 0x630)
#define RX_CTRL_5			(QP_PMA_TOP_BASE + 0x63c)
#define RX_CTRL_6			(QP_PMA_TOP_BASE + 0x640)
#define RX_CTRL_7			(QP_PMA_TOP_BASE + 0x644)
#define RX_CTRL_8			(QP_PMA_TOP_BASE + 0x648)
#define RX_CTRL_26			(QP_PMA_TOP_BASE + 0x690)
#define RX_CTRL_42			(QP_PMA_TOP_BASE + 0x6d0)

#define QP_ANA_CSR_BASE				0x1022f000
#define RG_QP_RX_DAC_EN				(QP_ANA_CSR_BASE + 0x00)
#define RG_QP_RXAFE_RESERVE			(QP_ANA_CSR_BASE + 0x04)
#define RG_QP_CDR_LPF_BOT_LIM		(QP_ANA_CSR_BASE + 0x08)
#define RG_QP_CDR_LPF_MJV_LIM		(QP_ANA_CSR_BASE + 0x0c)
#define RG_QP_CDR_LPF_SETVALUE		(QP_ANA_CSR_BASE + 0x14)
#define RG_QP_CDR_PR_CKREF_DIV1		(QP_ANA_CSR_BASE + 0x18)
#define RG_QP_CDR_PR_KBAND_DIV_PCIE	(QP_ANA_CSR_BASE + 0x1c)
#define RG_QP_CDR_FORCE_IBANDLPF_R_OFF	(QP_ANA_CSR_BASE + 0x20)
#define RG_QP_TX_MODE_16B_EN		(QP_ANA_CSR_BASE + 0x28)
#define RG_QP_PLL_IPLL_DIG_PWR_SEL	(QP_ANA_CSR_BASE + 0x3c)
#define RG_QP_PLL_SDM_ORD			(QP_ANA_CSR_BASE + 0x40)

#define HSGMII_AN_CSR_BASE			0x10220000
#define SGMII_REG_AN0				(HSGMII_AN_CSR_BASE + 0x000)
#define SGMII_REG_AN_13				(HSGMII_AN_CSR_BASE + 0x034)
#define SGMII_REG_AN_FORCE_CL37		(HSGMII_AN_CSR_BASE + 0x060)

#define HSGMII_CSR_PCS_BASE			0x10220000
#define RG_HSGMII_PCS_CTROL_1		(HSGMII_CSR_PCS_BASE + 0xa00)
#define RG_AN_SGMII_MODE_FORCE		(HSGMII_CSR_PCS_BASE + 0xa24)

#define ETHER_SYS_BASE				0x1028c800
#define RG_GPHY_AFE_PWD				(ETHER_SYS_BASE + 0x40)
#define RG_GPHY_SMI_ADDR			(ETHER_SYS_BASE + 0x48)
#define RG_P5MUX_MODE				(ETHER_SYS_BASE + 0x00)
#define RG_FORCE_CKDIR_SEL			(ETHER_SYS_BASE + 0x04)
#define RG_SWITCH_MODE				(ETHER_SYS_BASE + 0x08)
#define RG_FORCE_MAC5_SB			(ETHER_SYS_BASE + 0x2c)
#define RG_GPHY_AFE_PWD				(ETHER_SYS_BASE + 0x40)
#define RG_GPHY_SMI_ADDR			(ETHER_SYS_BASE + 0x48)
#define CSR_RMII					(ETHER_SYS_BASE + 0x70)

#define QP_DIG_CSR_BASE				0x1022a000
#define QP_CK_RST_CTRL_4			(QP_DIG_CSR_BASE + 0x310)
#define QP_DIG_MODE_CTRL_0			(QP_DIG_CSR_BASE + 0x324)
#define QP_DIG_MODE_CTRL_1			(QP_DIG_CSR_BASE + 0x330)

#define MULTI_SGMII_CSR_BASE		0x10224000
#define SGMII_STS_CTRL_0			(MULTI_SGMII_CSR_BASE + 0x018)
#define MSG_RX_CTRL_0				(MULTI_SGMII_CSR_BASE + 0x100)
#define MSG_RX_LIK_STS_0			(MULTI_SGMII_CSR_BASE + 0x514)
#define MSG_RX_LIK_STS_2			(MULTI_SGMII_CSR_BASE + 0x51c)
#define PHY_RX_FORCE_CTRL_0			(MULTI_SGMII_CSR_BASE + 0x520)

#define MULTI_PHY_RA_CSR_BASE		0x10226000
#define RG_RATE_ADAPT_CTRL_0		(MULTI_PHY_RA_CSR_BASE + 0x000)
#define RATE_ADP_P0_CTRL_0			(MULTI_PHY_RA_CSR_BASE + 0x100)
#define MII_RA_AN_ENABLE			(MULTI_PHY_RA_CSR_BASE + 0x300)

#define RG_CLK_CPU_ICG		0x10005034
#define MCU_ENABLE			BIT(3)

#define RG_TIMER_CTL		0x1000a100
#define WDOG_ENABLE			BIT(25)

#define PHY_TX_PAIR_DLY_SEL_GBE		0x013
#define PHY_RXADC_CTRL				0x0d8
#define PHY_RXADC_REV_0				0x0d9
#define PHY_RXADC_REV_1				0x0da

/* VLAN_ATTR: VLAN attributes */
#define VLAN_ATTR_USER			0
#define VLAN_ATTR_STACK			1
#define VLAN_ATTR_TRANSLATION		2
#define VLAN_ATTR_TRANSPARENT		3

#define PMCR_REG(p)			(0x3000 + (p) * 0x100)
/* XXX: all fields of MT7530 are defined under GMAC_PORT_MCR
 * MT7531 specific fields are defined below
 */
#define FORCE_MODE_EEE1G		BIT(25)
#define FORCE_MODE_EEE100		BIT(26)
#define FORCE_MODE_TX_FC		BIT(27)
#define FORCE_MODE_RX_FC		BIT(28)
#define FORCE_MODE_DPX			BIT(29)
#define FORCE_MODE_SPD			BIT(30)
#define FORCE_MODE_LNK			BIT(31)
#define MT7531_FORCE_MODE		FORCE_MODE_EEE1G | FORCE_MODE_EEE100 |\
					FORCE_MODE_TX_FC | FORCE_MODE_RX_FC | \
					FORCE_MODE_DPX   | FORCE_MODE_SPD | \
					FORCE_MODE_LNK

/* MT7531 SGMII Registers */
#define MT7531_SGMII_REG_BASE		0x5000
#define MT7531_SGMII_REG_PORT_BASE	0x1000
#define MT7531_SGMII_REG(p, r)		(MT7531_SGMII_REG_BASE + \
					(p) * MT7531_SGMII_REG_PORT_BASE + (r))
#define MT7531_PCS_CONTROL_1(p)		MT7531_SGMII_REG(((p) - 5), 0x00)
#define MT7531_SGMII_MODE(p)		MT7531_SGMII_REG(((p) - 5), 0x20)
#define MT7531_QPHY_PWR_STATE_CTRL(p)	MT7531_SGMII_REG(((p) - 5), 0xe8)
#define MT7531_PHYA_CTRL_SIGNAL3(p)	MT7531_SGMII_REG(((p) - 5), 0x128)
/* XXX: all fields of MT7531 SGMII  are defined under SGMSYS */

/* MT753x System Control Register */
#define SYS_CTRL_REG			0x7000
#define SW_PHY_RST			BIT(2)
#define SW_SYS_RST			BIT(1)
#define SW_REG_RST			BIT(0)

/* MT7531  */
#define MT7531_PHY_IAC			0x701c
/* XXX: all fields are defined under GMAC_PIAC_REG */

#define MT7531_CLKGEN_CTRL		0x7500
#define CLK_SKEW_OUT_S			8
#define CLK_SKEW_OUT_M			0x300
#define CLK_SKEW_IN_S			6
#define CLK_SKEW_IN_M			0xc0
#define RXCLK_NO_DELAY			BIT(5)
#define TXCLK_NO_REVERSE		BIT(4)
#define GP_MODE_S			1
#define GP_MODE_M			0x06
#define GP_CLK_EN			BIT(0)

/* Values of GP_MODE */
#define GP_MODE_RGMII			0
#define GP_MODE_MII			1
#define GP_MODE_REV_MII			2

/* Values of CLK_SKEW_IN */
#define CLK_SKEW_IN_NO_CHANGE		0
#define CLK_SKEW_IN_DELAY_100PPS	1
#define CLK_SKEW_IN_DELAY_200PPS	2
#define CLK_SKEW_IN_REVERSE		3

/* Values of CLK_SKEW_OUT */
#define CLK_SKEW_OUT_NO_CHANGE		0
#define CLK_SKEW_OUT_DELAY_100PPS	1
#define CLK_SKEW_OUT_DELAY_200PPS	2
#define CLK_SKEW_OUT_REVERSE		3

#define HWTRAP_REG			0x7800
/* MT7530 Modified Hardware Trap Status Registers */
#define MHWTRAP_REG			0x7804
#define CHG_TRAP			BIT(16)
#define LOOPDET_DIS			BIT(14)
#define P5_INTF_SEL_S			13
#define P5_INTF_SEL_M			0x2000
#define SMI_ADDR_S			11
#define SMI_ADDR_M			0x1800
#define XTAL_FSEL_S			9
#define XTAL_FSEL_M			0x600
#define P6_INTF_DIS			BIT(8)
#define P5_INTF_MODE_S			7
#define P5_INTF_MODE_M			0x80
#define P5_INTF_DIS			BIT(6)
#define C_MDIO_BPS			BIT(5)
#define CHIP_MODE_S			0
#define CHIP_MODE_M			0x0f

/* P5_INTF_SEL: Interface type of Port5 */
#define P5_INTF_SEL_GPHY		0
#define P5_INTF_SEL_GMAC5		1

/* P5_INTF_MODE: Interface mode of Port5 */
#define P5_INTF_MODE_GMII_MII		0
#define P5_INTF_MODE_RGMII		1

#define MT7530_P6ECR			0x7830
#define P6_INTF_MODE_M			0x3
#define P6_INTF_MODE_S			0

/* P6_INTF_MODE: Interface mode of Port6 */
#define P6_INTF_MODE_RGMII		0
#define P6_INTF_MODE_TRGMII		1

#define NUM_TRGMII_CTRL			5

#define MT7530_TRGMII_RD(n)		(0x7a10 + (n) * 8)
#define RD_TAP_S			0
#define RD_TAP_M			0x7f

#define MT7530_TRGMII_TD_ODT(n)		(0x7a54 + (n) * 8)
/* XXX: all fields are defined under GMAC_TRGMII_TD_ODT */

/* TOP Signals Status Register */
#define MT7531_TOP_SIG_SR		0x780c
#define PAD_MCM_SMI_EN			BIT(0)
#define PAD_DUAL_SGMII_EN		BIT(1)

/* MT7531 PLLGP Registers */
#define MT7531_PLLGP_EN			0x7820
#define EN_COREPLL			BIT(2)
#define SW_CLKSW			BIT(1)
#define SW_PLLGP			BIT(0)

#define MT7531_PLLGP_CR0		0x78a8
#define RG_COREPLL_EN			BIT(22)
#define RG_COREPLL_POSDIV_S		23
#define RG_COREPLL_POSDIV_M		0x3800000
#define RG_COREPLL_SDM_PCW_S		1
#define RG_COREPLL_SDM_PCW_M		0x3ffffe
#define RG_COREPLL_SDM_PCW_CHG		BIT(0)

/* MT7531 RGMII and SGMII PLL clock */
#define MT7531_ANA_PLLGP_CR2		0x78b0
#define MT7531_ANA_PLLGP_CR5		0x78bc

/* MT7531 GPIO GROUP IOLB SMT0 Control */
#define MT7531_SMT0_IOLB		0x7f04
#define SMT_IOLB_5_SMI_MDC_EN		BIT(5)

/* MT7530 GPHY MDIO Indirect Access Registers */
#define MII_MMD_ACC_CTL_REG		0x0d
#define MMD_CMD_S			14
#define MMD_CMD_M			0xc000
#define MMD_DEVAD_S			0
#define MMD_DEVAD_M			0x1f

/* MMD_CMD: MMD commands */
#define MMD_ADDR			0
#define MMD_DATA			1
#define MMD_DATA_RW_POST_INC		2
#define MMD_DATA_W_POST_INC		3

#define MII_MMD_ADDR_DATA_REG		0x0e

/* MT7530 GPHY MDIO MMD Registers */
#define CORE_PLL_GROUP2			0x401
#define RG_SYSPLL_EN_NORMAL		BIT(15)
#define RG_SYSPLL_VODEN			BIT(14)
#define RG_SYSPLL_POSDIV_S		5
#define RG_SYSPLL_POSDIV_M		0x60

#define CORE_PLL_GROUP4			0x403
#define MT7531_BYPASS_MODE		BIT(4)
#define MT7531_POWER_ON_OFF		BIT(5)
#define RG_SYSPLL_DDSFBK_EN		BIT(12)
#define RG_SYSPLL_BIAS_EN		BIT(11)
#define RG_SYSPLL_BIAS_LPF_EN		BIT(10)

#define CORE_PLL_GROUP5			0x404
#define RG_LCDDS_PCW_NCPO1_S		0
#define RG_LCDDS_PCW_NCPO1_M		0xffff

#define CORE_PLL_GROUP6			0x405
#define RG_LCDDS_PCW_NCPO0_S		0
#define RG_LCDDS_PCW_NCPO0_M		0xffff

#define CORE_PLL_GROUP7			0x406
#define RG_LCDDS_PWDB			BIT(15)
#define RG_LCDDS_ISO_EN			BIT(13)
#define RG_LCCDS_C_S			4
#define RG_LCCDS_C_M			0x70
#define RG_LCDDS_PCW_NCPO_CHG		BIT(3)

#define CORE_PLL_GROUP10		0x409
#define RG_LCDDS_SSC_DELTA_S		0
#define RG_LCDDS_SSC_DELTA_M		0xfff

#define CORE_PLL_GROUP11		0x40a
#define RG_LCDDS_SSC_DELTA1_S		0
#define RG_LCDDS_SSC_DELTA1_M		0xfff

#define CORE_GSWPLL_GRP1		0x40d
#define RG_GSWPLL_POSDIV_200M_S		12
#define RG_GSWPLL_POSDIV_200M_M		0x3000
#define RG_GSWPLL_EN_PRE		BIT(11)
#define RG_GSWPLL_FBKDIV_200M_S		0
#define RG_GSWPLL_FBKDIV_200M_M		0xff

#define CORE_GSWPLL_GRP2		0x40e
#define RG_GSWPLL_POSDIV_500M_S		8
#define RG_GSWPLL_POSDIV_500M_M		0x300
#define RG_GSWPLL_FBKDIV_500M_S		0
#define RG_GSWPLL_FBKDIV_500M_M		0xff

#define CORE_TRGMII_GSW_CLK_CG		0x410
#define REG_GSWCK_EN			BIT(0)
#define REG_TRGMIICK_EN			BIT(1)

#define PHY_DEV07				0x07
#define PHY_DEV07_REG_03C		0x3c

/* Extend PHY Control Register 3 */
#define PHY_EXT_REG_14			0x14

/* Fields of PHY_EXT_REG_14 */
#define PHY_EN_DOWN_SHFIT		BIT(4)

/* Extend PHY Control Register 4 */
#define PHY_EXT_REG_17			0x17

/* Fields of PHY_EXT_REG_17 */
#define PHY_LINKDOWN_POWER_SAVING_EN	BIT(4)

/* PHY RXADC Control Register 7 */
#define PHY_DEV1E_REG_0C6		0x0c6

#define PHY_DEV1E	0x1e

/* Fields of PHY_DEV1E_REG_0C6 */
#define PHY_POWER_SAVING_S		8
#define PHY_POWER_SAVING_M		0x300
#define PHY_POWER_SAVING_TX		0x0

#endif /* _MTK_ETH_H_ */
