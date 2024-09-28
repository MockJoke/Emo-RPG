#include "GameManager.h"
#include "clear.h"
using namespace std; 

void showStats(Player* player, Enemy* enemy)
{
    if (player->getPlayerHealth() < 0)
    {
        player->setPlayerHealth(0);
    }
    cout << player->getPlayerName() + " : Health = " << player->getPlayerHealth() << endl;

    getEnemyStats(enemy);
}


void levelOneInstructions(string name)
{
    clearscr();
    cout << "Great meditation " + name + "," << endl << endl;
    cout << "You are now in a movement meditative state!" << endl << endl; sleep(0s);
    cout << "Now you can achieve your confidence back for your further journey." << endl; sleep(0s);
    cout << "Hold on, to get that corevalue, you have to defeat the evil emotion fear who is guarding that corevalue." << endl << endl << endl; sleep(0s);
}


void startLevelOne(string name)
{
    levelOneInstructions(name);
    moveForward();

    clearscr();
    cout << "You've identified the corevalue confidence, but you have to overcome the evil emotion fear to get the corevalue." <<endl << endl; sleep(2s);

    while (true)
    {
        cout << "Press 'F' to feel and fight with emotion... ";
        string input;
        cin >> input;
        if (!(input == "F" || input == "f"))
        {
            cout << "Hey, it's time to show your focused strength!" << endl << endl;
        }
        else break;
    }
}

void attack(Player* player, Enemy* enemy)
{
    clearscr();
    cout << "Attack :" << endl;
    player->genRangedDamage();
    enemy->genEnemyDamage();

    enemy->setEnemyHealth(enemy->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
    player->setPlayerHealth(player->getPlayerHealth() - enemy->getEnemyDamage());

    showStats(player, enemy);
    cout << player->getPlayerName() + " : Damage Given = " << player->getMeleeDamage() + player->getRangedDamage() << endl;
    cout << enemy->getEnemyName() << " : Damage Given = " << enemy->getEnemyDamage() << endl;
}

void block(Player* player, Enemy* enemy)
{
    clearscr();
    cout << "Defend :" << endl;
    showStats(player, enemy);
    cout << player->getPlayerName() + " : Damage Given = 0" << endl;
    cout << enemy->getEnemyName() << " : Damage Given = 0" << endl;
}


void levelOneBattle(Player* player)
{
    Enemy* enemy = new Enemy("fear", normalEnemy, 20, 5);
    string input;
    
    clearscr();
    cout << "Get aware!" << endl;
    showStats(player, enemy);

    while (true)
    {
        if (enemy->getEnemyHealth() <= 0) break; sleep(1s);

        switch (rand() % 3)
        {
        case 0:
            attack(player, enemy);
            break;
        case 1:
            block(player, enemy);
            break;
        default:
            attack(player, enemy);
            break;
        }
    }

    cout << endl << endl << "!! You've moved on from the emotion !!" << endl;
    cout << "Press Enter To Continue meditating... ";
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clearscr();
    cout << "Well done " + player->getPlayerName() + "," << endl << endl;
    cout << "You have regained your confidence." << endl; sleep(0s);
    cout << "Five more corevalues needed to feel your soul again." << endl; sleep(2s);
    moveForward();

    delete enemy;
}
