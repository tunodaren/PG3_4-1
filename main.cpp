#include <iostream>
using namespace std;


// 自作クラス
class Enemy {
public:


	void Func1();
	void Func2();
	void Func3();

	void Update();

	// メンバ関数ポインタのテーブル
	static void (Enemy::* table[])();

private:
	// メンバ関数ポインタのテーブルを参照するインデックス
	int index = 0;
};

void Enemy::Func1() {
	cout << "敵の接近！" << endl;
}

void Enemy::Func2() {
	cout << "敵の攻撃！" << endl;
}

void Enemy::Func3() {
	cout << "敵の後退！" << endl;
}

void Enemy::Update() {

	// 関数ポインタのテーブルから関数を実行
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
		/*敵の状態（関数ポインタ配列のインデックス）を+1*/
		/*インデックスが配列の最後の要素なら他の値を入れる*/
	}
	
}

// staticで宣言したメンバ関数ポインタテーブルの実体
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