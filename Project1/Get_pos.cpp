
#include "Get_pos.h"

using namespace std;

/************************************************************************/

//----------------------------------------------------------------------//

size_t Get_pos_tail_var (string &_arg_str_var)
{
	cout << "�ϐ����̌��";
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
		_pos++;	//�ϐ��ȊO�̗]���ȕ����̐擪�ʒu��T������
	}

	while (_arg_str_var[_pos] != '\0') //�]���ȕ������폜
	{
		_arg_str_var.pop_back();
	}

	if	//�]���ȕ������폜
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
	cout << "�ϐ����̐擪";
	cout << " " << _arg_str_var;

	size_t _pos = _arg_pos_tail_var - 1;

	while (1)
	{
		if	(
				(_pos == 0) ||
				(_arg_str_var[_pos] == ' ') ||
				(_arg_str_var[_pos] == '\t')
			)
		//0�������́A�X�y�[�X�Ȃ�΂��̈ʒu���擪�̂͂��Ȃ̂ŒT���I��
		{
			break;
		}

		if (_pos > 2) //�ςȏꏊ�ɃA�N�Z�X���Ȃ�����
		{
			if
				(
					(_arg_str_var[_pos - 0] == '(') ||
					(_arg_str_var[_pos - 2] == ',')
				)
			//�ǂ����ϐ�����Ȃ��Ċ֐��������݂����ł�
			//�܂��C�ɂ����T�����܂�
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
	cout << "�֐����̐擪";
	cout << " " << _arg_str_func;

	size_t _pos = _arg_str_func.find("(") - 2; //������(�̈ʒu������

	if(_pos < 0)	return 0;

	while
		( !
			(
				(_arg_str_func[_pos] == ' ')	||
				(_arg_str_func[_pos] == '\t')
			)
		)
	{
		_pos--;	//�֐��̐擪�̈ʒu������
	}

	cout << " head = " << _pos << endl;

	return _pos;
}

//----------------------------------------------------------------------//

size_t Get_pos_head_arg (string &_arg_str_func)
{
	cout << "�������̐擪";
	cout << " "<< _arg_str_func;

	size_t _pos = _arg_str_func.rfind(")") - 1; //������)�̈ʒu������
	
	if(_pos < 0)	return 0;

	while
		( ! 
			(
				(_arg_str_func[_pos] == ' ')  || 
				(_arg_str_func[_pos] == '\t')
			)
		)
	{
		_pos--;	//�����̐擪�̈ʒu������
	}

	cout << " head = " << _pos << endl;

	return _pos;
}

//----------------------------------------------------------------------//

/************************************************************************/
