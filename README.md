# One-Card-WAR

This project implements a simple card game called One Card WAR for two players using C++. The game is played with a standard deck of 52 cards. Each player is dealt one card, and the player with the higher card wins the round. If the cards are of equal rank, it's a tie.

Description

- Objective: Implement a card game called One Card WAR for two players.

- Rules: Each player is dealt one card from a standard deck of 52 cards. The player with the higher-ranked card wins the round. If the cards are of equal rank, it's a tie.

- Input: Player names and number of games to play.

- Output: Winner of each game and final statistics.

Files Included

- war.cpp: Source code for the One Card WAR game.

How to Play

- Run the program.

- Enter the names of the two players.
  
- Specify the number of games to play.
  
- The unshuffled deck will be displayed.
  
- The deck will be shuffled.
  
- The shuffled deck will be displayed.
  
- Games will be played, and the winner of each game will be announced.
  
- After all games are played, statistics will be printed.

Compilation

$ g++ war.cpp -o war

Execution

$ ./war
  
Exception Handling

- If the number of requested games is greater than the number of cards in the deck, an exception will be raised and handled in the main function.

Enjoy playing the game of One Card WAR!


