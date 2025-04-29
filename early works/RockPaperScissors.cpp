#include <iostream>
#include <random>
#include <string>

// Function prototypes
std::string promptPlayerChoice();
std::string determineWinner(const std::string &computerChoice, const std::string &playerChoice);
void updateScores(const std::string &winner, int &computerScore, int &playerScore);
void declareWinner(int computerScore, int playerScore);

int main()
{
    int computerScore = 0;
    int playerScore = 0;
    std::string playerChoice;
    std::string computerChoice;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3); // Random number between 1 and 3

    while (true)
    {
        // Get computer's choice
        int randomChoice = dis(gen);
        if (randomChoice == 1)
            computerChoice = "rock";
        else if (randomChoice == 2)
            computerChoice = "paper";
        else
            computerChoice = "scissors";

        // Prompt player for input
        playerChoice = promptPlayerChoice();

        // Check if the player wants to quit
        if (playerChoice == "quit")
        {
            break;
        }

        // Display choices and determine winner
        std::cout << "Computer chose " << computerChoice << std::endl;
        std::string winner = determineWinner(computerChoice, playerChoice);

        // Update scores based on the winner
        updateScores(winner, computerScore, playerScore);

        // Display current scores
        std::cout << "Current Score -> Computer: " << computerScore << " | Player: " << playerScore << std::endl;
    }

    // Declare the winner of the tournament
    declareWinner(computerScore, playerScore);
    return 0;
}

// Function to prompt the player to select an option
std::string promptPlayerChoice()
{
    std::string choice;
    while (true)
    {
        std::cout << "Enter rock, paper, scissors, or quit to end the game: ";
        std::cin >> choice;
        if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit")
        {
            return choice;
        }
        else
        {
            std::cout << "Invalid input. Please choose rock, paper, scissors, or quit." << std::endl;
        }
    }
}

// Function to determine the winner of the round
std::string determineWinner(const std::string &computerChoice, const std::string &playerChoice)
{
    if (computerChoice == playerChoice)
    {
        return "draw";
    }
    else if ((computerChoice == "rock" && playerChoice == "scissors") ||
             (computerChoice == "scissors" && playerChoice == "paper") ||
             (computerChoice == "paper" && playerChoice == "rock"))
    {
        return "computer";
    }
    else
    {
        return "player";
    }
}

// Function to update scores based on the winner
void updateScores(const std::string &winner, int &computerScore, int &playerScore)
{
    if (winner == "computer")
    {
        computerScore++;
    }
    else if (winner == "player")
    {
        playerScore++;
    }
}

// Function to declare the winner of the tournament
void declareWinner(int computerScore, int playerScore)
{
    std::cout << "\nFinal Score -> Computer: " << computerScore << " | Player: " << playerScore << std::endl;
    if (computerScore > playerScore)
    {
        std::cout << "Computer wins the tournament!" << std::endl;
    }
    else if (playerScore > computerScore)
    {
        std::cout << "Player wins the tournament!" << std::endl;
    }
    else
    {
        std::cout << "The tournament is a draw!" << std::endl;
    }
}
