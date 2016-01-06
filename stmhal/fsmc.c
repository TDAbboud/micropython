/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>

#include STM32_HAL_H

#include "py/runtime.h"
#include "irq.h"
#include "mphalport.h"

/// \moduleref pyb
/// \class FSMC - Flexible Static Memory Controller 
///
///
/// Example usage:
///


/******************************************************************************/
// Micro Python bindings

typedef struct _pyb_fsmc_obj_t {
    mp_obj_base_t base;
} pyb_fsmc_obj_t;

STATIC const pyb_fsmc_obj_t pyb_fsmc_obj = {{&pyb_fsmc_type}};

/// \classmethod \constructor()
/// Create an FSMC object.
STATIC mp_obj_t pyb_fsmc_make_new(mp_obj_t type_in, mp_uint_t n_args, mp_uint_t n_kw, const mp_obj_t *args) {
    // check arguments
    mp_arg_check_num(n_args, n_kw, 0, 0, false);

    // return constant object
    return (mp_obj_t)&pyb_fsmc_obj;
}

mp_obj_t pyb_fsmc_init(mp_obj_t self_in) {
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(pyb_rtc_init_obj, pyb_rtc_init);


STATIC const mp_map_elem_t pyb_fsmc_locals_dict_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR_init), (mp_obj_t)&pyb_fsmc_init_obj },
};
STATIC MP_DEFINE_CONST_DICT(pyb_fsmc_locals_dict, pyb_fsmc_locals_dict_table);


const mp_obj_type_t pyb_fsmc_type = {
    { &mp_type_type },
    .name = MP_QSTR_FSMC,
    .make_new = pyb_fsmc_make_new,
    .locals_dict = (mp_obj_t)&pyb_fsmc_locals_dict,
}
