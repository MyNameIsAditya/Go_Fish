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
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main()
{
    int numCards = 7;

    Player p1("Kedar");
    Player p2("Aditya");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<"'s : " << p1.showHand() << endl;
    cout << p2.getName() <<"'s : " << p2.showHand() << endl;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
    {
        Card temp = d.dealCard();
        if(temp.getRank()!=-1)
        {
            p.addCard(temp);
        }
        else
        {
            cout << "ERROR- INSUFFICIENT AMOUNT OF CARDS IN DECK, PLEASE REDUCE NUMBER OF CARDS PER PLAYER TO <= 26";
            return;
        }

    }
}
