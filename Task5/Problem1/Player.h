#pragma once
#include <iostream>

class Player
{
private:
    enum class CharacterClasses
    {
        WARRIOR,
        MAGE,
        ROGUE,
        DEFAULTCLASS
    };
    struct Attributes
    {
        Attributes(int _strength = 10, int _agility = 10, int _intelligence = 10);

        int strength;
        int agility;
        int intelligence;
    };
    std::string m_nickname;
    CharacterClasses m_characterClass;
    Attributes m_attributes;
    static int numberOfPlayers;

public:
    Player(std::string nickname = "Unknown",
        CharacterClasses characterClass = CharacterClasses::DEFAULTCLASS);
    ~Player();

    friend bool operator > (const Player&, const Player&);

    std::string getNickname() const { return m_nickname; };

    CharacterClasses getCharacterClass() const { return m_characterClass; };

    Attributes getAttributes() const { return m_attributes; };
    void setAttributes(Attributes& attributes) { m_attributes = attributes; };

    static int getNumberOfPlayers() { return numberOfPlayers; };

    void chooseNickname();
    void chooseClass();
    void printInformation() const;
};