// Copyright (c) Hercules Dev Team, licensed under GNU GPL.
// See the LICENSE file
// Portions Copyright (c) Athena Dev Teams

#ifndef COMMON_CORE_H
#define COMMON_CORE_H

#include "../common/cbasetypes.h"
#include "../common/db.h"
#include "../common/mmo.h"

/* so that developers with --enable-debug can raise signals from any section of the code they'd like */
#ifdef DEBUG
#	include <signal.h>
#endif

#define HERC_UNKNOWN_VER '\x02'

enum server_types {
	SERVER_TYPE_UNKNOWN = 0x0,
	SERVER_TYPE_LOGIN   = 0x1,
	SERVER_TYPE_CHAR    = 0x2,
	SERVER_TYPE_MAP     = 0x4,
};

/// The main loop continues until runflag is CORE_ST_STOP
enum E_CORE_ST {
	CORE_ST_STOP = 0,
	CORE_ST_RUN,
	CORE_ST_LAST
};

extern int arg_c;
extern char **arg_v;

/// @see E_CORE_ST
extern int runflag;
extern char *SERVER_NAME;

enum server_types SERVER_TYPE;

extern int do_init(int,char**);
extern void set_server_type(void);
extern void do_abort(void);
extern int do_final(void);

/// Called when a terminate signal is received. (Ctrl+C pressed)
/// If NULL, runflag is set to CORE_ST_STOP instead.
extern void (*shutdown_callback)(void);

#endif /* COMMON_CORE_H */
