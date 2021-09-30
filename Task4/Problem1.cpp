#include <iostream>

enum class CharacterClasses
{
    WARRIOR,
    MAGE,
    ROGUE,
    DEFAULTCLASS
};

struct PlayerAttributes
{
    PlayerAttributes(int _strength = 10, int _agility = 10, int _intelligence = 10) :
        strength{ _strength }, agility{ _agility }, intelligence{ _intelligence } {}

    int strength;
    int agility;
    int intelligence;
};

struct Player
{
    Player(std::string _nickname = "Unknown",
        CharacterClasses _characterClass = CharacterClasses::DEFAULTCLASS) :
        nickname{ _nickname }, characterClass{ _characterClass } {}

    ~Player()
    {
        std::cout << "Player was deleted\n";
    }

    std::string nickname;
    CharacterClasses characterClass;
    PlayerAttributes Attributes;

    bool operator > (const Player& player2)
    {
        if (Attributes.strength > player2.Attributes.strength)
        {
            return true;
        }
        return false;
    }

    void chooseNickname()
    {
        std::cout << "So, what's your name?\n";
        std::cin >> nickname;
    }

    void chooseClass()
    {
        std::cout << "\nOk, " << nickname << ", let's see what you are capable of.\n";
        std::cout << "(Choose your character class)\n" << "w - warrior\n" << "m - mage\n" << "r - rogue\n";
        char input;
        std::cin >> input;
        switch (input)
        {
        case 'w':
            characterClass = CharacterClasses::WARRIOR;
            Attributes.strength += 10;
            std::cout << "Your strength increased by 10\n\n";
            break;
        case 'm':
            characterClass = CharacterClasses::MAGE;
            Attributes.intelligence += 10;
            std::cout << "Your intelligence increased by 10\n\n";
            break;
        case 'r':
            characterClass = CharacterClasses::ROGUE;
            Attributes.agility += 10;
            std::cout << "Your agility increased by 10\n\n";
            break;
        default:
            std::cout << "\nSomething went wrong. You will not have a class. =(\n";
            characterClass = CharacterClasses::DEFAULTCLASS;
        }
        std::cout << '\n';
    }

    void getInformation()
    {
        std::cout << "Your nickname: " << nickname << '\n';

        switch (characterClass)
        {
        case CharacterClasses::WARRIOR:
            std::cout << "Your class: " << "warrior" << '\n';
            break;
        case CharacterClasses::MAGE:
            std::cout << "Your class: " << "mage" << '\n';
            break;
        case CharacterClasses::ROGUE:
            std::cout << "Your class: " << "rogue" << '\n';
            break;
        default:
            std::cout << "You have no talents =(\n";
            break;
        }

        std::cout << "Your attributes:\n" <<
            "Strength = " << Attributes.strength << '\n' <<
            "Agility = " << Attributes.agility << '\n' <<
            "Intelligence = " << Attributes.intelligence << "\n\n";
    }
};


int main()
{
    using namespace std;
    Player player;

    cout << "\nHey, you. You are finally awake.\n\n";
    player.chooseNickname();
    player.chooseClass();
    player.getInformation();

    Player defaultPlayer{};
    defaultPlayer.getInformation();

    if (player > defaultPlayer)
    {
        cout << player.nickname << " wins " << defaultPlayer.nickname << "\n\n";
    }

    return EXIT_SUCCESS;
}