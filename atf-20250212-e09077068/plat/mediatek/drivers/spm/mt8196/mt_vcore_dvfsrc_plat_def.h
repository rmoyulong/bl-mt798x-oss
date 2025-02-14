/*
 * Copyright (c) 2025, Mediatek Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MT_VCORE_DVFSRC_PLAT_DEF_H
#define MT_VCORE_DVFSRC_PLAT_DEF_H

#include <lib/utils_def.h>

#ifdef MT8196_VCORE_SUPPORT
#define VCORE_BASE_UV		0
#define VCORE_STEP_UV		6250

/* PMIC */
#define VCORE_PMIC_TO_UV(pmic)	\
	(((pmic) * VCORE_STEP_UV) + VCORE_BASE_UV)
#define VCORE_UV_TO_PMIC(uv)	/* pmic >= uv */	\
	((((uv) - VCORE_BASE_UV) + (VCORE_STEP_UV - 1)) / VCORE_STEP_UV)
#else
#define VCORE_BASE_UV		0
#define VCORE_STEP_UV		5000

/* PMIC */
#define VCORE_PMIC_TO_UV(pmic)	\
	(((pmic) * VCORE_STEP_UV) + VCORE_BASE_UV)
#define VCORE_UV_TO_PMIC(uv)	/* pmic >= uv */	\
	((((uv) - VCORE_BASE_UV) + (VCORE_STEP_UV - 1)) / VCORE_STEP_UV)

#ifndef v_min
#define v_min(a, b)	MIN(a, b)
#endif

#ifndef v_max
#define v_max(a, b)	MAZ(a, b)
#endif
#endif

#define VCORE_VB_INFO0	(EFUSEC_BASE + 0xD24)
#define VCORE_VB_INFO1	(EFUSEC_BASE + 0xD28)
#define VCORE_VB_INFO2	(EFUSEC_BASE + 0xD84)

