#include "Player.h"
#include <iostream>

int main()
{
    using namespace std;
    Player player;

    cout << "\nHey, you. You are finally awake.\n\n";
    player.chooseNickname();
    player.chooseClass();
    player.printInformation();
    cout << "Number of players: " << Player::getNumberOfPlayers() << "\n\n";

    Player defaultPlayer{};
    defaultPlayer.printInformation();
    cout << "Number of players: " << Player::getNumberOfPlayers() << "\n\n";

    if (player > defaultPlayer)
    {
        cout << player.getNickname() << " wins " << defaultPlayer.getNickname() << "\n\n";
    }

    return EXIT_SUCCESS;
}