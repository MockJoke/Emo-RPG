#include "player.h"
using namespace std; 

Player::Player(string name, string aura, int health, int damage)
{
	setPlayerName(name);
	setPlayerAura(aura);
	setPlayerHealth(health);
	setMeleeDamage(damage);
}

string const Player::getPlayerName()
{
	return playerName;
}

void Player::setPlayerName(string name)
{
	playerName = name;
}

string const Player::getPlayerAura()
{
	return playerAura;
}

void Player::setPlayerAura(string aura)
{
	playerAura = aura;
}

int const Player::getPlayerLevel()
{
	return playerLevel;
}

void Player::setPlayerLevel(int level)
{
	playerLevel = level;
}

int const Player::getPlayerHealth()
{
	return playerHealth;
}

void Player::setPlayerHealth(int health)
{
	playerHealth = health;
}

int const Player::getMeleeDamage()
{
	return meleeDamage;
}

void Player::setMeleeDamage(int damage)
{
	meleeDamage = damage;
}

int const Player::getRangedDamage()
{
	return rangedDamage;
}

void Player::setRangedDamage(int damage)
{
	rangedDamage = damage;
}

CoreValue const Player::getCoreValue()
{
	return coreValue;
}

void Player::setCoreValue(CoreValue corevalue)
{
	coreValue = corevalue;
}

void Player::genRangedDamage()
{
	setRangedDamage(5 + rand() % 10);
}
