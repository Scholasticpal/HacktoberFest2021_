#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum Action {YES = 0, NO, X_WIN, O_WIN};

const string red("\033[0;31m");
const string cyan("\033[0;36m");
const string reset("\033[0m");

const unsigned int EMPTY_SUM    =   216; // ascii value of an "empty" slot
const unsigned int X_SUM        =   272 + 434 + 275; // ascii value of an slot filled by X (also red + reset)
const unsigned int O_SUM        =   263 + 439 + 275; // ascii value of an slot filled by O (also cyan + reset)

const string X_PLAYER           =   red + "X" + reset;
const string O_PLAYER           =   cyan + "O" + reset;

string board[][5] = {"   ", " 0 ", " 1 ", " 2 ", "(y)",
                     "0  ", "[ ]", "[ ]", "[ ]", "   ",
                     "1  ", "[ ]", "[ ]", "[ ]", "   ",
                     "2  ", "[ ]", "[ ]", "[ ]", "   ",
                     "(x)", "   ", "   ", "   ", "   "};

bool running = true;

// clears the screen and displays the current board
void print_board() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// returns the ascii value of the given string
int get_ascii_value(string &str) {
    int ascii_count = 0;
    for (int i = 0; i < str.length(); i++) {
        ascii_count += int(str.at(i));
    }
    return ascii_count;
}

// checks the sum of the collindant slots to see if an slot is surrounded by the same values (aka: wins)
Action check_sum(int sum, string player) {
    if (sum == X_SUM * 2) {
        if (player == X_PLAYER)
            return X_WIN;
        else if (player == O_PLAYER)
            return YES;
    } else if (sum == O_SUM * 2) {
        if (player == O_PLAYER)
            return O_WIN;
        else if (player == X_PLAYER)
            return YES;
    } else {
        return YES;
    }
}

// checks the collindant slots in order to see if a player has won, is a valid movement or is not a valid movement
Action get_action_from_movement(unsigned short *x, unsigned short *y, string player) {
    if (*x > 3 || *y > 3 || *x < 0 || *y < 0)
        return NO;

    if (get_ascii_value(board[*x][*y]) != EMPTY_SUM)
        return NO;

    Action curr_state = NO;

    if (*x == 1) {
        curr_state = check_sum(get_ascii_value(board[2][*y]) + get_ascii_value(board[3][*y]), player);
        if (curr_state == YES && *y == 1) {
            curr_state = check_sum(get_ascii_value(board[2][2]) + get_ascii_value(board[3][3]), player);
        } else if (curr_state == YES && *y == 3) {
            curr_state = check_sum(get_ascii_value(board[2][2]) + get_ascii_value(board[3][1]), player);
        }
    } else if (*x == 2) {
        curr_state = check_sum(get_ascii_value(board[1][*y]) + get_ascii_value(board[3][*y]), player);
        if (curr_state == YES && *y == 2) {
            curr_state = check_sum(get_ascii_value(board[1][1]) + get_ascii_value(board[3][3]), player);
            if (curr_state == YES) {
                curr_state = check_sum(get_ascii_value(board[3][1]) + get_ascii_value(board[1][3]), player);
            }
        }
    } else if (*x == 3) {
        curr_state = check_sum(get_ascii_value(board[1][*y]) + get_ascii_value(board[2][*y]), player);
        if (curr_state == YES && *y == 3) {
            curr_state = check_sum(get_ascii_value(board[1][1]) + get_ascii_value(board[2][2]), player);
            if (curr_state == YES && *y == 1) {
                curr_state = check_sum(get_ascii_value(board[2][2]) + get_ascii_value(board[1][3]), player);
            } else if (curr_state == YES && *y == 3) {
                curr_state = check_sum(get_ascii_value(board[2][2]) + get_ascii_value(board[1][1]), player);
            }
        }
    }

    if (curr_state != YES)
        return curr_state;

    if (*y == 1) {
        curr_state = check_sum(get_ascii_value(board[*x][2]) + get_ascii_value(board[*x][3]), player);
    } else if (*y == 2) {
        curr_state = check_sum(get_ascii_value(board[*x][1]) + get_ascii_value(board[*x][3]), player);
    } else if (*y == 3) {
        curr_state = check_sum(get_ascii_value(board[*x][1]) + get_ascii_value(board[*x][2]), player);
    }

    if (curr_state != YES)
        return curr_state;

    return YES;
}

// fills the given slot with the given player value
void fill_slot(unsigned short *x, unsigned short *y, string player) {
    board[*x][*y] = "[" + player + "]";
}

// checks if the board is full
bool is_board_full() {
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (get_ascii_value(board[i][j]) == EMPTY_SUM)
                return false;
        }
    }
    return true;
}

// exits the game when the user press enter
void exit_game() {
    cin.ignore();
    cout << "Press enter to exit..." << endl; 
    cin.get();
    exit(EXIT_SUCCESS); 
}

// handles the current turn actions
void handle_turn(string player) {
    unsigned short x, y;
    bool error;
    Action curr_state;

    do {
        error = false;
        cout << "Player [" << player << "] enter (x) position (0..2): ";
        cin >> x;
        cout << "Player [" << player << "] enter (y) position (0..2): ";
        cin >> y;

        x = x + 1;
        y = y + 1;

        curr_state = get_action_from_movement(&x, &y, player);

        if (curr_state == NO) {
            error = true;
            cout << "ERROR: Enter a valid action." << endl;
            continue;
        }

        fill_slot(&x, &y, player);
        print_board();

        if (curr_state == X_WIN || curr_state == O_WIN) {
            cout << "Player [" << player << "] wins!" << endl;
            exit_game();
        }

    } while (error);

    if (is_board_full()) {
        cout << "The game has ended, the board is full." << endl;
        exit_game();
    }
}

int main() {
    print_board();
    while (running) {
        handle_turn(X_PLAYER);
        handle_turn(O_PLAYER);
    }

    return EXIT_SUCCESS;
}