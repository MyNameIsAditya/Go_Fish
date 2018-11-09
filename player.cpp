// FILE:  player.cpp
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
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#include "player.h"

//Default Constructor
//Inputs: None
//Outputs/Results: Creates a default Player with name "Roger"
Player::Player()
{
    myName = "Roger";
}

//Overloaded Constructor
//Inputs: string name
//Outputs/Results: Creates a Card with inputted Rank and Suit
Player::Player(string name)
{
    this->myName = name;
}

//Gets Player Name
//Inputs: None
//Outputs/Results: Returns Player Object Name (string)
string Player::getName() const
{
    return this->myName;
}

//Adds Card to Hand
//Inputs: Card Object
//Outputs/Results: Adds Card Object to the Hand Vector
void Player::addCard(Card c)
{
    this->myHand.push_back(c);
}

//Adds Cards to Book
//Inputs: Card Objects
//Outputs/Results: Adds Card Objects to the Book Vector
void Player::bookCards(Card c1, Card c2)
{
    this->myBook.push_back(c1);
    this->myBook.push_back(c2);
}


//This function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.
//Inputs: Card Objects
//Outputs/Results: Returns True if Cards Share Rank Values and Populates Card variables with Card pair
bool Player::checkHandForBook(Card &c1, Card &c2)
{
    vector<Card>::iterator iterator1;
    vector<Card>::iterator iterator2;
    for (iterator1 = this->myHand.begin(); iterator1 != this->myHand.end(); iterator1++)
    {
        for (iterator2 = (iterator1 + 1); iterator2 != this->myHand.end(); iterator2++)
        {
            if (iterator1->getRank() == iterator2->getRank())
            {
                c1 = *iterator1;
                c2 = *iterator2;
                return true;
            }
        }
    }
    return false;
}

//Checks if there is a card with the same Rank as the inputted Card Object
//Inputs: Card Object
//Outputs/Results: Returns True if Cards Share Rank Values and Populates Card variable with found card
bool Player::rankInHand(Card c, Card &temp)
{
    vector<Card>::const_iterator iter;
    for (iter = this->myHand.begin(); iter != this->myHand.end(); iter++)
    {
        if ((iter->getRank()) == (c.getRank()))
        {
            temp = (*iter);
            return true;
        }
    }
    return false;
}

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card Player::chooseCardFromHand() const
    {
        srand((unsigned) time(0));
        int randomIndex = (rand() & this->getHandSize());
        return this->myHand[randomIndex];
    }
    //Does the player have the card c in her hand?

//Checks if Player has Card Object in their Hand
//Inputs: Card Object
//Outputs/Results: Returns True if Card Object matches Card in Hand Vector
bool Player::cardInHand(Card c) const
{
    vector<Card>::const_iterator iter;
    for (iter = this->myHand.begin(); iter != this->myHand.end(); iter++)
    {
        if ((*iter) == c)
        {
            return true;
        }
    }
    return false;
}

//Removes Card from Player's Hand
//Inputs: Card Object
//Outputs/Results: Returns Card Removed from Hand Vector of Player
Card Player::removeCardFromHand(Card c)
{
    vector<Card>::iterator iter;
    Card removedCard;
    for (iter = this->myHand.begin(); iter != this->myHand.end(); iter++)
    {
        if ((*iter) == c)
        {
            removedCard = (*iter);
            this->myHand.erase(iter);
        }
    }
    return removedCard;
}

//Shows Player's Hand
//Inputs: None
//Outputs/Results: Returns Card Objects (string) in Player's Hand Vector
string Player::showHand() const
{
    string s = "Hand: ";
    vector<Card>::const_iterator iter;
    for (iter = this->myHand.begin(); iter != this->myHand.end(); iter++)
    {
        s += ((*iter).toString() + ", ");
    }
    return s;
}

//Shows Player's Books
//Inputs: None
//Outputs/Results: Returns Card Objects (string) in Player's Books Vector
string Player::showBooks() const
{
    string s = "Books: ";
    vector<Card>::const_iterator iter;
    for (iter = this->myBook.begin(); iter != this->myBook.end(); iter++)
    {
        s += ((*iter).toString() + ", ");
    }
    return s;
}

//This function checks the size of a Player's Hand
//Inputs: None
//Outputs/Results: Returns the size (int) of the Hand Vector of a Player
int Player::getHandSize() const
{
    vector<Card>::const_iterator iter;
    int size = 0;
    for (iter = this->myHand.begin(); iter != this->myHand.end(); iter++)
    {
        size++;
    }
    return size;
}

//This function checks the size of a Player's Book
//Inputs: None
//Outputs/Results: Returns the size (int) of the Book Vector of a Player
int Player::getBookSize() const
{
    vector<Card>::const_iterator iter;
    int size = 0;
    for (iter = this->myBook.begin(); iter != this->myBook.end(); iter++)
    {
        size++;
    }
    return size;
}

//This function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards that make the pair.
//Inputs: Card Objects
//Outputs/Results: Returns True if Cards Share Rank Values and Populates Card variables with Card pair
bool Player::checkHandForPair(Card &c1, Card &c2)
{
    vector<Card>::iterator iterator1 ;
    vector<Card>::iterator iterator2;
    for (iterator1 = this->myHand.begin(); iterator1 != this->myHand.end(); iterator1++)
    {
        for (iterator2 = (iterator1 + 1); iterator2 != this->myHand.end(); iterator2++)
        {
            if (iterator1->getRank() == iterator2->getRank())
            {
                c1 = *iterator1;
                c2 = *iterator2;
                return true;
            }
        }
    }
    return false;
}

//Checks if there is a card with the same Rank as the inputted Card Object
//Inputs: Card Object
//Outputs/Results: Returns True if Cards Share Rank Values
bool Player::sameRankInHand(Card c) const
{
    vector<Card>::const_iterator iter;
    for (iter = this->myHand.begin(); iter != this->myHand.end(); iter++)
    {
        if ((iter->getRank()) == (c.getRank()))
        {
            return true;
        }
    }
    return false;
}

//Destructor
Player::~Player()
{
    vector<Card>::const_iterator iter;
    for (iter = this->myHand.begin(); iter != this->myHand.end(); iter++)
    {
        delete &(*iter);
    }
    this->myHand.clear();
    delete &(this->myHand);
    for (iter = this->myBook.begin(); iter != this->myBook.end(); iter++)
    {
        delete &(*iter);
    }
    this->myBook.clear();
    delete &(this->myBook);
}
