#include "GameManager.h"
#include "clear.h"
using namespace std; 

void showStats(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4, Enemy* enemy5)
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
    getEnemyStats(enemy5);
}


void levelFiveInstructions(string name)
{
    clearscr();
    cout << "Great meditation " + name + "," << endl << endl;
    cout << "You are now in a spiritual meditative state!" << endl << endl; sleep(0s);
    cout << "Here you can achieve the wisdom for your further journey." << endl; sleep(0s);
    cout << "But wait, to get that corevalue, you have to defeat the evil emotion pessimism who is guarding that corevalue." << endl << endl << endl; sleep(0s);
}


void startLevelFive(string name)
{
    levelFiveInstructions(name);
    moveForward();

    clearscr();
    cout << "You've identified the corevalue wisdom, but you have to overcome the evil emotion pessimism to get the corevalue." << endl << endl; sleep(2s);

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


void attack(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4, Enemy* enemy5)
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
    checkAlive(enemy5);

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

    switch (rand() % 9)
    {
    case 0:
        player->setPlayerHealth(player->getPlayerHealth() + 20);
        cout << "Special Ability Used : SelfAwareness" << endl;
        break;
    }

    switch (rand() % 5)
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

    case 4:
        if ((enemy5->getEnemyHealth() <= 0)) {}
        else
        {
            enemy5->setEnemyHealth(enemy5->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
            break;
        }

    default:
        enemy1->setEnemyHealth(enemy1->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
        break;
    }

    player->setPlayerHealth(player->getPlayerHealth() - (enemy1->getEnemyDamage() + enemy2->getEnemyDamage() + enemy3->getEnemyDamage() + enemy4->getEnemyDamage() + enemy5->getEnemyDamage()));

    showStats(player, enemy1, enemy2, enemy3, enemy4, enemy5);

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
    cout << enemy5->getEnemyName() << " : Damage Given = " << enemy5->getEnemyDamage() << endl;
}

void block(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, Enemy* enemy4, Enemy* enemy5)
{
    clearscr();
    cout << "Defend :" << endl;
    showStats(player, enemy1, enemy2, enemy3, enemy4, enemy5);

    cout << endl << player->getPlayerName() + " : Damage Given = 0" << endl;
    cout << enemy1->getEnemyName() << " : Damage Given = 0" << endl;
    cout << enemy2->getEnemyName() << " : Damage Given = 0" << endl;
    cout << enemy3->getEnemyName() << " : Damage Given = 0" << endl;
    cout << enemy4->getEnemyName() << " : Damage Given = 0" << endl;
    cout << enemy5->getEnemyName() << " : Damage Given = 0" << endl;
}


void levelFiveBattle(Player* player)
{
    Enemy* enemy1 = new Enemy("fear", normalEnemy, 30, 5);
    Enemy* enemy2 = new Enemy("disgust", normalEnemy, 30, 5);
    Enemy* enemy3 = new Enemy("sadness", normalEnemy, 30, 5);
    Enemy* enemy4 = new Enemy("anxiety", normalEnemy, 30, 5);
    Enemy* enemy5 = new Enemy("pessimism", normalEnemy, 30, 5);

    string input;
    
    clearscr();
    cout << "Get aware!" << endl;
    showStats(player, enemy1, enemy2, enemy3, enemy4, enemy5);

    while (true)
    {
        if (enemy1->getEnemyHealth() <= 0 && enemy2->getEnemyHealth() <= 0 && enemy3->getEnemyHealth() <= 0 && enemy4->getEnemyHealth() <= 0 && enemy5->getEnemyHealth() <= 0) break;
        if (player->getPlayerHealth() <= 0)
        {
            cout << endl << endl << "OOPs! You haven't moved on from the emotion!" << endl;
            cout << "Meditate Again!" << endl;
            exit(1);
        }
        sleep(1s);

        switch (rand() % 3)
        {
        case 0:
            attack(player, enemy1, enemy2, enemy3, enemy4, enemy5);
            break;
        case 1:
            block(player, enemy1, enemy2, enemy3, enemy4, enemy5);
            break;
        default:
            attack(player, enemy1, enemy2, enemy3, enemy4, enemy5);
            break;
        }
    }

    cout << std::endl << endl << "!! You've moved on from the emotion !!" << endl;
    cout << "Press Enter To Continue meditating... ";
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clearscr();
    cout << "Well done " + player->getPlayerName() + "," << endl << endl;
    cout << "You have regained your wisdom." << endl; sleep(0s);
    cout << "You've now a more oneness." << endl; sleep(0s);
    cout << "Now you only need to overcome your own ego to feel your soul again." << endl; sleep(2s);
    moveForward();

    delete enemy1;
    delete enemy2;
    delete enemy3;
    delete enemy4;
    delete enemy5;
}