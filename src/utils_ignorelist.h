/**
 * collectd - src/config_list.h
 * Copyright (C) 2006 Lubos Stanek <lubek at users.sourceforge.net>
 *
 * This program is free software; you can redistribute it and/
 * or modify it under the terms of the GNU General Public Li-
 * cence as published by the Free Software Foundation; either
 * version 2 of the Licence, or any later version.
 *
 * This program is distributed in the hope that it will be use-
 * ful, but WITHOUT ANY WARRANTY; without even the implied war-
 * ranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public Licence for more details.
 *
 * You should have received a copy of the GNU General Public
 * Licence along with this program; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139,
 * USA.
 *
 * Authors:
 *   Lubos Stanek <lubek at users.sourceforge.net>
 **/
/**
 * ignorelist handles plugin's list of configured collectable
 * entries with global ignore action
 **/

#ifndef UTILS_IGNORELIST_H
#define UTILS_IGNORELIST_H 1

#include "common.h"

#if HAVE_REGEX_H
# include <regex.h>
#endif

/* public prototypes */

struct ignorelist_s;
typedef struct ignorelist_s ignorelist_t;

/*
 * create the ignorelist_t with known ignore state
 * return pointer to ignorelist_t
 */
ignorelist_t *ignorelist_create (int ignore);

/*
 * create ignorelist_t and initialize the ignore state to 0
 * return pointer to ignorelist_t
 */
ignorelist_t *ignorelist_init (void);

/*
 * free memory used by ignorelist_t
 */
void ignorelist_free (ignorelist_t *conflist);

/*
 * set ignore state of the ignorelist_t
 */
void ignorelist_ignore (ignorelist_t *conflist, int ignore);
/*
 * get number of entries in the ignorelist_t
 * return int number
 */
int ignorelist_num (ignorelist_t *conflist);

/*
 * append entry to ignorelist_t
 * return 1 for success
 */
int ignorelist_add (ignorelist_t *conflist, const char *entry);

/*
 * check list for entry
 * return 1 for ignored entry
 */
int ignorelist_ignored (ignorelist_t *conflist, const char *entry);

#endif /* UTILS_IGNORELIST_H */