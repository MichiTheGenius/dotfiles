/* See LICENSE file for copyright and license details. */

/* appearance */
#include <X11/XF86keysym.h>
#include "movestack.c"
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "CaskaydiaCove Nerd Font:size=10" };
static const char dmenufont[]       = "CaskaydiaCove Nerd Font:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

/* nord colors */
static const char nord_polar_darkest_blue[]        = "#2E3440";
static const char nord_polar_darker_blue[]        = "#3B4252";
static const char nord_polar_lighter_dark_blue[]        = "#434C5E";
static const char nord_polar_lightest_dark_blue[]        = "#4C566A";
static const char nord_dark_white[]        = "#D8DEE9";
static const char nord_darker_white[]        = "#E5E9F0";
static const char nord_white[]        = "#ECEFF4";
static const char nord_white_dark[]        = "#d8dee9";
static const char nord_frost_light_blue[]        = "#8FBCBB";
static const char nord_frost_darker_light_blue[]        = "#88C0D0";
static const char nord_frost_lighter_dark_blue[]        = "#81A1C1";
static const char nord_frost_dark_blue[]        = "#5E81AC";
static const char nord_red[]        = "#BF616A";
static const char nord_orange[]        = "#D08770";
static const char nord_yellow[]        = "#EBCB8B";
static const char nord_green[]        = "#A3BE8C";
static const char nord_purple[]        = "#B48EAD";

/* everforest colors */
// Everforest
static const char normbgcolor[]     = "#2f383e";
static const char normbordercolor[] = "#272e33";
static const char normfgcolor[]     = "#d8caac";
static const char selfgcolor[]      = "#2f383e";
static const char selbgcolor[]      = "#a7c080";
static const char selbordercolor[]  = "#9da9a0";

/* nord theme | format: fg, bg, border
static const char *colors[][3]      = {
	[SchemeNorm] = { nord_white, nord_polar_darkest_blue, nord_polar_darkest_blue },
	[SchemeSel]  = { nord_polar_darkest_blue, nord_frost_darker_light_blue,  nord_red },
};
*/

/* everforest theme */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* default theme */
/*
static const char *colors[][3]      = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
*/


/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static const char *tagsel[][2] = {
    /* foreground, background */
	{ "#272e33", "#a7c080" },
	{ "#272e33", "#e69875" },
	{ "#272e33", "#7fbbb3" },
	{ "#272e33", "#d699b6" },
	{ "#272e33", "#83c092" },
};


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *browser[]  = { "firefox", NULL };
static const char *pcmanfm[]  = { "pcmanfm", NULL };
static const char *rofi[]  = { "rofi", "-show", "run", NULL };
static const char *power_menu[]  = { "rofi", "-show", "power-menu", "-modi", "power-menu:rofi-power-menu", NULL };

/* volume */
static const char *upvol[] = { "/usr/bin/amixer", "set", "Master", "2%+", NULL };
static const char *downvol[] = { "/usr/bin/amixer", "set", "Master", "2%-", NULL };
static const char *mutevol[] = { "/usr/bin/amixer", "set", "Master", "toggle", NULL };

/* brightness */
static const char *incbright[] = { "/bin/bash", "/home/michael/dwm/scripts/incbright.sh", NULL };
static const char *decbright[] = { "/bin/bash", "/home/michael/dwm/scripts/decbright.sh", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	/*{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },*/
	//{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = rofi } },
	{ MODKEY,                       XK_b,      spawn,          {.v = browser} },
	{ MODKEY,                       XK_e,      spawn,          {.v = pcmanfm} },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = power_menu} },
	{ 0     ,       XF86XK_AudioRaiseVolume,   spawn,          {.v = upvol} },
	{ 0     ,       XF86XK_AudioLowerVolume,   spawn,          {.v = downvol} },
	{ 0     ,       XF86XK_AudioMute,          spawn,          {.v = mutevol} },
	{ 0     ,       XF86XK_MonBrightnessUp,    spawn,          {.v = incbright} },
	{ 0     ,       XF86XK_MonBrightnessDown,  spawn,          {.v = decbright} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
