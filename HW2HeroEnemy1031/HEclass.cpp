#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HEclass.h"
using namespace std;

//�R���X�g���N�^
Hero::Hero(char* pName, int hp) {
	//���O���R�s�[
	_nameSize = strlen(pName);
	_pName = new char[_nameSize + 1];
	for (int i = 0; i < _nameSize; ++i) {
		_pName[i] = pName[i];
	}
	_pName[_nameSize] = '\0';

	//���̃p�����[�^�[��������
	_hp = hp;
	_attack = 75;
	_diffence = 20;
}

//�f�X�g���N�^
Hero::~Hero() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

void Hero::show() {
	printf("\n���O�F%s\n", _pName);
	printf("�̗́F%d\n", _hp);
	printf("�U���́F%d,", _attack);
	printf("�h��́F%d\n\n", _diffence);
}

void Enemy::operator*(const int i)
{
	_hp *= i;
	_attack *= i;
	_diffence *= i;
}

//�R���X�g���N�^
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

//�f�X�g���N�^
Enemy::~Enemy() {
	if (_pName != NULL) {
		delete[] _pName;
		_pName = NULL;
	}
}

void Enemy::show() {
	printf("\n���O�F%s\n", _pName);
	printf("�̗́F%d\n", _hp);
	printf("�U���́F%d,", _attack);
	printf("�h��́F%d\n\n", _diffence);
}

void Hero::attack(Enemy* enemy) {
	int deffence = enemy->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("\n%s�̍U���I\n%d�̃_���[�W��^����\n", _pName, damage);

	int hp = enemy->getHp();
	enemy->setHp(hp - damage);
	printf("����̎c��HP�F%d\n\n", enemy->getHp());
}

void Enemy::attack(Hero* hero) {
	int deffence = hero->getDiffence();
	int damage = 0;
	damage = _attack - deffence;
	printf("\n%s�̍U���I\n%d�̃_���[�W��^����\n", _pName, damage);

	int hp = hero->getHp();
	hero->setHp(hp - damage);
	printf("�G�̎c��HP�F%d\n\n", hero->getHp());
}

void Hero::heal() {
	int healHp = 0;
	printf("\n�ǂ̂��炢�񕜂��܂����@���@");
	cin >> healHp;
	_hp += healHp;

	printf("\n%s�̎c��HP�F%d\n\n", _pName, _hp);
}

void Enemy::heal() {
	int healHp = 0;
	printf("\n�ǂ̂��炢�񕜂��܂����@���@");
	cin >> healHp;
	_hp += healHp;

	printf("\n%s�̎c��HP�F%d\n\n", _pName, _hp);
}