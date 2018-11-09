// FILE: card_demo.cpp
//
//Go Fish Program
//EE 312
/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Aditya Khanna and Kedar Raman, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Aditya Khanna and Kedar Raman
 * email address: adityakhanna22@yahoo.com
 * UTEID: ak34642
 * Section 5 digit ID: 16225
 */

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
bool completeTurn(Deck &d, Player &primary, Player &secondary);
void showInitialState(Deck &d, Player &p1, Player &p2);
void bookCardsAtStart(Player &p1, Player &p2);
void endGame(Player &p1, Player &p2);

ofstream myFile;                                                    //Writes to gold_fish.txt

int main()
{
    myFile.open("gofish_results.txt");

    const int NUM_CARDS = 7;                                        //Players start with 7 cards in their hand
    const int PLAYER_1 = 0;                                         //0 represents Player 1
    const int PLAYER_2 = 1;                                         //1 represents Player 2

    Player p1("Kedar");
    Player p2("Aditya");

    int whoseTurn;                                                  //Keeps track of whose turn it is

    Deck d;                                                         //Creates a deck of cards
    d.shuffle();

    dealHand(d, p1, NUM_CARDS);
    dealHand(d, p2, NUM_CARDS);

    whoseTurn = PLAYER_1;                                           //Player 1 goes first

    cout << "START GAME" << endl;

    showInitialState(d, p1, p2);
    bookCardsAtStart(p1, p2);                                       //Books pairs in players' hands at the beginning of the game

    while ((d.size() != 0) || (p1.getHandSize() != 0) || (p2.getHandSize() != 0))
    {
        if (whoseTurn == PLAYER_1)
        {
            if (!(completeTurn(d, p1, p2)))
            {
                whoseTurn = PLAYER_2;
            }
        }
        else if (whoseTurn == PLAYER_2)
        {
            if (!(completeTurn(d, p2, p1)))
            {
                whoseTurn = PLAYER_1;
            }
        }
    }

    endGame(p1, p2);                                                //Checks Win Conditions

    myFile.close();
    cout << "END GAME" << endl;
    return EXIT_SUCCESS;
}

//Deals Starting Hand to a Player
//Inputs: Deck Object, Player Object, and number of Cards to Deal (int)
//Outputs/Results: Fills Player's Hand Vector with Card Objects from the Deck
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
    {
        Card temp = d.dealCard();
        if (temp.getRank() != -1)
        {
            p.addCard(temp);
        }
        else
        {
            myFile << "ERROR - INSUFFICIENT AMOUNT OF CARDS IN THE DECK; PLEASE REDUCE NUMBER OF CARDS PER PLAYER TO <= 26" << endl;
            return;
        }
    }
}

