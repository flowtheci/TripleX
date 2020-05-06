#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{  
    if(Difficulty == 1)
    {
    cout << "  __  __  _    _  _____   _____   ______  _____      __  __ __     __ _____  _______  ______  _____ __     __\n";
    cout << " |  \\/  || |  | ||  __ \\ |  __ \\ |  ____||  __ \\    |  \\/  |\\ \\   / // ____||__   __||  ____||  __ \\ \\   / /\n";
    cout << " | \\  / || |  | || |__) || |  | || |__   | |__) |   | \\  / | \\ \\_/ /| (___     | |   | |__   | |__) |\\ \\_/ / \n";
    cout << " | |\\/| || |  | ||  _  / | |  | ||  __|  |  _  /    | |\\/| |  \\   /  \\___ \\    | |   |  __|  |  _  /  \\   /  \n";
    cout << " | |  | || |__| || | \\ \\ | |__| || |____ | | \\ \\    | |  | |   | |   ____) |   | |   | |____ | | \\ \\   | |   \n";
    cout << " |_|  |_| \\____/ |_|  \\_\\|_____/ |______||_|  \\_\\   |_|  |_|   |_|  |_____/    |_|   |______||_|  \\_\\  |_|   \n\n";
    cout << "###########################################################################################################################\n";
    cout << "You are a detective investigating a murder scene. The police department suspects this to be the case of a recent serial killer.\n";
    cout << "There is a high-tech locked box next to the body, which after hours of attempts, the officers were not able to open.\n";
    cout << "The lockbox has a combination lock on it with 3 numbers. You must solve the code to find out the contents of the box.\n";
    cout << "###########################################################################################################################\n\n";
    }
    else if (Difficulty >= 2)
    {
    cout << "  __  __  _    _  _____   _____   ______  _____      __  __ __     __ _____  _______  ______  _____ __     __\n";
    cout << " |  \\/  || |  | ||  __ \\ |  __ \\ |  ____||  __ \\    |  \\/  |\\ \\   / // ____||__   __||  ____||  __ \\ \\   / /\n";
    cout << " | \\  / || |  | || |__) || |  | || |__   | |__) |   | \\  / | \\ \\_/ /| (___     | |   | |__   | |__) |\\ \\_/ / \n";
    cout << " | |\\/| || |  | ||  _  / | |  | ||  __|  |  _  /    | |\\/| |  \\   /  \\___ \\    | |   |  __|  |  _  /  \\   /  \n";
    cout << " | |  | || |__| || | \\ \\ | |__| || |____ | | \\ \\    | |  | |   | |   ____) |   | |   | |____ | | \\ \\   | |   \n";
    cout << " |_|  |_| \\____/ |_|  \\_\\|_____/ |______||_|  \\_\\   |_|  |_|   |_|  |_____/    |_|   |______||_|  \\_\\  |_|   \n\n";
    cout << "###########################################################################################################################\n";
    cout << "You arrive at location number "<< Difficulty << ". At the location, you again find a dead body buried underground.\n";
    cout << "Once again, there is a high-tech locked box next to the body, which looks similar to the last one.\n";
    cout << "The lockbox has a combination lock on it with 3 numbers. You must solve the code to find out the contents of the box.\n";
    cout << "###########################################################################################################################\n\n"; 
    }

}


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Picks a random number depending on your difficulty level.
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // First prints text, then the sum & product, and ends the line.
    cout << "There is a note on the box, with the following information: \n";
    cout << "+ There are 3 numbers in the code.\n";
    cout << "+ The codes add up to " << CodeSum << ".\n";
    cout << "+ The codes multiply up to " << CodeProduct << ".\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA;

    if(GuessA >= 100 && GuessA <= 999)
    {
        int Digit1 = GuessA % 10;
        int Digit2 = GuessA / 10 % 10;
        int Digit3 = GuessA / 100 % 10;

        GuessA = Digit1;
        GuessB = Digit2;
        GuessC = Digit3;
    }
    else
    {
        cin >> GuessB >> GuessC;
    }
    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Checking player guess
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\nYou got the correct code! You find a note in the box.\nThe note has co-ordinates to a location closeby.\n";
        cout << "You and the officers decide to check out the location.\n\n";
        cout << "Level " << Difficulty << " Complete.\n";
        system("pause");
        cout.flush();
        system("CLS");
        return true;
    }
    else
    {
        cout << "Wrong code. The box explodes and you die instantly.\n";
        return false;
    }

}

