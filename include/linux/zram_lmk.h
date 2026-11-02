/*
 * Interface between zram and the low memory killer.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef _LINUX_ZRAM_LMK_H
#define _LINUX_ZRAM_LMK_H

#include <linux/types.h>

#if IS_BUILTIN(CONFIG_ZRAM)
/*
 * Report how many pages zram0 currently stores and how many bytes they take
 * after compression. The caller must hold rcu_read_lock(). Returns false if
 * the device does not exist or is not initialised yet.
 */
bool zram_lmk_get_usage(u64 *compr_bytes, u64 *stored_pages);
#else
static inline bool zram_lmk_get_usage(u64 *compr_bytes, u64 *stored_pages)
{
	return false;
}
#endif

#endif /* _LINUX_ZRAM_LMK_H */
