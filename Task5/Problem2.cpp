#include <iostream>

class Energy
{
private:
    double m_joule;
    double m_erg;
    double m_eV;
    static const double evToJoule;
    static const double evToErg;
    static const double ergToJoule;
public:
    double getJoule() const
    {
        return m_joule;
    }
    void setJoule()
    {
        std::cout << "Enter energy in J:\n";
        double input{ 0 };
        std::cin >> input;
        std::cout << "\n";

        m_joule = input;
        m_erg = m_joule / ergToJoule;
        m_eV = m_joule / evToJoule;
    }
    double getErg() const
    {
        return m_erg;
    }
    void setErg()
    {
        std::cout << "Enter energy in erg:\n";
        double input{ 0 };
        std::cin >> input;
        std::cout << "\n";

        m_erg = input;
        m_joule = m_erg * ergToJoule;
        m_eV = m_erg / evToErg;
    }
    double getEV() const
    {
        return m_eV;
    }
    void setEV()
    {
        std::cout << "Enter energy in eV:\n";
        double input{ 0 };
        std::cin >> input;
        std::cout << "\n";

        m_eV = input;
        m_joule = m_eV * evToJoule;
        m_erg = m_eV * evToErg;
    }
    void print()
    {
        std::cout << "Energy is equal:" << "\n";
        std::cout << m_joule << " J\n";
        std::cout << m_erg << " erg\n";
        std::cout << m_eV << " eV\n\n";
    }
};

const double Energy::evToJoule{ 1.602176634e-19 };
const double Energy::evToErg{ 1.602176634e-12 };
const double Energy::ergToJoule{ 1e-7 };

int main()
{
    Energy energy;

    energy.setJoule();
    energy.print();

    energy.setErg();
    energy.print();

    energy.setEV();
    energy.print();

    std::cout << energy.getEV() << " eV\n";

    return EXIT_SUCCESS;
}