# HorseRace
#include <iostream>
#include <random>
set TRACK_LENGTH constant

advance function
  performs a "coin flip" to decide whether the horse advances or not
  use random for coin flip
  if 'heads', move forward, if 'tails' stay in same spot
    this will likely be 0 for heads and 1 for tails, but is subject to change
        if heads, increase horse position
  temp to store horses location
  will not return a value

printLane function
  use for loop for printing lane
    i as sentry, end when i = 16
    if i = horses position, print number in lane
    else print dot
    print updated lane each time

bool isWinner function
  if 15th value of array is not a dot, return true
  else return false

main
  make an array called horses that contains 5 zeros (representing their position)
  for loop (i sentry)
    end when i gets to 5
    call advance function with i and the array
    call printLane
    
  while keepGoing = true
