/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2010-2012 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#ifndef __ARCH_CONFIG_H__
#define __ARCH_CONFIG_H__

/* Configuration for the PB platform with ZBT memory enabled */

static _mali_osk_resource_t arch_configuration [] =
{

    	{
                .type = PMU,
                .description = "Mali-400 PMU",
                .base = 0xC0002000,
                .irq = -1,
                .mmu_id = 0
        },
	{
		.type = MALI400GP,
		.description = "Mali-400 GP",
		.base = 0xC0000000,
		.irq = -1,
		.mmu_id = 1
	},
	{
		.type = MALI400PP,
		.base = 0xc0008000,
		.irq = -1,
		.description = "Mali-400 PP",
		.mmu_id = 2
	},
	{
		.type = MMU,
		.base = 0xC0003000,
		.irq = -1,
		.description = "Mali-400 MMU for GP",
		.mmu_id = 1
	},
	{
		.type = MMU,
		.base = 0xC0004000,
		.irq = -1,
		.description = "Mali-400 MMU for PP",
		.mmu_id = 2
	},
	{
		.type = OS_MEMORY,
		.description = "OS Memory",
		.alloc_order = 10, /* Lowest preference for this memory */
		.size = 96 * 1024 * 1024, /* 96 MB */
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
	{
		.type = MEMORY,
		.description = "Mali SDRAM remapped to baseboard",
		.cpu_usage_adjust = 0,
		.alloc_order = 5, /* Medium preference for this memory */
		.base = 0x80000000,
		.size = 0x10000000,
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
	{
		.type = MEMORY,
		.description = "Mali ZBT",
		.alloc_order = 0, /* Highest preference for this memory */
		.base = 0xe1000000,
		.size = 0x01000000,
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_READABLE | _MALI_PP_WRITEABLE |_MALI_GP_READABLE | _MALI_GP_WRITEABLE
	},
	{
		.type = MEM_VALIDATION,
		.description = "Framebuffer",
		.base = 0xe0000000,
		.size = 0x01000000,
		.flags = _MALI_CPU_WRITEABLE | _MALI_CPU_READABLE | _MALI_PP_WRITEABLE | _MALI_PP_READABLE
	},
	{
		.type = MALI400L2,
		.base = 0xC0001000,
		.description = "Mali-400 L2 cache"
	},
};

#endif /* __ARCH_CONFIG_H__ */
