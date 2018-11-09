Hello! This is a guide on how to run the program! - Aditya Khanna and Kedar Raman (ak34642 and kvr336)

1) Unzip the folder and extract all of the files
2) Compile the code with make -f makefile
3) Run the executable with ./go_fish
4) The program will run a Go Fish program. The start and end of the game will be indicated on the console.
5) A "gofish_results.txt" file will be created. The game log and results will be documented there.

Game Rule Clarifications:
1) Players pick a card to guess (that is already in their hand).
If successful (the other player has the card), the player continues to guess until it is not successful.
2) A player's turn ends when they are unsuccessful and draw a card from the deck.
3) If a player does not have any cards in their hand, they must draw a card and end their turn.
4) Cards are booked at the beginning of the game. Additionally, cards are booked at the end of
the turn (when there is a successful guess or when the card drawn matches a card in the hand).