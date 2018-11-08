// FILE: deck.h
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

#ifndef _DECK_H
#define _DECK_H

#include <ctime>
#include <cstdlib>
#include "card.h"

class Deck
{
    static const int SIZE = 52;

public:
    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the cards in the current deck
    Card dealCard();   // get a card, after 52 are dealt, fail
    int  size() const; // # cards left in the deck

    ~Deck();

private:
    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif