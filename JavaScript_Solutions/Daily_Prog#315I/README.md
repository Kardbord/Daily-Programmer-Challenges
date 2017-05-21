Daily Programmer Challenge #315 \[Intermediate\]

https://www.reddit.com/r/dailyprogrammer/comments/6bumxo/20170518_challenge_315_intermediate_game_of_life/

Description:

This challenge is based on a game (the mathematical variety - not quite as fun!) called Conway's Game of Life. This is
called a cellular automaton. This means it is based on a 'playing field' of sorts, made up of lots of little cells or
spaces. For Conway's game of life, the grid is square - but other shapes like hexagonal ones could potentially exist
too. Each cell can have a value - in this case, on or off - and for each 'iteration' or loop of the game, the value of
each cell will change depending on the other cells around it. This might sound confusing at first, but looks easier
when you break it down a bit.
- A cell's "neighbours" are the 8 cells around it.
- If a cell is 'off' but exactly 3 of its neighbours are on, that cell will also turn on - like reproduction.
- If a cell is 'on' but less than two of its neighbours are on, it will die out - like underpopulation.
- If a cell is 'on' but more than three of its neighbours are on, it will die out - like overcrowding.

Fairly simple, right? This might sound boring, but it can generate fairly complex patterns.
There are other examples of such patterns, like ones which grow indefinitely.
We are going to extend this by giving it some additional rules:
There are two parties on the grid, say red and blue.
When a cell only has neighbours that are of his own color, nothing changes and it will follow the rules as explained
before.
When a cell has neighbours that are not of his own 1 of two things can happen:
- The total amount of cells in his neighbourhood of his color (including himself) is greater then the amount of cells
not in his color in his neighbourhood 
    - apply normal rules, meaning that you have to count in the cells of other colors as alive cells
- If the amount of the other colors is greater then amount of that cell's own color then it just changes color.
Last if a cell is 'off' and has 3 neighbour cells that are alive it will be the color that is the most represented.
Your challenge is, given a width and height to create a grid and a number of turns to simulate this variant