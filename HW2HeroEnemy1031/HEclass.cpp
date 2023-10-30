#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HEclass.h"
using namespace std;

//コンストラクタ
Hero::Hero(char* pName, int hp) {
	//名前をコピー
	_nameSize = strlen(pName);
	_pName = new char[_nameSize + 1];
	for (int i = 0; i < _nameSize; ++i) {
		_pName[i] = pName[i];
	}
	_pName[_nameSize] = '\0';

	//他のパラメーターを初期化
	_hp = hp;
	_attack = 75;
	_diffence = 20;
}

//デストラクタ
Hero::~Hero() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

void Hero::show() {
	printf("\n名前：%s\n", _pName);
	printf("体力：%d\n", _hp);
	printf("攻撃力：%d,", _attack);
	printf("防御力：%d\n\n", _diffence);
}

void Enemy::operator*(const int i)
{
	_hp *= i;
	_attack *= i;
	_diffence *= i;
}

//コンストラクタ
Enemy::Enemy(char* pName, int hp) {
	_nameSize = strlen(pName);
	_pName = new char[_nameSize + 1];
	for (int i = 0; i < _nameSize; ++i) {
		_pName[i] = pName[i];
	}
	_pName[_nameSize] = '\0';

	_hp = hp;
	_attack = 75;
	_diffence = 20;
}

//デストラクタ
Enemy::~Enemy() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

void Enemy::show() {
	printf("\n名前：%s\n", _pName);
	printf("体力：%d\n", _hp);
	printf("攻撃力：%d,", _attack);
	printf("防御力：%d\n\n", _diffence);
}

void Hero::attack(Enemy* enemy) {
	int deffence = enemy->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("\n%sの攻撃！\n%dのダメージを与えた\n", _pName, damage);

	int hp = enemy->getHp();
	enemy->setHp(hp - damage);
	printf("相手の残りHP：%d\n\n", enemy->getHp());
}

void Enemy::attack(Hero* hero) {
	int deffence = hero->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("\n%sの攻撃！\n%dのダメージを与えた\n", _pName, damage);

	int hp = hero->getHp();
	hero->setHp(hp - damage);
	printf("敵の残りHP：%d\n\n", hero->getHp());
}

void Hero::heal() {
	int healHp = 0;
	printf("\nどのくらい回復しますか　＞　");
	cin >> healHp;
	_hp += healHp;

	printf("\n%sの残りHP：%d\n\n", _pName, _hp);
}

void Enemy::heal() {
	int healHp = 0;
	printf("\nどのくらい回復しますか　＞　");
	cin >> healHp;
	_hp += healHp;

	printf("\n%sの残りHP：%d\n\n", _pName, _hp);
}