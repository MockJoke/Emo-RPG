#pragma once

#include <string>
using namespace std; 

enum CoreValue		 
{
	courage,		
	forgiveness,			
	focus,			 
	kindness		
};

enum coreDamage
{
	WillPower,	
	modesty,
	SelfAwareness,			 	 
	transcendence				
};

class Player 
{
private:
	string playerName;
	string playerAura;		
	int playerLevel;			
	int playerHealth;
	int meleeDamage;
	int rangedDamage;
	CoreValue coreValue;

public:
	Player(string, string, int, int);

	string const getPlayerName();
	void setPlayerName(string);
	string const getPlayerAura();
	void setPlayerAura(string);
	int const getPlayerLevel();
	void setPlayerLevel(int);
	int const getPlayerHealth();
	void setPlayerHealth(int);
	int const getMeleeDamage();
	void setMeleeDamage(int);
	int const getRangedDamage();
	void setRangedDamage(int);
	CoreValue const getCoreValue();
	void setCoreValue(CoreValue);
	void genRangedDamage();

}; 
