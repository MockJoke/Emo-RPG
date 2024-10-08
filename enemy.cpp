#include "enemy.h"
using namespace std; 

Enemy::Enemy(std::string name, EnemyType type, int health, int damage)
{
    setEnemyName(name);
    setEnemyHealth(health);
    setEnemyDamage(damage);
    setEnemyType(type);
}

string const Enemy::getEnemyName()
{
    return enemyName;
}

void Enemy::setEnemyName(string name)
{
    enemyName = name;
}

int const Enemy::getEnemyHealth()
{
    return enemyHealth;
}

void Enemy::setEnemyHealth(int health)
{
    enemyHealth = health;
}

int const Enemy::getEnemyDamage()
{
    return enemyDamage;
}

void Enemy::setEnemyDamage(int damage)
{
    enemyDamage = damage;
}

AttackType const Enemy::getAttackType()
{
    return attackType;
}

void Enemy::setAttackType(AttackType type)
{
    attackType = type;
}

EnemyType const Enemy::getEnemyType()
{
    return enemyType;
}

void Enemy::setEnemyType(EnemyType type)
{
    enemyType = type;
}

void Enemy::genEnemyDamage()
{
    if (enemyType == bossEnemy)
    {
        setEnemyDamage(10 + rand() % 5);
    }
    else
    {
        setEnemyDamage(0 + rand() % 5);
    }
}
