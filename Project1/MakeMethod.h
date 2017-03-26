
#pragma once

#include <iostream>
#include <fstream>
#include <string>

class MakeMethod
{
private:

	std :: ifstream _file_method;
	std :: ifstream _file_var;

	std :: ofstream _file_result;

	std :: string _str_method;
	std :: string _str_var;
	std :: string _str_class;

protected:

	size_t _pos_var_head;
	size_t _pos_var_tail;

	size_t _pos_func_head;

	size_t _pos_arg_head;

	void Get_pos_var_head ();
	void Get_pos_var_tail ();

	void Get_pos_func_head ();

	void Get_pos_arg_head ();

	void Write_func_type ();
	void Write_func ();
	void Write_var ();
	void Write_arg();
	void Write_class ();

	void Write_part();

public:

	MakeMethod (std :: string _str_func, std :: string _str_var, std::string _str_result);

	void Make_write_method ();
	void Make_read_method ();
	void Make_func_method();
	void Make_func_call_method();
	void Make_func();
};
