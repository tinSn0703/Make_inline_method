
#include "MakeMethod.h"

using namespace std;

int main(void)
{
	int _mode = 0;

	cout << "inline���x�ł������\�b�h���[�J�[" << endl;
	
	cout << "type A (type _a) \n";
	cout << "type B (type _b) \n";
	cout << "type C (type _c) \n";
	cout << "���̂悤�Ȍ`�Ŋ֐������͂��ꂽ�t�@�C����p�ӂ��Ă��������B\n" << endl;

	cout << "a \n";
	cout << "b \n";
	cout << "c \n";
	cout << "���̂悤�Ȍ`�ŕϐ������͂��ꂽ�t�@�C����p�ӂ��Ă��������B\n" << endl;
	
	string _str_func("func.txt");
	string _str_var("var.txt");
	string _str_result("result.txt");

	int i = 0;

	cout << "���̃f�t�H���g�����g���܂����H Yes -> ~0, No -> 0" << endl;
	cout << _str_func << endl;
	cout << _str_var << endl;
	cout << _str_result << endl;
	cin >> i;

	if ( ! i)
	{
		cout << "���\�b�h�����L������Ă���t�@�C��������͂��Ă��������B" << endl;
		cin >> _str_func;

		cout << "\n�ϐ������L������Ă���t�@�C��������͂��Ă��������B" << endl;
		cin >> _str_var;

		cout << "\n���ʂ��L�������t�@�C��������͂��Ă��������B" << endl;
		cin >> _str_result;
	}

	cout << "\n�ǂݏo���݂̂̃��\�b�h�̏ꍇ��0���A" << endl;
	cout <<	"�������݂݂̂̃��\�b�h�̏ꍇ��1���A" << endl;
	cout << "�֐��ɕϐ�����͂��郁�\�b�h�̏ꍇ��2���A" << endl;
	cout << "�֐����Ăяo�������̃��\�b�h�̏ꍇ��3���A" << endl;
	cout << "inline�֐��̎������쐬�������ꍇ��4���A" << endl;
	cout << "���͂��Ă�������\n" << endl;
	cout << "�� : 0 inline type Class :: A ()	{	return a;	}" << endl;
	cout << "�� : 1 inline void Class :: A (type _a)	{	_a = a;		}" << endl;
	cout << "�� : 2 inline void Class :: A ()	{	Func(a);	}" << endl;
	cout << "�� : 3 inline void Class :: A ()	{	Func();		}" << endl;
	cout << "�� : 4 inline void Class :: A (type _a)	{	}" << endl;

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
				cout << _mode << " �l���Ⴂ�܂��B������x���͂��Ă��������B" << endl;

				break;
			}
		}
	}

	cout << "Erorr �I�����Ă�������" << endl;

	while(1);

	_goto_end:

	cout << "�������܂����B�I�����Ă��������B" << endl;

	while(1);
}
