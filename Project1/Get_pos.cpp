
#include "Get_pos.h"

using namespace std;

/************************************************************************/

//----------------------------------------------------------------------//

size_t Get_pos_tail_var (string &_arg_str_var)
{
	cout << "変数名の後尾";
	cout << " " << _arg_str_var;

	size_t _pos = 0;

	while
		( !
			(
				(_arg_str_var[_pos] == '/')		||
				(_arg_str_var[_pos] == ':')		||
				(_arg_str_var[_pos] == ';')		||
				(_arg_str_var[_pos] == '\0')
			)
		)
	{
		_pos++;	//変数以外の余分な部分の先頭位置を探索する
	}

	while (_arg_str_var[_pos] != '\0') //余分な部分を削除
	{
		_arg_str_var.pop_back();
	}

	if	//余分な部分を削除
		(
			(_arg_str_var[_pos - 1] == ' ')		|| 
			(_arg_str_var[_pos - 1] == '\t')
		)
	{
		_arg_str_var.pop_back();

		_pos--;
	}

	cout << " tail = " << _pos << endl;

	return _pos;
}

//----------------------------------------------------------------------//

size_t Get_pos_head_var (size_t _arg_pos_tail_var, string &_arg_str_var)
{
	cout << "変数名の先頭";
	cout << " " << _arg_str_var;

	size_t _pos = _arg_pos_tail_var - 1;

	while (1)
	{
		if	(
				(_pos == 0) ||
				(_arg_str_var[_pos] == ' ') ||
				(_arg_str_var[_pos] == '\t')
			)
		//0もしくは、スペースならばその位置が先頭のはずなので探索終了
		{
			break;
		}

		if (_pos > 2) //変な場所にアクセスしないため
		{
			if
				(
					(_arg_str_var[_pos - 0] == '(') ||
					(_arg_str_var[_pos - 2] == ',')
				)
			//どうやら変数じゃなくて関数だったみたいです
			//まあ気にせず探索します
			{
				_pos--;
			}
		}

		_pos--;
	}

	if (_pos != 0)	_pos++;

	cout << " head = " << _pos << endl;

	return _pos;
}

//----------------------------------------------------------------------//

size_t Get_pos_head_func (string &_arg_str_func)
{
	cout << "関数名の先頭";
	cout << " " << _arg_str_func;

	size_t _pos = _arg_str_func.find("(") - 2; //引数の(の位置を検索

	if(_pos < 0)	return 0;

	while
		( !
			(
				(_arg_str_func[_pos] == ' ')	||
				(_arg_str_func[_pos] == '\t')
			)
		)
	{
		_pos--;	//関数の先頭の位置を検索
	}

	cout << " head = " << _pos << endl;

	return _pos;
}

//----------------------------------------------------------------------//

size_t Get_pos_head_arg (string &_arg_str_func)
{
	cout << "引数名の先頭";
	cout << " "<< _arg_str_func;

	size_t _pos = _arg_str_func.rfind(")") - 1; //引数の)の位置を検索
	
	if(_pos < 0)	return 0;

	while
		( ! 
			(
				(_arg_str_func[_pos] == ' ')  || 
				(_arg_str_func[_pos] == '\t')
			)
		)
	{
		_pos--;	//引数の先頭の位置を検索
	}

	cout << " head = " << _pos << endl;

	return _pos;
}

//----------------------------------------------------------------------//

/************************************************************************/
