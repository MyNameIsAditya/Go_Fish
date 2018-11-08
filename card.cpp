//File Name: card.cpp
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
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13

#include "card.h"

//Default Constructor
//Inputs: None
//Outputs/Results: Creates a default Card (Ace of Spades)
Card::Card()
{
    myRank = 1;
    mySuit = spades;
}

//Overloaded Constructor
//Inputs: Rank (Integer) and Suit
//Outputs/Results: Creates a Card with inputted Rank and Suit
Card::Card(int rank, Suit s)
{
    this->myRank = rank;
    this->mySuit = s;
}

//Returns string description of Card Object
//Inputs: None
//Outputs/Results: Returns String of Card Rank and Suit (e.g. 7h)
string Card::toString() const
{
    return rankString(this->myRank) + suitString(this->mySuit);
}

//Checks if two Card Objects share the same Suit
//Inputs: Card Object
//Outputs/Results: Returns true if card objects have the same suit
bool Card::sameSuitAs(const Card& c) const
{
    return (this->mySuit == c.mySuit);
}

//Returns Rank of Card Object
//Inputs: None
//Outputs/Results: Returns Rank (int) of Card Object
int  Card::getRank() const
{
    return this->myRank;
}

//Converts Suit to string
//Inputs: Suit type
//Outputs/Results: Returns string of Suit type (e.g. "s" for spades)
string Card::suitString(Suit s) const
{
    switch (s)
    {
        case spades:
            return "s";
        case hearts:
            return "h";
        case clubs:
            return "c";
        case diamonds:
            return "d";
        default:
            return "(ERROR)";
    }
}

//Converts Rank to string
//Inputs: Rank (int)
//Outputs/Results: Returns string of Rank (e.g. "A" for 1)
string Card::rankString(int r) const
{
    switch (r)
    {
        case 1:
            return "A";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default:
            return "ERROR";
    }
}

//Overloads the == operator to check if the Card Objects are the same (same Rank and Suit)
bool Card::operator == (const Card& rhs) const
{
    return ((this->myRank == rhs.myRank) && (this->mySuit == rhs.mySuit));
}

//Overloads the != operator to check if the Card Objects are the different (different Rank and/or Suit)
bool Card::operator != (const Card& rhs) const
{
    return ((this->myRank != rhs.myRank) || (this->mySuit != rhs.mySuit));
}

//Destructor
Card::~Card()
{
}

//Overloads the << operator to output Card Objects
ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString();
    return out;
}