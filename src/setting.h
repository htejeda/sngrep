/**************************************************************************
 **
 ** sngrep - SIP Messages flow viewer
 **
 ** Copyright (C) 2015 Ivan Alonso (Kaian)
 ** Copyright (C) 2015 Irontec SL. All rights reserved.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **
 ****************************************************************************/
/**
 * @file setting.h
 * @author Ivan Alonso [aka Kaian] <kaian@irontec.com>
 *
 * @brief Functions to manage application settings
 *
 * This file contains the functions to manage application settings and
 * optionuration resource files. Configuration will be parsed in this order,
 * from less to more priority, so the later will overwrite the previous.
 *
 *  - Initialization
 *  - \@sysdir\@/sngreprc
 *  - $HOME/.sngreprc
 *
 * This is a basic approach to configuration, but at least a minimun is required
 * for those who can not see all the list columns or want to disable colours in
 * every sngrep execution.
 */

#ifndef __SNGREP_SETTING_H
#define __SNGREP_SETTING_H

//! Shorter declarartion of setting_option struct
typedef struct setting_option setting_t;

//! Generic setting formats
#define SETTING_ENUM_ONOFF       (const char *[]){ "on", "off", NULL }
#define SETTING_ENUM_YESNO       (const char *[]){ "yes", "no", NULL }
#define SETTING_ENUM_BACKGROUND  (const char *[]){ "dark" , "default", NULL }
#define SETTING_ENUM_COLORMODE   (const char *[]){ "request", "cseq", "callid", NULL }
#define SETTING_ENUM_HIGHLIGHT   (const char *[]){ "bold", "reverse", "reversebold", NULL }
#define SETTING_ENUM_SDP_INFO    (const char *[]){ "off", "first", "full", NULL}

//! Available setting Options
enum setting_id
{
    SETTING_BACKGROUND = 0,
    SETTING_COLORMODE,
    SETTING_SYNTAX,
    SETTING_SYNTAX_TAG,
    SETTING_SYNTAX_BRANCH,
    SETTING_ALTKEY_HINT,
    SETTING_EXITPROMPT,
    SETTING_CAPTURE_LIMIT,
    SETTING_CAPTURE_LOOKUP,
    SETTING_CAPTURE_DEVICE,
    SETTING_CAPTURE_INFILE,
    SETTING_CAPTURE_OUTFILE,
    SETTING_CAPTURE_KEYFILE,
    SETTING_CAPTURE_RTP,
    SETTING_SIP_NOINCOMPLETE,
    SETTING_SIP_CALLS,
    SETTING_SAVEPATH,
    SETTING_DISPLAY_HOST,
    SETTING_DISPLAY_ALIAS,
    SETTING_CL_FILTER,
    SETTING_CL_SCROLLSTEP,
    SETTING_CF_FORCERAW,
    SETTING_CF_RAWMINWIDTH,
    SETTING_CF_RAWFIXEDWIDTH,
    SETTING_CF_SPLITCALLID,
    SETTING_CF_HIGHTLIGHT,
    SETTING_CF_SCROLLSTEP,
    SETTING_CF_LOCALHIGHLIGHT,
    SETTING_CF_SDP_INFO,
    SETTING_CF_MEDIA,
    SETTING_CF_DELTA,
    SETTING_CR_SCROLLSTEP,
    SETTING_FILTER_METHODS,
    SETTING_COUNT,
};

//! Available setting formats
enum setting_fmt
{
    SETTING_FMT_STRING = 0,
    SETTING_FMT_NUMBER,
    SETTING_FMT_ENUM,
};

/**
 * @brief Configurable Setting structure
 */
struct setting_option {
    //! Setting id
    enum setting_id id;
    //! Setting name
    const char *name;
    //! Setting format
    enum setting_fmt fmt;
    //! Value of the setting
    const char *value;
    //! Compa separated valid values
    const char **valuelist;
};


setting_t *
setting_by_id(int id);

setting_t *
setting_by_name(const char *name);

/**
 * @brief Return the setting id of a given string
 *
 * @param name String representing configurable setting
 * @return setting id or -1 if setting is not found
 */
int
setting_id(const char *name);

/**
 * @brief Return string representing given setting id
 *
 * @param id Setting id from settings enum
 * @return string representation of setting or NULL
 */
const char *
setting_name(int id);

int
setting_format(int id);

const char **
setting_valid_values(int id);

const char*
setting_get_value(int id);

int
setting_get_intvalue(int id);

void
setting_set_value(int id, const char *value);

void
setting_set_intvalue(int id, int value);

int
setting_enabled(int id);

int
setting_has_value(int id, const char *value);

void
setting_toggle(int id);

const char *
setting_enum_next(int id, const char *value);

#endif /* __SNGREP_SETTING_H */