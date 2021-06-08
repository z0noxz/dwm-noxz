/* See LICENSE file for copyright and license details. */
#define COL_DEF                     "#000000"
#define MODKEY                      Mod4Mask

/* appearance */
static unsigned int borderpx    = 2;        /* border pixel of windows */
static unsigned int snap        = 32;       /* snap pixel */
static unsigned int gap         = 10;       /* inner and outer gap between windows */
static int showbar              = 1;        /* 0 means no bar */
static int topbar               = 1;        /* 0 means bottom bar */
static int viewontag            = 1;
static int focusonwheel         = 0;
static char font[256]           = "monospace:size=10";
static char *fonts[]            = { font };

static char col_none[]          = COL_DEF;
static char col_nbr[]           = COL_DEF;
static char col_sbr[]           = COL_DEF;
static char col_sfl[]           = COL_DEF;
static char col_tanfg[]         = COL_DEF;
static char col_tanbg[]         = COL_DEF;
static char col_tanbr[]         = COL_DEF;
static char col_tasfg[]         = COL_DEF;
static char col_tasbg[]         = COL_DEF;
static char col_tasbr[]         = COL_DEF;
static char col_tinfg[]         = COL_DEF;
static char col_tisfg[]         = COL_DEF;
static char col_snfg[]          = COL_DEF;
static char col_safg[]          = COL_DEF;
static char col_sabg[]          = COL_DEF;
static char col_sdfg[]          = COL_DEF;
static char col_sdbg[]          = COL_DEF;
static char col_snofg[]         = COL_DEF;
static char col_snobg[]         = COL_DEF;
static char *colors[][4]        = {
	/*                          fg          bg          border      float   */
	[SchemeNorm]            = { col_none,   col_none,   col_nbr,    col_none },
	[SchemeSel]             = { col_none,   col_none,   col_sbr,    col_sfl },
	[SchemeTagsNorm]        = { col_tanfg,  col_tanbg,  col_tanbr,  col_none },
	[SchemeTagsSel]         = { col_tasfg,  col_tasbg,  col_tasbr,  col_none },
	[SchemeTitleNorm]       = { col_tinfg,  col_none,   col_none,   col_none },
	[SchemeTitleSel]        = { col_tisfg,  col_none,   col_none,   col_none },

	[SchemeStatusNorm]      = { col_snfg,   col_none,   col_none,   col_none },
	[SchemeStatusAct]       = { col_safg,   col_sabg,   col_none,   col_none },
	[SchemeStatusDist]      = { col_sdfg,   col_sdbg,   col_none,   col_none },
	[SchemeStatusNoti]      = { col_snofg,  col_snobg,  col_none,   col_none },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = { NULL
	/* xprop(1):
	 * WM_CLASS(STRING) = instance, class
	 * WM_NAME(STRING) = title
	 */
	/* class            instance    title   tags mask   isfloating   monitor */
};

/* layout(s) */
static float mfact              = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster              = 0;    /* number of clients in master area */
static int resizehints          = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	[LayoutGrid]                = { "\uE026\uE027",nrowgrid }, /* default */
	[LayoutTiled]               = { "\uE020\uE021",tile },
	[LayoutMonocle]             = { "\uE024\uE025",monocle },
	[LayoutFloating]            = { "\uE022\uE023",NULL },    /* no layout function means floating behavior */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click            event mask      button      function        argument */
	{ ClkLtSymbol,      0,              Button1,    rotatelayout,   {.i = +1 } },
	{ ClkLtSymbol,      0,              Button3,    rotatelayout,   {.i = -1 } },
	{ ClkClientWin,     Mod4Mask,       Button4,    rotatestack,    {.i = +1 } },
	{ ClkClientWin,     Mod4Mask,       Button5,    rotatestack,    {.i = -1 } },
	{ ClkWinTitle,      0,              Button2,    zoom,           {0} },
	{ ClkClientWin,     Mod4Mask,       Button1,    movemouse,      {0} },
	{ ClkClientWin,     Mod4Mask,       Button2,    togglefloating, {0} },
	{ ClkClientWin,     Mod4Mask,       Button3,    resizemouse,    {0} },
	{ ClkTagBar,        0,              Button1,    view,           {0} },
	{ ClkTagBar,        0,              Button3,    toggleview,     {0} },
	{ ClkTagBar,        Mod4Mask,       Button1,    tag,            {0} },
	{ ClkTagBar,        Mod4Mask,       Button3,    toggletag,      {0} },
};