//Completes a Player's Turn
//Inputs: Deck Object an Player Object
//Outputs/Results: Fills Player's Hand Vector with Card Objects from the Deck
bool completeTurn(Deck &d, Player &primary, Player &secondary)
{
    bool successfulTurn = false;

    myFile << "*******************" << primary.getName() << "'s Turn" << "*******************" << endl;
    myFile << primary.getName() <<"'s " << primary.showHand() << endl;                                //Show primary player's hand
    myFile << primary.getName() << "'s " << primary.showBooks() << endl;                              //Show primary player's book
    myFile << primary.getName() <<"'s Number of Books:" << primary.getBookSize() << endl;             //Show primary player's number of books
    myFile << secondary.getName() <<"'s " << secondary.showHand() << endl;                            //Show secondary player's hand
    myFile << secondary.getName() << "'s " << secondary.showBooks() << endl;                          //Show secondary player's books
    myFile << secondary.getName() <<"'s Number of Books:" << secondary.getBookSize() << endl;         //Show secondary player's number of books
    myFile << "-------------------------------------------------" << endl;


    //HAND SIZE 0
    Card chosenCard;
    if (primary.getHandSize() != 0)
    {
        chosenCard = primary.chooseCardFromHand();                                      //Primary player chooses card
        myFile << primary.getName() << " - Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
    }
    Card temp;
    if ((primary.getHandSize() != 0) && (secondary.rankInHand(chosenCard, temp)))       //If guess is correct
    {
        myFile << secondary.getName() << " - Yes! I have a " << chosenCard.rankString(chosenCard.getRank()) << "." << endl;
        myFile << primary.getName() << " books a " << chosenCard.rankString(chosenCard.getRank()) << " pair." << endl;
        primary.bookCards(chosenCard, temp);                                            //Books cards
        primary.removeCardFromHand(chosenCard);                                         //Removes Card from primary player's hand
        secondary.removeCardFromHand(temp);                                             //Removes Card from secondary player's hand
        successfulTurn = true;
    }
    else                                                                                //If guess is not correct
    {
        if (primary.getHandSize() != 0)
        {
            myFile << secondary.getName() << " - Go Fish!" << endl;
        }
        else
        {
            myFile << primary.getName() << "'s Hand is Empty, but the Deck is not Empty. Draw a Card!" << endl;
        }
        temp = d.dealCard();
        if (temp.getRank() != -1)
        {
            myFile << primary.getName() << " draws " << temp.toString() << "." << endl;
            Card foundPairFromDraw;
            if (primary.rankInHand(temp, foundPairFromDraw))                                        //Card drawn has a pair and is booked
            {
                primary.bookCards(temp,foundPairFromDraw);
                primary.removeCardFromHand(foundPairFromDraw);
                myFile << primary.getName() << " books a " << foundPairFromDraw.rankString(foundPairFromDraw.getRank()) << " pair." << endl;
            }
            else
            {
                primary.addCard(temp);
            }
        }
        else
        {
            myFile << "Deck is empty." << endl;
        }
    }

    myFile << endl;
    return successfulTurn;
}

//Checks for Books in Player's hand
//Inputs: Player Objects
//Outputs/Results: Checks for Books in Players' Hand Vectors and places them in the respectove Book Vectors
void bookCardsAtStart(Player &p1, Player &p2)
{
    Card temp1;
    Card temp2;
    while (p1.checkHandForBook(temp1, temp2))                       //Books all pairs for Player 1
    {
        p1.bookCards(temp1, temp2);
        p1.removeCardFromHand(temp1);
        p1.removeCardFromHand(temp2);
    }
    while (p2.checkHandForBook(temp1, temp2))                       //Books all pairs for Player 2
    {
        p2.bookCards(temp1, temp2);
        p2.removeCardFromHand(temp1);
        p2.removeCardFromHand(temp2);
    }
}

//Shows Initial State of Game
//Inputs: Deck Objects and Player Objects
//Outputs/Results: Shows Hand Vctors and Book Vector so
void showInitialState(Deck &d, Player &p1, Player &p2)
{
    myFile << "*******************INITIAL STATE*******************" << endl;
    myFile << p1.getName() <<"'s " << p1.showHand() << endl;                                  //Show primary player's hand
    myFile << p1.getName() << "'s " << p1.showBooks() << endl;                                //Show primary player's book
    myFile << p1.getName() <<"'s Number of Books:" << p1.getBookSize() << endl;               //Show primary player's number of books
    myFile << p2.getName() <<"'s " << p2.showHand() << endl;                                  //Show secondary player's hand
    myFile << p2.getName() << "'s " << p2.showBooks() << endl;                                //Show seondary player's books
    myFile << p2.getName() <<"'s Number of Books:" << p2.getBookSize() << endl << endl;       //Show secondary player's number of books
}

//Checks Who Won the Game
//Inputs: Player Objects
//Outputs/Results: Checks Book Vector of each Player Object and Announces a Winner
void endGame(Player &p1, Player &p2)
{
    myFile << p1.getName() << " has a Book Size of " << p1.getBookSize() << endl;
    myFile << p1.showBooks() << endl;
    myFile << p2.getName() << " has a Book Size of " << p2.getBookSize() << endl;
    myFile << p2.showBooks() << endl << endl;
    myFile << "*************************************************************" << endl;

    if (p1.getBookSize() > p2.getBookSize())
    {
        myFile << p1.getName() << " Wins the Game!" << endl;
    }
    else if (p1.getBookSize() < p2.getBookSize())
    {
        myFile << p2.getName() << " Wins the Game!" << endl;
    }
    else
    {
        myFile << "The Game is a Tie!" << endl;
    }

    myFile << "*************************************************************" << endl;
}
