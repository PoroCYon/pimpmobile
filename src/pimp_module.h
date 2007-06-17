/* pimp_module.h -- module data structure and getter functions
 * Copyright (C) 2005-2006 J�rn Nystad and Erik Faye-Lund
 * For conditions of distribution and use, see copyright notice in LICENSE.TXT
 */

#ifndef PIMP_MODULE_H
#define PIMP_MODULE_H

#include "pimp_instrument.h"

typedef struct
{
	u32 data_ptr;
	u16 row_count;
} pimp_pattern;

/* packed, because it's all bytes. no member-alignment or anything needed */
typedef struct __attribute__((packed))
{
	u8 pan;
	u8 volume;
	u8 mute;
} pimp_channel;

typedef struct pimp_module
{
	char name[32];
	
	u32 flags;
	u32 reserved; /* for future flags */
	
	/* these are offsets relative to the begining of the pimp_module_t-structure */
	u32 order_ptr;
	u32 pattern_ptr;
	u32 channel_ptr;
	u32 instrument_ptr;
	
	u16 period_low_clamp;
	u16 period_high_clamp;
	u16 order_count;
	
	u8  order_repeat;
	u8  volume;
	u8  tempo;
	u8  bpm;
	
	u8  instrument_count;
	u8  pattern_count;
	u8  channel_count;
} pimp_module;

#include "pimp_debug.h"
#include "pimp_internal.h"

/* pattern entry */
static INLINE pimp_pattern_entry *__pimp_pattern_get_data(const pimp_pattern *pat)
{
	ASSERT(pat != NULL);
	return (pimp_pattern_entry*)PIMP_GET_PTR(pat->data_ptr);
}

static INLINE int __pimp_module_get_order(const pimp_module *mod, int i)
{
	char *array;
	ASSERT(mod != NULL);

	array = (char*)pimp_get_ptr(&mod->order_ptr);
	if (NULL == array) return -1;

	return array[i];
}

static INLINE pimp_pattern *__pimp_module_get_pattern(const pimp_module *mod, int i)
{
	ASSERT(mod != NULL);
	return &((pimp_pattern*)PIMP_GET_PTR(mod->pattern_ptr))[i];
}

static INLINE pimp_channel *__pimp_module_get_channel(const pimp_module *mod, int i)
{
	ASSERT(mod != NULL);
	return &((pimp_channel*)PIMP_GET_PTR(mod->channel_ptr))[i];
}

static INLINE pimp_instrument *__pimp_module_get_instrument(const pimp_module *mod, int i)
{
	pimp_instrument *array;
	ASSERT(mod != NULL);
	
	array = (pimp_instrument*)pimp_get_ptr(&mod->instrument_ptr);
	if (NULL == array) return NULL;
	
	return &(array[i]);
}

#endif /* PIMP_MODULE_H */
