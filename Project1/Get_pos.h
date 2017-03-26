
#pragma once

/************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

/************************************************************************/

size_t Get_pos_tail_var (std::string &_str_var);

size_t Get_pos_head_var (size_t _pos_tail_var, std::string &_str_var);

size_t Get_pos_head_func (std::string &_str_func);

size_t Get_pos_head_arg (std::string &_str_func);

/************************************************************************/
