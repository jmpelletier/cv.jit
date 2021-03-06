/*
max.cv.jit.lines
	

Copyright 2010, Jean-Marc Pelletier
jmp@jmpelletier.com

This file is part of cv.jit.

cv.jit is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published 
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

cv.jit is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with cv.jit.  If not, see <http://www.gnu.org/licenses/>.

*/


#include "c74_jitter.h"

using namespace c74::max;

typedef struct _max_cv_jit_lines 
{
	t_object		ob;
	void			*obex;
} t_max_cv_jit_lines;

t_jit_err cv_jit_lines_init(void); 

void *max_cv_jit_lines_new(t_symbol *s, long argc, t_atom *argv);
void max_cv_jit_lines_free(t_max_cv_jit_lines *x);
void *max_cv_jit_lines_class;
	
#ifdef __cplusplus
extern "C"
#endif
void ext_main(void* unused)
{	
	void *p,*q;
	
	union { void **v_ptr; t_messlist **m_ptr; } alias_ptr;
	alias_ptr.v_ptr = &max_cv_jit_lines_class;
	cv_jit_lines_init();
	setup(alias_ptr.m_ptr, (method)max_cv_jit_lines_new, (method)max_cv_jit_lines_free, (short)sizeof(t_max_cv_jit_lines), 
		0L, A_GIMME, 0);

	p = max_jit_classex_setup(calcoffset(t_max_cv_jit_lines,obex));
	q = jit_class_findbyname(gensym("cv_jit_lines"));    
    max_jit_classex_mop_wrap(p,q,0); 		
    max_jit_classex_standard_wrap(p,q,0); 	
    addmess((method)max_jit_mop_assist, "assist", A_CANT,0);
}

void max_cv_jit_lines_free(t_max_cv_jit_lines *x)
{
	max_jit_mop_free(x);
	jit_object_free(max_jit_obex_jitob_get(x));
	max_jit_obex_free(x);
}

void *max_cv_jit_lines_new(t_symbol *s, long argc, t_atom *argv)
{
	t_max_cv_jit_lines *x;
	void *o;

	if ((x=(t_max_cv_jit_lines *)max_jit_obex_new(max_cv_jit_lines_class,gensym("cv_jit_lines")))) {
		if ((o= (t_jit_object*)jit_object_new(gensym("cv_jit_lines")))) {
			max_jit_mop_setup_simple(x,o,argc,argv);			
			max_jit_attr_args(x,argc,argv);
		} else {
			object_error((t_object*)x, "cv.jit.lines: could not allocate object");
			object_free((t_object *)x);
		}
	}
	return (x);
}