static const struct reg_config dvfsrc_init_configs[] = {
	{ DVFSRC_TIMEOUT_NEXTREQ,	0x00001AFF },
	{ DVFSRC_VCORE_USER_REQ,	0x00010F51 },
	{ DVFSRC_BW_USER_REQ,	0x00010033 },
	/* EMI MONITOR */
	{ DVFSRC_DDR_REQUEST3,	0x44444321 },
	{ DVFSRC_DDR_REQUEST10,	0x44444321 },
	/* SW QOS */
	{ DVFSRC_QOS_EN,	0x20F1007C },
	{ DVFSRC_DDR_QOS0,	0x0000004B },
	{ DVFSRC_DDR_QOS1,	0x0000009A },
	{ DVFSRC_DDR_QOS2,	0x000000CE },
	{ DVFSRC_DDR_QOS3,	0x00000134 },
	{ DVFSRC_DDR_QOS4,	0x00000185 },
	{ DVFSRC_DDR_QOS5,	0x000001F9 },
	{ DVFSRC_DDR_QOS6,	0x0000024C },
	{ DVFSRC_DDR_QOS7,	0x000002B4 },
	{ DVFSRC_DDR_QOS8,	0x00000354 },
	{ DVFSRC_DDR_REQUEST5,	0x87654321 },
	{ DVFSRC_DDR_REQUEST8,	0x00000009 },
	/* LEVEL */
	{ DVFSRC_LEVEL_LABEL_0_1,	0x9055A055 },
	{ DVFSRC_LEVEL_LABEL_2_3,	0x80458055 },
	{ DVFSRC_LEVEL_LABEL_4_5,	0x70558044 },
	{ DVFSRC_LEVEL_LABEL_6_7,	0x70447045 },
	{ DVFSRC_LEVEL_LABEL_8_9,	0x60456055 },
	{ DVFSRC_LEVEL_LABEL_10_11,	0x60446035 },
	{ DVFSRC_LEVEL_LABEL_12_13,	0x60336034 },
	{ DVFSRC_LEVEL_LABEL_14_15,	0x50455055 },
	{ DVFSRC_LEVEL_LABEL_16_17,	0x50445035 },
	{ DVFSRC_LEVEL_LABEL_18_19,	0x50335034 },
	{ DVFSRC_LEVEL_LABEL_20_21,	0x40454055 },
	{ DVFSRC_LEVEL_LABEL_22_23,	0x40254035 },
	{ DVFSRC_LEVEL_LABEL_24_25,	0x40344044 },
	{ DVFSRC_LEVEL_LABEL_26_27,	0x40334024 },
	{ DVFSRC_LEVEL_LABEL_28_29,	0x40224023 },
	{ DVFSRC_LEVEL_LABEL_30_31,	0x30453055 },
	{ DVFSRC_LEVEL_LABEL_32_33,	0x30253035 },
	{ DVFSRC_LEVEL_LABEL_34_35,	0x30443015 },
	{ DVFSRC_LEVEL_LABEL_36_37,	0x30243034 },
	{ DVFSRC_LEVEL_LABEL_38_39,	0x30333014 },
	{ DVFSRC_LEVEL_LABEL_40_41,	0x30133023 },
	{ DVFSRC_LEVEL_LABEL_42_43,	0x30123022 },
	{ DVFSRC_LEVEL_LABEL_44_45,	0x20553011 },
	{ DVFSRC_LEVEL_LABEL_46_47,	0x20352045 },
	{ DVFSRC_LEVEL_LABEL_48_49,	0x20152025 },
	{ DVFSRC_LEVEL_LABEL_50_51,	0x20442005 },
	{ DVFSRC_LEVEL_LABEL_52_53,	0x20242034 },
	{ DVFSRC_LEVEL_LABEL_54_55,	0x20042014 },
	{ DVFSRC_LEVEL_LABEL_56_57,	0x20232033 },
	{ DVFSRC_LEVEL_LABEL_58_59,	0x20032013 },
	{ DVFSRC_LEVEL_LABEL_60_61,	0x20122022 },
	{ DVFSRC_LEVEL_LABEL_62_63,	0x20112002 },
	{ DVFSRC_LEVEL_LABEL_64_65,	0x20002001 },
	{ DVFSRC_LEVEL_LABEL_66_67,	0x10451055 },
	{ DVFSRC_LEVEL_LABEL_68_69,	0x10251035 },
	{ DVFSRC_LEVEL_LABEL_70_71,	0x10051015 },
	{ DVFSRC_LEVEL_LABEL_72_73,	0x10341044 },
	{ DVFSRC_LEVEL_LABEL_74_75,	0x10141024 },
	{ DVFSRC_LEVEL_LABEL_76_77,	0x10331004 },
	{ DVFSRC_LEVEL_LABEL_78_79,	0x10131023 },
	{ DVFSRC_LEVEL_LABEL_80_81,	0x10221003 },
	{ DVFSRC_LEVEL_LABEL_82_83,	0x10021012 },
	{ DVFSRC_LEVEL_LABEL_84_85,	0x10011011 },
	{ DVFSRC_LEVEL_LABEL_86_87,	0x00001000 },
	/* HRT */
	{ DVFSRC_PMQOS_HRT_UNIT_SW_BW,	0x00000120 },
	{ DVFSRC_ISP_HRT_UNIT_SW_BW,	0x0000010F },
	{ DVFSRC_MD_HRT_UNIT_SW_BW,	0x0000010F },
	{ DVFSRC_HRT_BASE_HRT_UNIT_SW_BW,	0x0000010F },
	{ DVFSRC_HRT_REQUEST,	0x87654321 },
	{ DVFSRC_HRT_REQUEST_1,	0x00000009 },
	{ DVFSRC_HRT_HIGH,	0x000006A8 },
	{ DVFSRC_HRT_HIGH_1,	0x00000DD7 },
	{ DVFSRC_HRT_HIGH_2,	0x000012A8 },
	{ DVFSRC_HRT_HIGH_3,	0x00001C0B },
	{ DVFSRC_HRT_HIGH_4,	0x00002644 },
	{ DVFSRC_HRT_HIGH_5,	0x000031AC },
	{ DVFSRC_HRT_HIGH_6,	0x000039FD },
	{ DVFSRC_HRT_HIGH_7,	0x00004435 },
	{ DVFSRC_HRT_HIGH_8,	0x000053B6 },
	{ DVFSRC_HRT_LOW,	0x000006A7 },
	{ DVFSRC_HRT_LOW_1,	0x00000DD7 },
	{ DVFSRC_HRT_LOW_2,	0x000012A8 },
	{ DVFSRC_HRT_LOW_3,	0x00001C0B },
	{ DVFSRC_HRT_LOW_4,	0x00002643 },
	{ DVFSRC_HRT_LOW_5,	0x000031AB },
	{ DVFSRC_HRT_LOW_6,	0x000039FD },
	{ DVFSRC_HRT_LOW_7,	0x00004435 },
	{ DVFSRC_HRT_LOW_8,	0x000053B6 },
	/* MDDDR */
	{ DVFSRC_HRT_REQ_MD_URG,	0x003FF3FF },
	{ DVFSRC_95MD_SCEN_BW7,	0x90000000 },
	{ DVFSRC_95MD_SCEN_BW7_T,	0x90000000 },
	{ DVFSRC_95MD_SCEN_BWU,	0x00000009 },
	{ DVFSRC_MD_LATENCY_IMPROVE,	0x00000021 },
	{ DVFSRC_DEBOUNCE_TIME,	0x0000179E },
	/* RISING */
	{ DVFSRC_DDR_ADD_REQUEST,	0x76543210 },
	{ DVFSRC_DDR_ADD_REQUEST_1,	0x99999998 },
	{ DVFSRC_EMI_MON_DEBOUNCE_TIME,	0x4C2D0000 },
	/* MISC */
	{ DVFSRC_DEFAULT_OPP_1,	0x00000000 },
	{ DVFSRC_DEFAULT_OPP_2,	0x00000000 },
	{ DVFSRC_DEFAULT_OPP_3,	0x00000000 },
	{ DVFSRC_DEFAULT_OPP_4,	0x00000000 },
	{ DVFSRC_DEFAULT_OPP_5,	0x00000000 },
	{ DVFSRC_DEFAULT_OPP_6,	0x00000000 },
	{ DVFSRC_DEFAULT_OPP_7,	0x00000000 },
	{ DVFSRC_DEFAULT_OPP_8,	0x00000001 },
	{ DVFSRC_BASIC_CONTROL_4,	0x0000020F },
	{ DVFSRC_INT_EN,	0x00000002 },
};

