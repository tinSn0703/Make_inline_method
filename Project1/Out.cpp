
#include "Out.h"

using namespace std;

void Out_var
(
	const size_t	 _arg_pos_head_var,
	const size_t	 _arg_pos_tail_var,
	ofstream		&_arg_file,
	string			&_arg_str_var
)
{
	for(size_t i = _arg_pos_head_var; i < _arg_pos_tail_var; i++)
	{
		_arg_file << _arg_str_var[i];

		cout << _arg_str_var[i];
	}
}

//----------------------------------------------------------------------//

void Out_func_type
(
	const size_t	 _arg_pos_head_func,
	ofstream		&_arg_file,
	string			&_arg_str_func
)
{
	size_t _pos = 0;

	while 
		(
			(_arg_str_func[_pos] == '\t')	|| 
			(_arg_str_func[_pos] == ' ')	||
			(_arg_str_func[_pos] == '{')
		)
	{
		if(_arg_str_func[_pos] == '\0')
		{
			cout << "\nERORR " << __func__ << endl;

			return (void)0;
		}

		_pos++;
	}

	for(size_t i = _pos; i < _arg_pos_head_func; i++)
	{
		_arg_file << _arg_str_func[i];

		cout << _arg_str_func[i];
	}
}

//----------------------------------------------------------------------//

void Out_func
(
	const size_t	 _arg_pos_head_func,
	ofstream		&_arg_file,
	string			&_arg_str_func
)
{
	if(_arg_pos_head_func <= 0)
	{
		cout << "\nERORR " << __func__ << endl;

		return (void)0;
	}

	for(size_t i = _arg_pos_head_func; _arg_str_func[i] != ')'; i++)
	{
		if(_arg_str_func[i] == '\0')
		{
			cout << "\nERORR " << __func__ << endl;

			return (void)0;
		}

		_arg_file << _arg_str_func[i];

		cout << _arg_str_func[i];
	}

	_arg_file << ")";
	cout << ")";
}

//----------------------------------------------------------------------//

void Out_arg
(
	const size_t	 _arg_pos_head_arg, 
	ofstream		&_arg_file,
	string			&_arg_str_func
)
{
	if(_arg_pos_head_arg <= 0)
	{
		cout << "\nERORR " << __func__ << endl;

		return (void)0;
	}

	for(size_t i = _arg_pos_head_arg; _arg_str_func[i] != ')'; i++)
	{
		if(_arg_str_func[i] == '\0')
		{
			cout << "\nERORR " << __func__ << endl;

			return (void)0;
		}

		_arg_file << _arg_str_func[i];
		cout << _arg_str_func[i];
	}
}

//----------------------------------------------------------------------//

void Out_class
(
	ofstream	&_arg_file,
	string		&_arg_str_class
)
{
	_arg_file << ' ' << _arg_str_class << " ::";	//ƒNƒ‰ƒX–¼o—Í

	cout << ' ' << _arg_str_class << " ::";
}

//----------------------------------------------------------------------//

/************************************************************************/
