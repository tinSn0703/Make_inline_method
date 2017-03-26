
#include "MakeMethod.h"

#include "Header.h"

using namespace std;

//----------------------------------------------------------------------//

void MakeMethod::Get_pos_var_head()
{
	Get_pos_var_tail();

	_pos_var_head = Get_pos_head_var(_pos_var_tail, _str_var);
}

//----------------------------------------------------------------------//

void MakeMethod::Get_pos_var_tail()
{
	_pos_var_tail = Get_pos_tail_var(_str_var);
}

//----------------------------------------------------------------------//

void MakeMethod::Get_pos_func_head()
{
	_pos_func_head = Get_pos_head_func(_str_method);
}

//----------------------------------------------------------------------//

void MakeMethod::Get_pos_arg_head()
{
	_pos_arg_head = Get_pos_head_arg(_str_method);
}

//----------------------------------------------------------------------//

void MakeMethod::Write_func_type()
{
	Out_func_type(_pos_func_head, _file_result, _str_method);
}

//----------------------------------------------------------------------//

void MakeMethod::Write_func()
{
	Out_func(_pos_func_head, _file_result, _str_method);
}

//----------------------------------------------------------------------//

void MakeMethod::Write_var()
{
	Out_var(_pos_var_head, _pos_var_tail, _file_result, _str_var);
}

//----------------------------------------------------------------------//

void MakeMethod::Write_arg()
{
	Out_arg(_pos_arg_head, _file_result, _str_method);
}

//----------------------------------------------------------------------//

void MakeMethod::Write_class()
{
	Out_class(_file_result, _str_class);
}

//----------------------------------------------------------------------//

void MakeMethod::Write_part ()
{
	_file_result << "\n//----------------------------------------------------------------------//\n" << endl;
	cout << "\n//----------------------------------------------------------------------//\n" << endl;
}

//----------------------------------------------------------------------//

MakeMethod::MakeMethod(string _arg_str_func, string _arg_str_var, string _arg_str_result)

	: _file_method(_arg_str_func)
	, _file_var(_arg_str_var)
	, _file_result(_arg_str_result)
{
	_pos_arg_head = 0;
	_pos_func_head = 0;
	_pos_var_head = 0;
	_pos_var_tail = 0;
}

//----------------------------------------------------------------------//

void MakeMethod::Make_write_method()
{
	cout << "クラス名を入力してください" << endl;

	cin >> _str_class;

	cout << "実行結果" << endl;

	while( ! _file_var.eof())
	{
		getline(_file_method, _str_method);
		getline(_file_var, _str_var);

		Write_part();

		cout << _str_var << endl;
		cout << _str_method << "\n" << endl;

		Get_pos_var_head();
		Get_pos_arg_head();
		Get_pos_func_head();

		_file_result << "inline ";
		cout <<  "inline ";

		Write_func_type();
		Write_class();
		Write_func();

		_file_result << "\n{\n\t";
		cout << "\n{\n\t";

		Write_var();

		_file_result << " =";
		cout << " =";

		Write_arg();

		_file_result << ";\n}" << endl;
		cout << ";\t}" << endl;
	}

	Write_part();
}

//----------------------------------------------------------------------//

void MakeMethod::Make_read_method()
{
	cout << "クラス名を入力してください" << endl;

	cin >> _str_class;

	cout << "実行結果" << endl;

	while(!_file_var.eof())
	{
		Write_part();
		
		getline(_file_method, _str_method);
		getline(_file_var, _str_var);

		cout << _str_var << endl;
		cout << _str_method << "\n" << endl;

		Get_pos_func_head();
		Get_pos_var_head();

		_file_result << "inline ";
		cout <<  "inline ";

		Write_func_type();
		Write_class();
		Write_func();

		_file_result << "\n{\n\treturn ";
		cout << "\n{\n\treturn ";

		Write_var();

		_file_result << ";\n}" << endl;
		cout << ";\n}" << endl;
	}

	Write_part();
}

//----------------------------------------------------------------------//

void MakeMethod::Make_func_method()
{
	string _str_func;

	cout << "クラス名を入力してください" << endl;

	cin >> _str_class;

	cout << "\n中身を入力してください。" << endl;
	cout <<	"注意\n変数を入力する位置は「￥」にしてください。" << endl;
	cout << "最後は「$」にしてください。" << endl;

	while(1)
	{
		_str_func.clear();

		while(1)
		{
			string _str;

			cin >> _str;

			_str_func += ' ';
			_str_func += _str;

			if(_str.back() == '$')	break;
		}

		if(_str_func.rfind('\\') != -1)
		{
			break;
		}
		else
		{
			cout << "もう一度やり直してください" << endl;
		}
	}

	cout << "\n実行結果" << endl;

	while(!_file_var.eof())
	{
		Write_part();

		getline(_file_method, _str_method);
		getline(_file_var, _str_var);

		cout << _str_var << endl;
		cout << _str_method << "\n" << endl;

		Get_pos_func_head();
		Get_pos_var_head();

		_file_result << "inline ";
		cout <<  "inline ";

		Write_func_type();
		Write_class();
		Write_func();

		_file_result << "\n{\n\t";
		cout << "\n{\n\t";

		for (size_t i = 0; _str_func[i] != '\0'; i++)
		{
			if(_str_func[i] == '\\')
			{
				Write_var();

				i++;
			}

			if(_str_func[i] == '$')	break;

			_file_result << _str_func[i];
			cout << _str_func[i];
		}

		_file_result << ";\n}" << endl;
		cout << ";\n}" << endl;
	}

	Write_part();
}

//----------------------------------------------------------------------//

void MakeMethod::Make_func_call_method()
{
	string _str_func;

	cout << "クラス名を入力してください" << endl;

	cin >> _str_class;

	while( ! _file_var.eof())
	{
		getline(_file_method, _str_method);
		getline(_file_var, _str_var);

		Write_part();

		cout << _str_var << endl;
		cout << _str_method << "\n" << endl;

		Get_pos_var_head();
		Get_pos_arg_head();
		Get_pos_func_head();

		_file_result << "inline ";
		cout <<  "inline ";

		Write_func_type();
		Write_class();
		Write_func();

		_file_result << "\n{\n\t";
		cout << "\n{\n\t";

		Write_var();

		_file_result << ";\n}" << endl;
		cout << ";\n}" << endl;
	}

	Write_part();
}

//----------------------------------------------------------------------//

void MakeMethod :: Make_func()
{
	cout << "クラス名を入力してください" << endl;

	cin >> _str_class;

	cout << "実行結果" << endl;

	while (! _file_method.eof())
	{
		getline(_file_method, _str_method);

		Write_part();

		cout << _str_method << "\n" << endl;

		Get_pos_func_head();

		_file_result << "inline ";
		cout <<  "\ninline ";

		Write_func_type();
		Write_class();
		Write_func();

		_file_result << "\n{\n\t\n}" << endl;
		cout << "\n{\n\t\n}" << endl;
	}

	Write_part();
}

//----------------------------------------------------------------------//