static const struct reg_config lp5_7500_init_configs[] = {
	/* SW QOS */
	{ DVFSRC_DDR_REQUEST5,	0x77654321 },
	{ DVFSRC_DDR_REQUEST8,	0x00000007 },
	/* HRT */
	{ DVFSRC_HRT_REQUEST,	0x77654321 },
	{ DVFSRC_HRT_REQUEST_1,	0x00000007 },
	/* MDDDR */
	{ DVFSRC_95MD_SCEN_BW7,	0x70000000 },
	{ DVFSRC_95MD_SCEN_BW7_T,	0x70000000 },
	{ DVFSRC_95MD_SCEN_BWU,	0x00000007 },
};

static const struct reg_config lp5_8533_init_configs[] = {
	/* SW QOS */
	{ DVFSRC_DDR_REQUEST5,	0x87654321 },
	{ DVFSRC_DDR_REQUEST8,	0x00000008 },
	/* HRT */
	{ DVFSRC_HRT_REQUEST,	0x87654321 },
	{ DVFSRC_HRT_REQUEST_1,	0x00000008 },
	/* MDDDR */
	{ DVFSRC_95MD_SCEN_BW7,	0x80000000 },
	{ DVFSRC_95MD_SCEN_BW7_T,	0x80000000 },
	{ DVFSRC_95MD_SCEN_BWU,	0x00000008 },
};

static const struct reg_config lp5_10677_init_configs[] = {
	/* SW QOS */
	{ DVFSRC_DDR_QOS9,	0x000003C0 },
	{ DVFSRC_DDR_REQUEST5,	0x87654321 },
	{ DVFSRC_DDR_REQUEST8,	0x000000A9 },
	/* HRT */
	{ DVFSRC_HRT_HIGH_9,	0x00005E80 },
	{ DVFSRC_HRT_LOW_9,	0x00005E7F },
	{ DVFSRC_HRT_REQUEST,	0x87654321 },
	{ DVFSRC_HRT_REQUEST_1,	0x000000A9 },
};

