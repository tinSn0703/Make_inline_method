
#include "Header.h"

using namespace std;

int main(void)
{
	cout << "メンバへの書き込みのみのinlineメソッドつくーる" << endl;

	cout << "func.txtに, \n" << endl;
	cout << "void A(int _a) \n";
	cout << "void B(int _a) \n";
	cout << "void C(int _a) \n";
	cout << "\nといった形で関数を入力してください。\n" << endl;
	
	cout << "variable.txtに, \n" << endl;
	cout << "a \n";
	cout << "b \n";
	cout << "c \n";
	cout << "\nといった形で変数を入力してください。\n" << endl;

	cout << "クラス名を入力してください" << endl;

	string _str_class;

	cin >> _str_class;

	cout << "実行結果" << endl;

	ifstream _file_func("func.txt");
	ifstream _file_var("variable.txt");
	ofstream _file("result.txt");

	string _str_func;
	string _str_var;

	while (!(_file_func.eof() | _file_var.eof()))
	{
		getline(_file_func, _str_func);
		getline(_file_var, _str_var);

		_file << "\n//----------------------------------------------------------------------//\n\n" << "inline ";
		cout << "\n//----------------------------------------------------------------------//\n\n" << "inline ";

		size_t _pos_tail_ver = Get_pos_tail_var(_str_var);

		size_t _point_func_name	= _str_func.find("(") - 2; //引数の(の位置を検索
		size_t _point_arg_name	= _str_func.find(")") - 1; //引数の)の位置を検索

		while ( ! ((_str_func[_point_func_name] == ' ') || (_str_func[_point_func_name] == '\t')))	_point_func_name--;	//関数の先頭の位置を検索
		while ( ! ((_str_func[_point_arg_name] == ' ')  || (_str_func[_point_arg_name] == '\t')))	_point_arg_name--;	//引数の先頭の位置を検索

		for (size_t i = 0; i < _point_func_name; i++) 	//関数の先頭位置までは戻り値のはずなので、そこまで出力
		{
			_file << _str_func[i];
			cout << _str_func[i];
		}

		_file << ' ' << _str_class << " ::";	//クラス名出力
		cout << ' ' << _str_class << " ::";

		for (size_t i = _point_func_name; _str_func[i] != ')'; i++)	//	関数名出力
		{
			_file << _str_func[i];
			cout << _str_func[i];
		}

		_file << ")\t{\t" << _str_var << " =";
		cout << ")\t{\t" << _str_var << " =";

		for (size_t i = _point_arg_name; _str_func[i] != ')'; i++)	//	引数名出力
		{
			_file << _str_func[i];
			cout << _str_func[i];
		}

		_file << ";\t}" << endl;
		cout << ";\t}" << endl;
	}

	_file << "\n//----------------------------------------------------------------------//\n" << endl;
	cout << "\n//----------------------------------------------------------------------//\n" << endl;
	
	cout << "0以外で終了" << endl;

	int _end = 0;
	while (_end == 0)	cin >> _end;
}