/* Xresources preferences to load at startup */
ResourcePref resources[] = {
	{ "normalBorderColor",          STRING,     &col_nbr },
	{ "selectedBorderColor",        STRING,     &col_sbr },
	{ "selectedFloatColor",         STRING,     &col_sfl },
	{ "tagsNormalForeground",       STRING,     &col_tanfg },
	{ "tagsNormalBackground",       STRING,     &col_tanbg },
	{ "tagsNormalBorderColor",      STRING,     &col_tanbr },
	{ "tagsSelectedForeground",     STRING,     &col_tasfg },
	{ "tagsSelectedBackground",     STRING,     &col_tasbg },
	{ "tagsSelectedBorderColor",    STRING,     &col_tasbr },
	{ "titleNormalForeground",      STRING,     &col_tinfg },
	{ "titleSelectedForeground",    STRING,     &col_tisfg },
	{ "statusNormalForeground",     STRING,     &col_snfg },
	{ "statusActForeground",        STRING,     &col_safg },
	{ "statusActBackground",        STRING,     &col_sabg },
	{ "statusDistForeground",       STRING,     &col_sdfg },
	{ "statusDistBackground",       STRING,     &col_sdbg },
	{ "statusNotiForeground",       STRING,     &col_snofg },
	{ "statusNotiBackground",       STRING,     &col_snobg },
	{ "font",                       STRING,     &font },
	{ "borderpx",                   INTEGER,    &borderpx },
	{ "snap",                       INTEGER,    &snap },
	{ "gap",                        INTEGER,    &gap },
	{ "showbar",                    INTEGER,    &showbar },
	{ "topbar",                     INTEGER,    &topbar },
	{ "viewontag",                  INTEGER,    &viewontag },
	{ "focusonwheel",               INTEGER,    &focusonwheel },
	{ "nmaster",                    INTEGER,    &nmaster },
	{ "resizehints",                INTEGER,    &resizehints },
	{ "mfact",                      FLOAT,      &mfact },
};

static const char *dwmfifo = "/tmp/dwm.fifo";
static Command commands[] = {
	{ "spawn ...",          spawn,          {.i = DispCmdLine} },
	{ "quit",               quit,           {0} },
	{ "toggle bar",         togglebar,      {0} },
	{ "focus stack +",      focusstack,     {.i = +1} },
	{ "focus stack -",      focusstack,     {.i = -1} },
	{ "move stack +",       movestack,      {.i = +1} },
	{ "move stack -",       movestack,      {.i = -1} },
	{ "rotate stack +",     rotatestack,    {.i = +1} },
	{ "rotate stack -",     rotatestack,    {.i = -1} },
	{ "inc nmaster +",      incnmaster,     {.i = +1} },
	{ "inc nmaster -",      incnmaster,     {.i = -1} },
	{ "set mfact +",        setmfact,       {.f = +0.05} },
	{ "set mfact -",        setmfact,       {.f = -0.05} },
	{ "zoom",               zoom,           {0} },
	{ "kill client",        killclient,     {0} },

	{ "set layout grid",    setlayout,      {.v = &layouts[LayoutGrid]} },
	{ "set layout tiled",   setlayout,      {.v = &layouts[LayoutTiled]} },
	{ "set layout floating",setlayout,      {.v = &layouts[LayoutFloating]} },
	{ "set layout monocle", setlayout,      {.v = &layouts[LayoutMonocle]} },
	{ "toggle monocle",     togglelayout,   {.v = &layouts[LayoutMonocle]} },
	{ "toggle layout",      setlayout,      {0} },
	{ "rotate layout +",    rotatelayout,   {.i = +1} },
	{ "rotate layout -",    rotatelayout,   {.i = -1} },

	{ "toggle gaps",        togglegaps,     {0} },
	{ "inc gaps +",         incgaps,        {.i = +1} },
	{ "inc gaps -",         incgaps,        {.i = -1} },

	{ "toggle floating",    togglefloating, {0} },
	{ "toggle sticky",      togglesticky,   {0} },
	{ "focus mon +",        focusmon,       {.i = +1} },
	{ "focus mon -",        focusmon,       {.i = -1} },
	{ "tag mon +",          tagmon,         {.i = +1} },
	{ "tag mon -",          tagmon,         {.i = -1} },

	{ "view",               view,           {0} },
	{ "view all",           view,           {.ui = ~0} },
	{ "tag all",            tag,            {.ui = ~0} },
	{ "view ...",           view,           {.i = DispUi} },
	{ "toggle view ...",    toggleview,     {.i = DispUi} },
	{ "tag ...",            tag,            {.i = DispUi} },
	{ "toggle tag ...",     toggletag,      {.i = DispUi} },
};
