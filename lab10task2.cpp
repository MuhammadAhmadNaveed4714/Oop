#include <iostream>
#include <string>
using namespace std;

class Location {
private:
    int x, y;

public:
    
    Location(int x = 0, int y = 0) : x(x), y(y) {}

  
    void setX(int val) {
        x = val;
    }

    void setY(int val) {
        y = val;
    }

    
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    
    void moveLeft() {
        x--;
    }

    void moveRight() {
        x++;
    }

    void moveUp() {
        y--;
    }

    void moveDown() {
        y++;
    }

    
    void displayLocation() const {
        cout << "Location: (" << x << ", " << y << ")" << endl;
    }
};

class Player {
private:
    string playerName;
    Location position;

public:
   
    Player() : playerName("Unknown"), position(Location(0, 0)) {}

    
    Player(string name, int x, int y) : playerName(name), position(Location(x, y)) {}

    
    void setPlayerName(string name) {
        playerName = name;
    }

    
    string getPlayerName() const {
        return playerName;
    }

 
    void movePlayerLeft() {
        position.moveLeft();
    }

    void movePlayerRight() {
        position.moveRight();
    }

    void movePlayerUp() {
        position.moveUp();
    }

    void movePlayerDown() {
        position.moveDown();
    }

    
    void displayPlayerInfo() const {
        cout << "Player: " << playerName << endl;
        position.displayLocation();
    }
};

int main() {
    Player player1;
    string name;
    int x, y, choice;

   
    cout << "Enter player name: ";
    getline(cin, name);
    cout << "Enter initial X coordinate: ";
    cin >> x;
    cout << "Enter initial Y coordinate: ";
    cin >> y;

    
    player1 = Player(name, x, y);

   
    do {
        cout << "\nMenu: \n";
        cout << "1. Display Player Info\n";
        cout << "2. Move Player Left\n";
        cout << "3. Move Player Right\n";
        cout << "4. Move Player Up\n";
        cout << "5. Move Player Down\n";
        cout << "6. Set Player Name\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            player1.displayPlayerInfo();
            break;
        case 2:
            player1.movePlayerLeft();
            break;
        case 3:
            player1.movePlayerRight();
            break;
        case 4:
            player1.movePlayerUp();
            break;
        case 5:
            player1.movePlayerDown();
            break;
        case 6:
            cout << "Enter new player name: ";
            cin.ignore();  
            getline(cin, name);
            player1.setPlayerName(name);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
