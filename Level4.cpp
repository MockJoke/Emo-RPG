#include "GameManager.h"
#include "clear.h"
using namespace std; 

void showStats(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4)
{
    if (player->getPlayerHealth() < 0)
    {
        player->setPlayerHealth(0);
    }
    cout << player->getPlayerName() + " : Health = " << player->getPlayerHealth() << endl;

    getEnemyStats(enemy1);
    getEnemyStats(enemy2);
    getEnemyStats(enemy3);
    getEnemyStats(enemy4);
}


void levelFourInstructions(string name)
{
    clearscr();
    cout << "Great meditation " + name + "," << endl << endl;
    cout << "You are now in a gratitude meditative state!" << endl << endl; sleep(0s);
    cout << "Here you can achieve the peace for your further journey." << endl; sleep(0s);
    cout << "But wait, to get that corevalue, you have to defeat the evil emotion anxiety who is guarding that corevalue." << endl << endl << endl; sleep(0s);
}


void startLevelFour(string name)
{
    levelFourInstructions(name);
    moveForward();

    clearscr();
    cout << "You've identified the corevalue gratitude, but you have to overcome the evil emotion anxiety to get the corevalue." << endl << endl; sleep(2s);

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


void attack(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4)
{
    bool specialAbilityUsed = false;

    clearscr();
    cout << "Attack :" << endl;

    switch (rand() % 9)
    {
    case 0:
        player->setMeleeDamage(player->getMeleeDamage() * 2);
        cout << "Special Ability Used : WillPower" << endl;
        specialAbilityUsed = true;
        break;

    default:
        player->genRangedDamage();
        break;
    }

    checkAlive(enemy1);
    checkAlive(enemy2);
    checkAlive(enemy3);
    checkAlive(enemy4);

    switch (rand() % 9)
    {
    case 0:
        enemy1->setEnemyDamage(0);
        enemy2->setEnemyDamage(0);
        enemy3->setEnemyDamage(0);
        enemy4->setEnemyDamage(0);
        cout << "Special Ability Used : modesty" << endl;
        break;
    }

    switch (rand() % 4)
    {
    case 0:
        if ((enemy1->getEnemyHealth() <= 0)) {}
        else
        {
            enemy1->setEnemyHealth(enemy1->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
            break;
        }

    case 1:
        if ((enemy2->getEnemyHealth() <= 0)) {}
        else
        {
            enemy2->setEnemyHealth(enemy2->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
            break;
        }

    case 2:
        if ((enemy3->getEnemyHealth() <= 0)) {}
        else
        {
            enemy3->setEnemyHealth(enemy3->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
            break;
        }

    case 3:
        if ((enemy4->getEnemyHealth() <= 0)) {}
        else
        {
            enemy4->setEnemyHealth(enemy4->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
            break;
        }

    default:
        enemy1->setEnemyHealth(enemy1->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
        break;
    }

    player->setPlayerHealth(player->getPlayerHealth() - (enemy1->getEnemyDamage() + enemy2->getEnemyDamage() + enemy3->getEnemyDamage() + enemy4->getEnemyDamage()));

    showStats(player, enemy1, enemy2, enemy3, enemy4);

    cout << endl << player->getPlayerName() + " : Damage Given = " << player->getMeleeDamage() + player->getRangedDamage() << endl;

    if (specialAbilityUsed)
    {
        player->setMeleeDamage(player->getMeleeDamage() / 2);
        specialAbilityUsed = false;
    }

    cout << enemy1->getEnemyName() << " : Damage Given = " << enemy1->getEnemyDamage() << endl;
    cout << enemy2->getEnemyName() << " : Damage Given = " << enemy2->getEnemyDamage() << endl;
    cout << enemy3->getEnemyName() << " : Damage Given = " << enemy3->getEnemyDamage() << endl;
    cout << enemy4->getEnemyName() << " : Damage Given = " << enemy4->getEnemyDamage() << endl;
}

void block(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4)
{
    clearscr();
    cout << "Defend :" << endl;
    showStats(player, enemy1, enemy2, enemy3, enemy4);

    cout << std::endl << player->getPlayerName() + " : Damage Given = 0" << endl;
    cout << enemy1->getEnemyName() << " : Damage Given = 0" << endl;
    cout << enemy2->getEnemyName() << " : Damage Given = 0" << endl;
    cout << enemy3->getEnemyName() << " : Damage Given = 0" << endl;
    cout << enemy4->getEnemyName() << " : Damage Given = 0" << endl;
}


void levelFourBattle(Player* player)
{
    Enemy* enemy1 = new Enemy("fear", normalEnemy, 30, 5);
    Enemy* enemy2 = new Enemy("disgust", normalEnemy, 30, 5);
    Enemy* enemy3 = new Enemy("sadness", normalEnemy, 30, 5);
    Enemy* enemy4 = new Enemy("anxiety", normalEnemy, 30, 5);

    string input;
    
    clearscr();
    cout << "Get aware!" << endl;
    showStats(player, enemy1, enemy2, enemy3, enemy4);

    while (true)
    {
        if (enemy1->getEnemyHealth() <= 0 && enemy2->getEnemyHealth() <= 0 && enemy3->getEnemyHealth() <= 0 && enemy4->getEnemyHealth() <= 0) break;
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
            attack(player, enemy1, enemy2, enemy3, enemy4);
            break;
        case 1:
            block(player, enemy1, enemy2, enemy3, enemy4);
            break;
        default:
            attack(player, enemy1, enemy2, enemy3, enemy4);
            break;
        }
    }

    cout << endl << endl << "!! You've moved on from the emotion !!" << endl;
    cout << "Press Enter To Continue meditating... ";
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clearscr();
    cout << "Well done " + player->getPlayerName() + "," << endl << endl;
    cout << "You have regained your peace." << endl; sleep(0s);
    cout << "You've now a better SelfAwareness." << endl; sleep(0s);
    cout << "Two more corevalues needed to feel your soul again." << endl; sleep(2s);
    moveForward();

    delete enemy1;
    delete enemy2;
    delete enemy3;
    delete enemy4;
}