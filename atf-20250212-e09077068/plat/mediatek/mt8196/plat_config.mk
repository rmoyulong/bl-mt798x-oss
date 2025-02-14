#
# Copyright (c) 2025, MediaTek Inc. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

# Separate text code and read only data
SEPARATE_CODE_AND_RODATA := 1

# ARMv8.2 and above need enable HW assist coherence
HW_ASSISTED_COHERENCY := 1

# No need coherency memory because of HW assistency
USE_COHERENT_MEM := 0

# GIC600
GICV3_SUPPORT_GIC600 := 1

#
# MTK options
#
PLAT_EXTRA_RODATA_INCLUDES := 1
USE_PMIC_WRAP_INIT_V2 := 1

# Configs for A78 and A55
CTX_INCLUDE_AARCH32_REGS := 0

CONFIG_ARCH_ARM_V9 := y
CONFIG_MTK_APUSYS_CE_SUPPORT := y
CONFIG_MTK_APUSYS_EMI_SUPPORT := y
CONFIG_MTK_APUSYS_LOGTOP_SUPPORT := y
CONFIG_MTK_APUSYS_RV_APUMMU_SUPPORT := y
CONFIG_MTK_APUSYS_RV_COREDUMP_WA_SUPPORT := y
CONFIG_MTK_APUSYS_RV_IOMMU_HW_SEM_SUPPORT := y
CONFIG_MTK_APUSYS_SEC_CTRL := y
CONFIG_MTK_APUSYS_SETUP_CE := y
CONFIG_MTK_MCUSYS := y
MCUSYS_VERSION := v4
MCUPM_VERSION := v3
CONFIG_MTK_PM_SUPPORT := y
CONFIG_MTK_PM_ARCH := 9_0
CONFIG_MTK_CPU_PM_SUPPORT := y
CONFIG_MTK_CPU_PM_ARCH := 5_4
CONFIG_MTK_SMP_EN := y
CONFIG_MTK_CPU_SUSPEND_EN := y
CONFIG_MTK_MTCMOS := y
CONFIG_MTK_SPM_VERSION := mt8196
CONFIG_MTK_SUPPORT_SYSTEM_SUSPEND := n
CONFIG_MTK_TINYSYS_VCP := y
CPU_PWR_TOPOLOGY := group_4_3_1
CPU_PM_CORE_ARCH64_ONLY := y
CPU_PM_DOMAIN_CORE_ONLY := n
CPU_PM_SUSPEND_NOTIFY := y
CONFIG_MTK_SPM_SUPPORT := y
CONFIG_MTK_SPM_COMMON_SUPPORT := y
CONFIG_MTK_VCOREDVFS_SUPPORT :=y
CPU_PM_TINYSYS_SUPPORT := y
MTK_PUBEVENT_ENABLE := y
CONFIG_MTK_PMIC := y
CONFIG_MTK_PMIC_LOWPOWER := y
CONFIG_MTK_PMIC_SHUTDOWN_CFG := y
CONFIG_MTK_PMIC_SPT_SUPPORT := n
CONFIG_MTK_SPMI := y
PMIC_CHIP := mt6363

ENABLE_FEAT_AMU := 1
ENABLE_FEAT_ECV := 1
ENABLE_FEAT_FGT := 1
ENABLE_FEAT_HCX := 1
ENABLE_SVE_FOR_SWD := 1
