#include <iostream>
using namespace std;


// ����N���X
class Enemy {
public:


	void Func1();
	void Func2();
	void Func3();

	void Update();

	// �����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* table[])();

private:
	// �����o�֐��|�C���^�̃e�[�u�����Q�Ƃ���C���f�b�N�X
	int index = 0;
};

void Enemy::Func1() {
	cout << "�G�̐ڋ߁I" << endl;
}

void Enemy::Func2() {
	cout << "�G�̍U���I" << endl;
}

void Enemy::Func3() {
	cout << "�G�̌�ށI" << endl;
}

void Enemy::Update() {

	// �֐��|�C���^�̃e�[�u������֐������s
	(this->*table[index])();
	int a;;
	scanf_s("%d",& a);

	if (a == 0) {

		if(index == 2){
			index = 0;
		}else
		{
			index++;
		}
		/*�G�̏�ԁi�֐��|�C���^�z��̃C���f�b�N�X�j��+1*/
		/*�C���f�b�N�X���z��̍Ō�̗v�f�Ȃ瑼�̒l������*/
	}
	
}

// static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (Enemy::* Enemy::table[])() = {
  &Enemy::Func1,
  &Enemy::Func2,
  &Enemy::Func3,
};


int main()
{
	Enemy my;

	while (true)
	{
   my.Update();
	}
	

	return 0;
}