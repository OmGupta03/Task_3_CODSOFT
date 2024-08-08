#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1, n2;

void functionOne() {
    cout << "    |    |    \n";
    cout << "  " << space[0][0] << " | " << space[0][1] << "  | " << space[0][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << space[1][0] << " | " << space[1][1] << "  | " << space[1][2] << " \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << "  " << space[2][0] << " | " << space[2][1] << "  | " << space[2][2] << " \n";
    cout << "    |    |    \n";
}

void functionTwo() {
    int digit;
    
    if (token == 'x') {
        cout << n1 << " your turn: ";
    } else {
        cout << n2 << " your turn: ";
    }
    cin >> digit;

    switch (digit) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default: 
            cout << "Invalid!!!" << endl;
            functionTwo();
            return;
    }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "There is no empty space!" << endl;
        functionTwo();
    }
    functionOne();
}

bool functionThree() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);
    cout << n1 << " is player1 so he/she will play first\n";
    cout << n2 << " is player2 so he/she will play second\n";

    while (!functionThree()) {
        functionOne();
        functionTwo();
    }
    if (!tie) {
        if (token == '0') {
            cout << n1 << " Wins!!" << endl;
        } else {
            cout << n2 << " Wins!!" << endl;
        }
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
