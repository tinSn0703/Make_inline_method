
#include "Header.h"

using namespace std;

int main(void)
{
	cout << "�����o�ւ̏������݂݂̂�inline���\�b�h���[��" << endl;

	cout << "func.txt��, \n" << endl;
	cout << "void A(int _a) \n";
	cout << "void B(int _a) \n";
	cout << "void C(int _a) \n";
	cout << "\n�Ƃ������`�Ŋ֐�����͂��Ă��������B\n" << endl;
	
	cout << "variable.txt��, \n" << endl;
	cout << "a \n";
	cout << "b \n";
	cout << "c \n";
	cout << "\n�Ƃ������`�ŕϐ�����͂��Ă��������B\n" << endl;

	cout << "�N���X������͂��Ă�������" << endl;

	string _str_class;

	cin >> _str_class;

	cout << "���s����" << endl;

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

		size_t _point_func_name	= _str_func.find("(") - 2; //������(�̈ʒu������
		size_t _point_arg_name	= _str_func.find(")") - 1; //������)�̈ʒu������

		while ( ! ((_str_func[_point_func_name] == ' ') || (_str_func[_point_func_name] == '\t')))	_point_func_name--;	//�֐��̐擪�̈ʒu������
		while ( ! ((_str_func[_point_arg_name] == ' ')  || (_str_func[_point_arg_name] == '\t')))	_point_arg_name--;	//�����̐擪�̈ʒu������

		for (size_t i = 0; i < _point_func_name; i++) 	//�֐��̐擪�ʒu�܂ł͖߂�l�̂͂��Ȃ̂ŁA�����܂ŏo��
		{
			_file << _str_func[i];
			cout << _str_func[i];
		}

		_file << ' ' << _str_class << " ::";	//�N���X���o��
		cout << ' ' << _str_class << " ::";

		for (size_t i = _point_func_name; _str_func[i] != ')'; i++)	//	�֐����o��
		{
			_file << _str_func[i];
			cout << _str_func[i];
		}

		_file << ")\t{\t" << _str_var << " =";
		cout << ")\t{\t" << _str_var << " =";

		for (size_t i = _point_arg_name; _str_func[i] != ')'; i++)	//	�������o��
		{
			_file << _str_func[i];
			cout << _str_func[i];
		}

		_file << ";\t}" << endl;
		cout << ";\t}" << endl;
	}

	_file << "\n//----------------------------------------------------------------------//\n" << endl;
	cout << "\n//----------------------------------------------------------------------//\n" << endl;
	
	cout << "0�ȊO�ŏI��" << endl;

	int _end = 0;
	while (_end == 0)	cin >> _end;
}