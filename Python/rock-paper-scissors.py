# This program is a basic implementation of the rock-paper-scissors game
# User competes against the computer

import random

def start():
    user = input("What do you choose? 'r' for rock, 'p' for paper, 's' for scissors: ").lower()

    # emulating a do while loop
    while True:
        # computer chooses randomly among r, p and s
        computer = random.choice(['r', 'p', 's'])

        # check for valid choices
        if ((user == 'e') or (user == 'r') or (user == 'p') or (user == 's')):
            # end the loop if the user enters 'e'
            if (user == 'e'):
                break

            else:
                # printing the values choosen by the user
                if (user == 'r'):
                    print('Your choice is: rock(r)\n')
                if(user == 'p'):
                    print('Your choice is: paper(p)\n')
                if(user == 's'):
                    print('Your choice is: scissors(s)\n')

                # printing the values choosen by the computer
                if(computer == 'r'):
                    print('Computer\'s choice is: rock(r)\n')
                if(computer == 'p'):
                    print('Computer\'s choice is: paper(p)\n')
                if(computer == 's'):
                    print('Computer\'s choice is: scissors(s)\n')

                # condition for a tie
                if (user == computer):
                    print("It\'s a TIE!!!\n")

                # user as the winner
                elif win(user, computer):
                    print('Congralutions...You won!!!\n')

                # computer as the winner
                else:
                    print('Oops...You lost!!!\n')

            user = input("Choose 'e' to end the game or else choose 'r' for rock, 'p' for paper, 's' for scissors: ").lower()

        else:
            # ask for a valid choice
            print("Please choose a valid choice: 'r' for rock, 'p' for paper, 's' for scissors")
            user = input("What do you choose? ").lower()
            continue


# funtion to determine the winnner
def win(player, opponent):
    if (player == 'r' and opponent == 's') or (player == 's' and opponent == 'p') or (player == 'p' and opponent == 'r'):
        return True  # returns true if player wins

start()
