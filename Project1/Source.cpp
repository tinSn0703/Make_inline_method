
#include "MakeMethod.h"

using namespace std;

int main(void)
{
	int _mode = 0;

	cout << "inline程度でいいメソッドメーカー" << endl;
	
	cout << "type A (type _a) \n";
	cout << "type B (type _b) \n";
	cout << "type C (type _c) \n";
	cout << "このような形で関数が入力されたファイルを用意してください。\n" << endl;

	cout << "a \n";
	cout << "b \n";
	cout << "c \n";
	cout << "このような形で変数が入力されたファイルを用意してください。\n" << endl;
	
	string _str_func("func.txt");
	string _str_var("var.txt");
	string _str_result("result.txt");

	int i = 0;

	cout << "下のデフォルト名を使いますか？ Yes -> ~0, No -> 0" << endl;
	cout << _str_func << endl;
	cout << _str_var << endl;
	cout << _str_result << endl;
	cin >> i;

	if ( ! i)
	{
		cout << "メソッド名が記入されているファイル名を入力してください。" << endl;
		cin >> _str_func;

		cout << "\n変数名が記入されているファイル名を入力してください。" << endl;
		cin >> _str_var;

		cout << "\n結果が記入されるファイル名を入力してください。" << endl;
		cin >> _str_result;
	}

	cout << "\n読み出しのみのメソッドの場合は0を、" << endl;
	cout <<	"書き込みのみのメソッドの場合は1を、" << endl;
	cout << "関数に変数を入力するメソッドの場合は2を、" << endl;
	cout << "関数を呼び出すだけのメソッドの場合は3を、" << endl;
	cout << "inline関数の実装を作成したい場合は4を、" << endl;
	cout << "入力してください\n" << endl;
	cout << "例 : 0 inline type Class :: A ()	{	return a;	}" << endl;
	cout << "例 : 1 inline void Class :: A (type _a)	{	_a = a;		}" << endl;
	cout << "例 : 2 inline void Class :: A ()	{	Func(a);	}" << endl;
	cout << "例 : 3 inline void Class :: A ()	{	Func();		}" << endl;
	cout << "例 : 4 inline void Class :: A (type _a)	{	}" << endl;

	MakeMethod _make(_str_func, _str_var, _str_result);

	for (int i = 0; i < 5; i++)
	{
		_mode++;

		cin >> _mode;

		switch(_mode)
		{
			case 0:	_make.Make_read_method();		goto _goto_end;
			case 1:	_make.Make_write_method();		goto _goto_end;
			case 2:	_make.Make_func_method();		goto _goto_end;
			case 3:	_make.Make_func_call_method();	goto _goto_end;
			case 4:	_make.Make_func();				goto _goto_end;
			default:
			{
				cout << _mode << " 値が違います。もう一度入力してください。" << endl;

				break;
			}
		}
	}

	cout << "Erorr 終了してください" << endl;

	while(1);

	_goto_end:

	cout << "完了しました。終了してください。" << endl;

	while(1);
}
