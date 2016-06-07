#include <iostream>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()

void setupBoard();

int main()
{
    //setup board
    const unsigned int length = 4;//length of board
    const unsigned int maxTurns = 12;
    char board[length];
    srand(time(0));
    for(unsigned int i=0; i<length; ++i){
        unsigned int randomNumber = (rand()%6)+1;
        
        switch(randomNumber){
            case 1:
                board[i] = 'R';//red
                break;
            case 2:
                board[i] = 'G';//green
                break;
            case 3:
                board[i] = 'B';//blue
                break;
            case 4:
                board[i] = 'Y';//yellow
                break;
            case 5:
                board[i] = 'P';//purple
                break;
            case 6:
                board[i] = 'O';//orange
                break;
        }
    }
    /*std::cout << "correct board: ";
    for(unsigned int i=0; i<length; ++i){
        std::cout << colors[i] << " ";
    }
    std::cout << std::endl;*/
    
    //start game
    std::cout << "Welcome to Mastermind!" << "\n";
    std::cout << "There are 6 colors: R, G, B, Y, P, O and the board consists of 4 colors" << "\n";
    std::cout << "X=color at right position, Z=color at wrong positon" << std::endl;
    
    char userGuess[length];
    unsigned int turncounter= 1;
    while(true){
        
        //read userGuess
        std::cout << "Your guess for turn number " << turncounter << ":" << std::endl;
        for(unsigned int i=0; i<length; ++i){
            std::cout << "Type in color " << i << ": ";
            std::cin >> userGuess[i];
        }
        
        //print userGuess
        std::cout << "Your guess is: ";
        for(unsigned int i=0; i<length; ++i){
            std::cout << userGuess[i] << " ";
        }
        std::cout << std::endl;
        
        //check if color is at right postion = X
        for(unsigned int i=0; i<length; ++i){
            if(userGuess[i] == board[i])
                std::cout << "X" << " ";
        }
        //check if color is at wrong position = Z
        if(userGuess[0] == board[1] || userGuess[0] == board[2] || userGuess[0] == board[3])
            std::cout << "Z" << " ";
        if(userGuess[1] == board[0] || userGuess[1] == board[2] || userGuess[1] == board[3])
            std::cout << "Z" << " ";
        if(userGuess[2] == board[0] || userGuess[2] == board[1] || userGuess[2] == board[3])
            std::cout << "Z" << " ";
        if(userGuess[3] == board[0] || userGuess[3] == board[1] || userGuess[3] == board[2])
            std::cout << "Z" << " ";
        std::cout << std::endl;
        
        //check if every color is at the right position --> user wins
        if(userGuess[0] == board[0] && userGuess[1] == board[1] && userGuess[2] == board[2] && userGuess[3] == board[3]){
            std::cout << "You win in turn: " << turncounter << std::endl;
            break;
        }
        
        //check if user exceeded number of maximum steps
        if(turncounter == maxTurns){
            std::cout << "Maximum steps reached --> you lose!" << std::endl;
            break;
        }
        
        ++turncounter;
    }
    return 0;
}

