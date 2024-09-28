#include "GameManager.h"
#include "clear.h"
#include "ASCIIart.h"
#include <fstream>
#include <string>
using namespace std; 

void showStats(Enemy* enemy, Player* player)
{
    if (player->getPlayerHealth() < 0)
    {
        player->setPlayerHealth(0);
    }
    cout << player->getPlayerName() + " : Health = " << player->getPlayerHealth() << endl;

    getEnemyStats(enemy);
}


void levelSixInstructions(string name)
{
    clearscr();
    cout << "Great meditation " + name + "," << endl << endl;
    cout << "You are now in a transcendental meditative state!" << endl << endl; sleep(0s);
    cout << "Here you can feel your soul again." << endl; sleep(0s);
    cout << "Now you're finally again your own AlterEgo." << endl; sleep(0s);
    cout << "Remember, you have your all the corevalues to overcome your AlterEgo." << endl; sleep(2s);  
}


void startLevelSix(string name)
{
    levelSixInstructions(name);
    moveForward();

    clearscr();
    cout << "You've identified your AlterEgo, but you have to overcome your ego to feel your soul." << endl << endl; sleep(2s);

    while (true)
    {
        cout << "Press 'F' to feel and fight with emotion... ";
        string input;
        cin >> input;
        if (!(input == "F" || input == "f"))
        {
            cout << "Hey, it's time to show your strength!" << endl << endl;
        }
        else break;
    }
}

void attack(Enemy* enemy, Player* player)
{
    bool specialAbilityUsed = false;
    bool specialAbilityMurlocs = false;

    clearscr();
    std::cout << "Attack :" << std::endl;

    if (rand() % 5 == 0)
    {
        player->setMeleeDamage(player->getMeleeDamage() * 2);
        cout << "Special Ability Used : WillPower" << endl;
        specialAbilityUsed = true;
    }
    else
    {
        player->genRangedDamage();
    }

    checkAlive(enemy);

    if (rand() % 5 == 0)
    {
        enemy->setEnemyDamage(0);
        std::cout << "Special Ability Used : modesty" << std::endl;
    }

    if (rand() % 5 == 0)
    {
        player->setPlayerHealth(player->getPlayerHealth() + 20);
        std::cout << "Special Ability Used : SelfAwareness" << std::endl;
    }

    enemy->setEnemyHealth(enemy->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));

    if (rand() % 7 == 0)
    {
        cout << "Special Ability Used By Murlocs : oneness" << endl;
        enemy->setEnemyDamage(enemy->getEnemyDamage() * 2);
    }

    if (rand() % 7 == 0)
    {
        cout << "Special Ability Used By AlterEgo : Ego" << endl;
        enemy->setEnemyHealth(enemy->getEnemyHealth() + 10);
    }

    player->setPlayerHealth(player->getPlayerHealth() - (enemy->getEnemyDamage()));

    showStats(enemy, player);

    cout << std::endl << player->getPlayerName() + " : Damage Given = " << player->getMeleeDamage() + player->getRangedDamage() << endl;

    if (specialAbilityUsed)
    {
        player->setMeleeDamage(player->getMeleeDamage() / 2);
        specialAbilityUsed = false;
    }

    std::cout << enemy->getEnemyName() << " : Damage Given = " << enemy->getEnemyDamage() << endl;
    if (specialAbilityMurlocs)
    {
        enemy->setEnemyDamage(enemy->getEnemyDamage() / 2);
        specialAbilityMurlocs = false;
    }
}

void block(Enemy* enemy, Player* player)
{
    clearscr();
    cout << "Defend :" << endl;
    showStats(enemy, player);

    cout << endl << player->getPlayerName() + " : Damage Given = 0" << endl;
    cout << enemy->getEnemyName() << " : Damage Given = 0" << endl;
}


void levelSixBattle(Player* player)
{
    Enemy* enemy = new Enemy("AlterEgo", bossEnemy, 100, 10);

    string input;
    
    clearscr();
    cout << "Get totally aware!" << endl;
    showStats(enemy, player);

    while (true)
    {
        if (enemy->getEnemyHealth() <= 0) 
            break;
        if (player->getPlayerHealth() <= 0)
        {
            cout << std::endl << endl << "OOPs! You haven't moved on from the emotion!" << endl;
            cout << "Meditate Again!" << endl;
            exit(1);
        }
        sleep(1s);

        switch (rand() % 3)
        {
        case 0:
            attack(enemy, player);
            break;
        case 1:
            block(enemy, player);
            break;
        default:
            attack(enemy, player);
            break;
        }
    }

    cout << endl << endl << "!! You've moved on from the emotion !!" << endl;
    cout << "Press Enter To Continue meditating... ";
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clearscr();
    cout << "Welcome back " + player->getPlayerName() + "," << endl << endl;
    cout << "You have overcome your own AlterEgo and regained your Soul." << endl; sleep(0s);
    cout << "Now nothing can take your soul away from you." << endl; sleep(2s);

    printAscii("end.txt");
    cout << "Press Enter To Stop meditating... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    delete enemy;
}