#include "GameManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Level5.h"
#include "Level6.h"
#include <thread>
#include <string>
#include <fstream>
#include "clear.h" 
#include "ASCIIart.h"
using namespace std; 

void sleep(const chrono::duration<int>& time)
{
    this_thread::sleep_for(time);
}

void getEnemyStats(Enemy* enemy)
{
    if (enemy->getEnemyHealth() < 0)
    {
        enemy->setEnemyHealth(0);
    }
    cout << enemy->getEnemyName() << " : Health = " << enemy->getEnemyHealth() << endl;
}

void checkAlive(Enemy* enemy)
{
    if (!(enemy->getEnemyHealth() <= 0)) 
    {
        enemy->genEnemyDamage(); 
    }
    else
    {
        enemy->setEnemyDamage(0);
    }
}

void moveForward()
{
    while (true)
    {
        cout << "Press 'M' to meditate...  ";
        string input;
        cin >> input;
        if (!(input == "M" || input == "m"))
        {
            cout << "OOPs! You seem distracted" << endl << endl;
        }
        else break;
    }
}

void welcomeMessage()
{
    clearscr();
    cout << "!! Welcome To Mindful Adventure Game !!" << endl << endl;
    cout << "Press Enter To continue meditating... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string playerDetails()
{
    char name[50];
    clearscr();
    cout << "Enter your name: ";
    cin >> name;
    return (string)name;
}


void instructions(string name)
{
    using namespace literals::chrono_literals;

    clearscr();

    printAscii("player.txt");
    cout << "Recognise yourself " + name + "," << endl << endl;
    cout << "Welcome to your simulation!" << endl; sleep(0s);
    cout << "Your soul is captured by your AlterEgo." << endl; sleep(0s);
    cout << "To feel your soul again, you have to overcome 5 negative states." << endl; sleep(0s);
    cout << "You will need some core values to get back your Soul." << endl << endl; sleep(0s);
    cout << "Have a great mindful journey." << endl << endl << endl; sleep(2s);

    cout << "Press Enter to begin your mindful Journey... ";
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void gameStart()
{
    welcomeMessage(); 

    string name = playerDetails();
    instructions(name);

    Player* player = new Player(name, "soul", 100, 10);

    startLevelOne(name);
    levelOneBattle(player);

    startLevelTwo(name);
    levelTwoBattle(player);

    startLevelThree(name);
    levelThreeBattle(player);

    startLevelFour(name);
    levelFourBattle(player);

    startLevelFive(name);
    levelFiveBattle(player);

    startLevelSix(name);
    levelSixBattle(player);

    delete player;
}
