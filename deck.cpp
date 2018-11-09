// FILE: deck.cpp
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
//
// This class represents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck will randomize whatever cards are in the deck
// Do not shuffle if you have less than 2 cards
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.

#include "Deck.h"

//Default Constructor
//Inputs: None
//Outputs/Results: Creates a default Deck (Sorted Deck from A - K)
Deck::Deck()
{
    myIndex = 0;
    int index = 0;
    for (int i = 1; i <= (SIZE / 4); i++)                           //Begins at 1 for Ace and ends on 13 for King
    {
        myCards[index] = Card(i, Card::spades);
        index++;
        myCards[index] = Card(i, Card::hearts);
        index++;
        myCards[index] = Card(i, Card::clubs);
        index++;
        myCards[index] = Card(i, Card::diamonds);
        index++;
    }
}

//Shuffles the Deck Object
//Inputs: None
//Outputs/Results: Randomizes the cards in the deck Object
void Deck::shuffle()
{
    srand((unsigned) time(0));
    for (int i = 0; i < SIZE; i++)
    {
        int firstRandomIndex = (rand() % SIZE);
        int secondRandomIndex = (rand() % SIZE);

        Card temp = myCards[firstRandomIndex];
        myCards[firstRandomIndex] = myCards[secondRandomIndex];
        myCards[secondRandomIndex] = temp;
    }
}

//Deals a Card from the deck Object
//Inputs: None
//Outputs/Results: Returns a Card Object; Fails After All 52 card Objects Are Dealt
Card Deck::dealCard()
{
    if (this->size() >= 0)
    {
        Card returned = myCards[myIndex];
        (this->myIndex)++;
        return returned;
    }
    else
    {
        return Card(-1, Card::spades);                              //Returns ERROR Card
    }
}

//Gets Number of Cards Remaining
//Inputs: None
//Outputs/Results: Returns number of Card Objects left in the Deck (int)
int Deck::size() const
{
    return (SIZE - this->myIndex);
}

string Deck::toString()
{
    string ret = "DECK: ";
    for(int i = myIndex; i < SIZE; i++)
    {
        ret += myCards[i].toString() + " , ";
    }
    return ret;
}

//Destructor
Deck::~Deck()
{
}