static const struct reg_config lp5_8533_init_configs_auto[] = {

	/* LEVEL */
	{ DVFSRC_LEVEL_LABEL_0_1,	0x80449045 },
	{ DVFSRC_LEVEL_LABEL_2_3,	0x70448044 },
	{ DVFSRC_LEVEL_LABEL_4_5,	0x60346044 },
	{ DVFSRC_LEVEL_LABEL_6_7,	0x50446033 },
	{ DVFSRC_LEVEL_LABEL_8_9,	0x50335034 },
	{ DVFSRC_LEVEL_LABEL_10_11,	0x40344044 },
	{ DVFSRC_LEVEL_LABEL_12_13,	0x40334024 },
	{ DVFSRC_LEVEL_LABEL_14_15,	0x40224023 },
	{ DVFSRC_LEVEL_LABEL_16_17,	0x30343044 },
	{ DVFSRC_LEVEL_LABEL_18_19,	0x30143024 },
	{ DVFSRC_LEVEL_LABEL_20_21,	0x30233033 },
	{ DVFSRC_LEVEL_LABEL_22_23,	0x30223013 },
	{ DVFSRC_LEVEL_LABEL_24_25,	0x30113012 },
	{ DVFSRC_LEVEL_LABEL_26_27,	0x20342044 },
	{ DVFSRC_LEVEL_LABEL_28_29,	0x20142024 },
	{ DVFSRC_LEVEL_LABEL_30_31,	0x20332004 },
	{ DVFSRC_LEVEL_LABEL_32_33,	0x20132023 },
	{ DVFSRC_LEVEL_LABEL_34_35,	0x20222003 },
	{ DVFSRC_LEVEL_LABEL_36_37,	0x20022012 },
	{ DVFSRC_LEVEL_LABEL_38_39,	0x20012011 },
	{ DVFSRC_LEVEL_LABEL_40_41,	0x10442000 },
	{ DVFSRC_LEVEL_LABEL_42_43,	0x10241034 },
	{ DVFSRC_LEVEL_LABEL_44_45,	0x10041014 },
	{ DVFSRC_LEVEL_LABEL_46_47,	0x10231033 },
	{ DVFSRC_LEVEL_LABEL_48_49,	0x10031013 },
	{ DVFSRC_LEVEL_LABEL_50_51,	0x10121022 },
	{ DVFSRC_LEVEL_LABEL_52_53,	0x10111002 },
	{ DVFSRC_LEVEL_LABEL_54_55,	0x10001001 },
	{ DVFSRC_LEVEL_LABEL_56_57,	0x10341044 },
	{ DVFSRC_LEVEL_LABEL_58_59,	0x10141024 },
	{ DVFSRC_LEVEL_LABEL_60_61,	0x10331004 },
	{ DVFSRC_LEVEL_LABEL_62_63,	0x10131023 },
	{ DVFSRC_LEVEL_LABEL_64_65,	0x10221003 },
	{ DVFSRC_LEVEL_LABEL_66_67,	0x10021012 },
	{ DVFSRC_LEVEL_LABEL_68_69,	0x10011011 },
	{ DVFSRC_LEVEL_LABEL_70_71,	0x00001000 },
	{ DVFSRC_LEVEL_LABEL_72_73,	0x00000000 },
	{ DVFSRC_LEVEL_LABEL_74_75,	0x00000000 },
	{ DVFSRC_LEVEL_LABEL_76_77,	0x00000000 },
	{ DVFSRC_LEVEL_LABEL_78_79,	0x00000000 },
	{ DVFSRC_LEVEL_LABEL_80_81,	0x00000000 },
	{ DVFSRC_LEVEL_LABEL_82_83,	0x00000000 },
	{ DVFSRC_LEVEL_LABEL_84_85,	0x00000000 },
	{ DVFSRC_LEVEL_LABEL_86_87,	0x00000000 },
};

#endif /* MT_VCORE_DVFSRC_PLAT_DEF_H */
