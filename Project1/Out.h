
#pragma once

#include <iostream>
#include <fstream>
#include <string>

void Out_func (size_t _pos_head_func, std::ofstream &_file, std :: string &_str_func);

void Out_arg(size_t _pos_head_arg, std::ofstream & _file, std::string & _str_func);

void Out_var (size_t _pos_head_var, size_t _pos_tail_var, std::ofstream &_file, std :: string &_str_var);

void Out_func_type (size_t _pos_head_func, std::ofstream &_file, std :: string &_str_func);

void Out_class (std::ofstream &_file, std :: string &_str_class);
