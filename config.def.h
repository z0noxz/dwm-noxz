/* See LICENSE file for copyright and license details. */
#define COL_DEF                     "#000000"
#define MODKEY                      Mod4Mask

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int viewontag          = 1;
static const int focusonwheel       = 0;
static const char *fonts[]          = { "dnoxz_numerics:pixelsize=12:autohint=false" };
static const char title_bg_dark[]   = "#030303";
static const char title_bg_light[]  = "#fdfdfd";
static const int color_ptrs[][4]    = {
	/*                              fg          bg       border   float   */
	[SchemeNorm]                   = { -1,      -1,      5,       -1      },
	[SchemeSel]                    = { -1,      -1,      6,       13      },
	[SchemeTagsNorm]               = { 2,       0,       0,       -1      },
	[SchemeTagsSel]                = { 5,       6,       6,       -1      },
	[SchemeTitleNorm]              = { 6,       -1,      -1,      -1      },
	[SchemeTitleSel]               = { 6,       -1,      -1,      -1      },

	[SchemeStatusNorm]             = { 6,       -1,      -1,      -1      },
	[SchemeStatusAct]              = { 5,       6,       -1,      -1      },
	[SchemeStatusDist]             = { 11,      0,       -1,      -1      },
	[SchemeStatusNoti]             = { 0,       6,       -1,      -1      },
};
static char colors[][4][8]         = {
	/*                                 fg       bg       border   float   */
	[SchemeNorm]                   = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeSel]                    = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeTagsNorm]               = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeTagsSel]                = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeTitleNorm]              = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeTitleSel]               = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },

	[SchemeStatusNorm]             = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeStatusAct]              = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeStatusDist]             = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
	[SchemeStatusNoti]             = { COL_DEF, COL_DEF, COL_DEF, COL_DEF },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 * WM_CLASS(STRING) = instance, class
	 * WM_NAME(STRING) = title
	 */
	/* class            instance    title   tags mask   isfloating   monitor */
	{ "Gimp",           NULL,       NULL,   0,          0,           -1 },
	{ "tabbed",         "vimb",     NULL,   1 << 1,     0,           -1 },
	{ "Brave-browser",  NULL,       NULL,   1 << 1,     0,           -1 },
};

/* layout(s) */
static const float mfact            = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster            = 0;    /* number of clients in master area */
static const int resizehints        = 0;    /* 1 means respect size hints in tiled resizals */

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
