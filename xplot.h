/* 
This software is being provided to you, the LICENSEE, by the
Massachusetts Institute of Technology (M.I.T.) under the following
license.  By obtaining, using and/or copying this software, you agree
that you have read, understood, and will comply with these terms and
conditions:

Permission to use, copy, modify and distribute, including the right to
grant others the right to distribute at any tier, this software and
its documentation for any purpose and without fee or royalty is hereby
granted, provided that you agree to comply with the following
copyright notice and statements, including the disclaimer, and that
the same appear on ALL copies of the software and documentation,
including modifications that you make for internal use or for
distribution:

Copyright 1992,1993 by the Massachusetts Institute of Technology.
                    All rights reserved.

THIS SOFTWARE IS PROVIDED "AS IS", AND M.I.T. MAKES NO REPRESENTATIONS
OR WARRANTIES, EXPRESS OR IMPLIED.  By way of example, but not
limitation, M.I.T. MAKES NO REPRESENTATIONS OR WARRANTIES OF
MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE USE
OF THE LICENSED SOFTWARE OR DOCUMENTATION WILL NOT INFRINGE ANY THIRD
PARTY PATENTS, COPYRIGHTS, TRADEMARKS OR OTHER RIGHTS.

The name of the Massachusetts Institute of Technology or M.I.T. may
NOT be used in advertising or publicity pertaining to distribution of
the software.  Title to copyright in this software and any associated
documentation shall at all times remain with M.I.T., and USER agrees
to preserve same.
*/

#ifndef _xplot_h_
#define _xplot_h_

#include "config.h"

#ifdef HAVE_LIBX11
#include <X11/Xos.h>
#else
#error xplot requires X11
#endif

#ifdef HAVE_LIBX11
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>

/*** WH: begin ***/
#include <X11/keysym.h>
/*** WH: end ***/

#else
#error xplot requires x11
#endif


#ifdef STDC_HEADERS
#include <stdlib.h>
#else
#include <malloc.h>
#endif

#ifdef HAVE_LIBM
#include <math.h>
#ifdef ultrix
double rint();     /* YMUL! some versions of ultrix omit this from math.h! */
#endif
#else
#error xplot requires libm/math.h
#endif

/* Coordinate type definitions */
typedef union coord_u {
  int i;
  unsigned int u;
  struct timeval t;
  double d;
} coord;

typedef enum {U_INT, INT, TIMEVAL, DOUBLE, DTIME} coord_type;

#include "coord.h"

#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define abs(x)   (((x)>0)?(x):(-(x)))

typedef enum {CENTERED, ABOVE, BELOW, TO_THE_LEFT, TO_THE_RIGHT} position; 

/* dXPoint is just like Xpoint but uses doubles instead instead of shorts.
*/
typedef struct { double x,y; } dXPoint;

/* lXPoint is just like Xpoint but uses longs instead instead of shorts.
   We need the extra bits to do Postscript stuff in emit_PS() below. 
*/
typedef struct { int x,y; } lXPoint;

typedef short xpcolor_t;

typedef struct command_struct {
  struct command_struct *next;
  enum plot_command_type { X, DOT, PLUS, BOX, DIAMOND,
			   UTICK, DTICK, LTICK, RTICK, HTICK, VTICK,
			   UARROW, DARROW, LARROW, RARROW,
			   INVISIBLE, LINE, DLINE,
			   TEXT, TITLE, XLABEL, YLABEL } type:5;
  position position:3;
  bool needs_redraw:1;
  bool mapped:1;
  bool decoration:1;
  xpcolor_t color;
#ifdef WINDOW_COORDS_IN_COMMAND_STRUCT
  dXPoint a,b;
#endif
  coord xa, ya;
  coord xb, yb;
  char *text;
} command;


#define NUMVIEWS 30

#define pl_x_left   pl->x_left[pl->viewno]
#define pl_x_right  pl->x_right[pl->viewno]
#define pl_y_top    pl->y_top[pl->viewno]
#define pl_y_bottom pl->y_bottom[pl->viewno]

#ifndef WINDOW_COORDS_IN_COMMAND_STRUCT
#define pspl_x_left   pspl.x_left[pspl.viewno]
#define pspl_x_right  pspl.x_right[pspl.viewno]
#define pspl_y_top    pspl.y_top[pspl.viewno]
#define pspl_y_bottom pspl.y_bottom[pspl.viewno]
#endif


/* prototypes */

void panic(char *s);
void fatalerror(char *s);


#endif
