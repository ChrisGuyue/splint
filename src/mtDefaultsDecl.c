/*
** LCLint - annotation-assisted static program checker
** Copyright (C) 1994-2001 University of Virginia,
**         Massachusetts Institute of Technology
**
** This program is free software; you can redistribute it and/or modify it
** under the terms of the GNU General Public License as published by the
** Free Software Foundation; either version 2 of the License, or (at your
** option) any later version.
** 
** This program is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** General Public License for more details.
** 
** The GNU General Public License is available from http://www.gnu.org/ or
** the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
** MA 02111-1307, USA.
**
** For information on lclint: lclint-request@cs.virginia.edu
** To report a bug: lclint-bug@cs.virginia.edu
** For more information: http://lclint.cs.virginia.edu
*/
/*
** mtDefaultsDecl.c
*/

# include "lclintMacros.nf"
# include "basic.h"
# include "mtgrammar.h"

extern mtDefaultsDecl 
mtDefaultsDecl_create  (/*@only@*/ mtContextNode context, 
			       /*@only@*/ mttok value)
{
  mtDefaultsDecl res = (mtDefaultsDecl) dmalloc (sizeof (*res));
  
  llassert (mttok_isIdentifier (value));

  res->context = context;
  res->loc = fileloc_copy (mttok_getLoc (value));
  res->value = mttok_getText (value);
  
  mttok_free (value);
  return res;
}

extern void mtDefaultsDecl_free (mtDefaultsDecl dd)
{
  cstring_free (dd->value);
  fileloc_free (dd->loc);
  mtContextNode_free (dd->context);
  sfree (dd);
}

extern cstring mtDefaultsDecl_unparse (mtDefaultsDecl node)
{
  return message ("%s %q",
		  node->value, mtContextNode_unparse (node->context));
}