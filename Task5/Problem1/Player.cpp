#include "Player.h"
#include <iostream>

Player::Attributes::Attributes(int _strength, int _agility, int _intelligence) :
    strength{ _strength }, agility{ _agility }, intelligence{ _intelligence } {}

int Player::numberOfPlayers = 0;

Player::Player(std::string nickname, CharacterClasses characterClass) :
    m_nickname{ nickname }, m_characterClass{ characterClass } 
{
    ++numberOfPlayers;
}

Player::~Player()
{
    --numberOfPlayers;
    std::cout << "Player was deleted\n";
}

bool operator > (const Player& player1, const Player& player2)
{
    if (player1.m_attributes.strength > player2.m_attributes.strength)
    {
        return true;
    }
    return false;
}

void Player::chooseNickname()
{
    std::cout << "So, what's your name?\n";
    std::cin >> m_nickname;
}

void Player::chooseClass()
{
    std::cout << "\nOk, " << m_nickname << ", let's see what you are capable of.\n";
    std::cout << "(Choose your character class)\n" << "w - warrior\n" << "m - mage\n" << "r - rogue\n";
    char input;
    std::cin >> input;
    switch (input)
    {
    case 'w':
        m_characterClass = CharacterClasses::WARRIOR;
        m_attributes.strength += 10;
        std::cout << "Your strength increased by 10\n\n";
        break;
    case 'm':
        m_characterClass = CharacterClasses::MAGE;
        m_attributes.intelligence += 10;
        std::cout << "Your intelligence increased by 10\n\n";
        break;
    case 'r':
        m_characterClass = CharacterClasses::ROGUE;
        m_attributes.agility += 10;
        std::cout << "Your agility increased by 10\n\n";
        break;
    default:
        std::cout << "\nSomething went wrong. You will not have a class. =(\n";
        m_characterClass = CharacterClasses::DEFAULTCLASS;
    }
}

void Player::PrintInformation() const
{
    std::cout << "Your nickname: " << m_nickname << '\n';

    switch (m_characterClass)
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
        "Strength = " << m_attributes.strength << '\n' <<
        "Agility = " << m_attributes.agility << '\n' <<
        "Intelligence = " << m_attributes.intelligence << "\n\n";
}