int main()
{
    bool Restart = false; // Runs everything in the main once unless Restart is true.
    do
    {
        srand(time(NULL)); // generates new rand seed based on time
        int LevelDifficulty = 1;
        string RetryLevel = "N";
        const int MaxDifficulty = 5;
        while (LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
        {
            bool bLevelComplete = PlayGame(LevelDifficulty);
            cin.clear();
            cin.ignore();

            if (bLevelComplete)
            {
                ++LevelDifficulty;
            }
            else //Checks if player wishes to retry level on fail
            {
                cout << "Retry from the beginning? (Y/N)\n";
                cin >> RetryLevel;
                if(RetryLevel == "Y" || RetryLevel == "Yes" || RetryLevel == "yes" || RetryLevel == "y")
                {
                    cout.flush();
                    system("CLS");
                    LevelDifficulty = 1;
                }
                else
                {
                    return 0;
                }
            }       
        }   

        // Runs after loop is complete
        cout << "  __  __  _    _  _____   _____   ______  _____      __  __ __     __ _____  _______  ______  _____ __     __\n";
        cout << " |  \\/  || |  | ||  __ \\ |  __ \\ |  ____||  __ \\    |  \\/  |\\ \\   / // ____||__   __||  ____||  __ \\ \\   / /\n";
        cout << " | \\  / || |  | || |__) || |  | || |__   | |__) |   | \\  / | \\ \\_/ /| (___     | |   | |__   | |__) |\\ \\_/ / \n";
        cout << " | |\\/| || |  | ||  _  / | |  | ||  __|  |  _  /    | |\\/| |  \\   /  \\___ \\    | |   |  __|  |  _  /  \\   /  \n";
        cout << " | |  | || |__| || | \\ \\ | |__| || |____ | | \\ \\    | |  | |   | |   ____) |   | |   | |____ | | \\ \\   | |   \n";
        cout << " |_|  |_| \\____/ |_|  \\_\\|_____/ |______||_|  \\_\\   |_|  |_|   |_|  |_____/    |_|   |______||_|  \\_\\  |_|   \n\n";
        cout << "###########################################################################################################################\n";
        cout << "At the last location, you find a house, with a door that has been broken into.\n";
        cout << "You and the officers rush in to find a masked man with a bloody knife in his hands.\n";
        cout << "He says: \"Nice job detective. You found them faster than I thought you would.\"\n";
        cout << "###########################################################################################################################\n\n";
        cout << " __   __  _______  __   __      _     _  ___  __    _  __ \n";
        cout << "|  | |  ||       ||  | |  |    | | _ | ||   ||  |  | ||  |\n";
        cout << "|  |_|  ||   _   ||  | |  |    | || || ||   ||   |_| ||  |\n";
        cout << "|       ||  | |  ||  |_|  |    |       ||   ||       ||  |\n";
        cout << "|_     _||  |_|  ||       |    |       ||   ||  _    ||__|\n";
        cout << "  |   |  |       ||       |    |   _   ||   || | |   | __ \n";
        cout << "  |___|  |_______||_______|    |__| |__||___||_|  |__||__|\n";


        // Prompts for a game restart, otherwise quits.
        string RestartGame = "N";
        cout << "Well done on completing the game!\n";
        cout << "Restart from the beginning? (Y/N)\n";
        cin >> RestartGame;
        if(RestartGame == "Y" || RestartGame == "Yes" || RestartGame == "yes" || RestartGame == "y")
        {
            cout.flush();
            system("CLS");
            LevelDifficulty = 1;
            Restart = true;
        }
        else
        {
            Restart = false;
        }
    
    }

    while (Restart);
    
    return 0;

} 