//
//  main.cpp
//  TripleLocked
//
//  Created by Chris Mercer on 25/05/2020.
//  Copyright © 2020 Chris Mercer. All rights reserved.
//

#include <iostream>

void PrintIntroduction()
{
    std::cout << "#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n";
    std::cout << "You are an assassin trying to gain access to the castle's inner chamber.\n";
    std::cout << "Each chamber has an infernal mechanism that can only be unlocked wih 3 numbers.\n";
    std::cout << "If you talk to each infernal mechanism it will give you clues.\n\n";
    std::cout << "(if it seems contrived, don't overthink it...)\n\n";
    std::cout << "#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n\n";
}

bool PlayGame(int difficulty)
{
    int CodeA = rand() % (difficulty + difficulty) + 1;
    int CodeB = rand() % (difficulty + difficulty) + 1;
    int CodeC = rand() % (difficulty + difficulty) + 1;
    
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << "You enter chamber " << difficulty << "... the infernal device cackles the following clues:\n\n";
    std::cout << "- There are three numbers in the code." << std::endl;
    std::cout << "- These numbers add up to: " << CodeSum << std::endl;
    std::cout << "- When multiplied they come to: " << CodeProduct << std::endl;

    int PlayerGuessA, PlayerGuessB, PlayerGuessC;
    std::cout << "\nWhat is your guess? (example: 1 2 3): ";
    std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;
    
    int GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;
    
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << std::endl<< "You guess correctly, well done!\n\n";
        return true;
    }
    else
    {
        std::cout << std::endl << "The infernal machine laughs as it shoot a magic ball of death at your face. You die.\n\n";
        return false;
    }
}

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    PrintIntroduction();
    
    int Level = 1;
    int MaxLevel = 5;
    bool CompletedLevel = true;
    
    while(CompletedLevel && Level <= MaxLevel)
    {
        CompletedLevel = PlayGame(Level);
        std::cin.clear();
        std::cin.ignore();
        
        if(CompletedLevel)
        {
            Level++;
        }
    }
    
    if(Level >= MaxLevel)
    {
        std::cout << "\n\nUpon reaching the inner chamber, you find your target sleeping peacefully... *slice*\n\n";
    }
    else
    {
        std::cout << "\n\nYour body is found by a cleaner who rolls their eyes, and adds you to the pile on the roses outside.\n\n";
    }
    
    return 0;
}
