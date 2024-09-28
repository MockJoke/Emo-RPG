#pragma once

#include <string>
#include <vector>
using namespace std; 

enum EnemyType
{
	normalEnemy,
	bossEnemy
};

enum AttackType
{
	ego,		
	pessimism,			 
	anxiety 
};

class Enemy {
private:
	string enemyName;
	int enemyHealth;
	int enemyDamage;
	EnemyType enemyType;
	AttackType attackType;

public:
	vector<Enemy*> enemy;

	Enemy(string, EnemyType, int, int);
	string const getEnemyName();
	void setEnemyName(string);
	int const getEnemyHealth();
	void setEnemyHealth(int);
	int const getEnemyDamage();
	void setEnemyDamage(int);
	AttackType const getAttackType();
	void setAttackType(AttackType);
	EnemyType const getEnemyType();
	void setEnemyType(EnemyType);
	void genEnemyDamage();

}; 
