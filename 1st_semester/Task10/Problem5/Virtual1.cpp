#include <iostream>
#include <random>

class Subject
{
protected:
    static constexpr int    _maxGrade{ 10 };
    static constexpr int    _minGrade{ 1 };
    static constexpr double _averageEaseOfCommunication{ 3 };

    double _easeOfCommunication;

    int _examGrade;

    int getExamGrade() const
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(_minGrade, _maxGrade);

        double estimatedGrade{ dist(gen) * 1.0 }; // generate int number between 1 and 10 inclusive
        estimatedGrade *= _easeOfCommunication / _averageEaseOfCommunication; // accounting character of examiner
        int finalGrade = static_cast<int>(estimatedGrade + 0.51); // rounding in favor of the student

        if (finalGrade > _maxGrade)
            return _maxGrade;

        return finalGrade;
    }

public:
    Subject(double easeOfCommunication) : _easeOfCommunication{ easeOfCommunication },
                                          _examGrade{ getExamGrade() } {}
    virtual ~Subject() = default;

    virtual int getGrade() const = 0;
    virtual int getGrade(int) const = 0;

    int recalculateGrade()
    {
        _examGrade = getExamGrade();
        return getGrade();
    }

    int recalculateGrade(int exam)
    {
        _examGrade = exam;
        return getGrade();
    }
};

class Maths : public Subject
{
private:
    static constexpr int _maxScores{ 100 };
    static constexpr int _stepScores{ 7 };

    int _BRS{ 0 };

public:
    Maths(int BRS = 0, double easeOfCommunication = _averageEaseOfCommunication) :
        Subject(easeOfCommunication), _BRS{ BRS } {}

    virtual ~Maths() = default;

    virtual int getGrade() const override
    {
        if (_examGrade <= _minGrade + 1)
        {
            return _examGrade;
        }

        int scores = _BRS + _examGrade * _stepScores;
        int finalGrade = _maxGrade - (_maxScores - scores - 1) / _stepScores;

        if (finalGrade <= _minGrade)
        {
            return _minGrade;
        }
        return finalGrade;
    }

    virtual int getGrade(int exam) const override
    {
        int scores = _BRS + exam * _stepScores;
        int finalGrade = _maxGrade + 1 - (_maxScores - scores) / _stepScores;

        if (finalGrade <= _minGrade)
        {
            return _minGrade;
        }
        return finalGrade;
    }
};

class Physics : public Subject
{
private:
    static constexpr int _maxScores{ 4 };
    static constexpr int _minScores{ -6 };

    int _BRS{ 0 };

public:
    Physics(int BRS = _minScores, double easeOfCommunication = _averageEaseOfCommunication) :
        Subject(easeOfCommunication), _BRS{ BRS } {}

    virtual ~Physics() = default;

    virtual int getGrade() const override
    {
        int grade = _BRS + _examGrade;

        if (grade > _maxGrade)
            return _maxGrade;

        if (grade < _minGrade)
            return _minGrade;

        return grade;
    }

    virtual int getGrade(int exam) const override
    {
        int grade = _BRS + exam;

        if (grade > _maxGrade)
            return _maxGrade;

        if (grade < _minGrade)
            return _minGrade;

        return grade;
    }
};

int main()
{
    // getGrade(int) if you already know your exam grade
    // getGrade()    if you don't

    Maths maths{ 30, 5.0 }; // ctor( brs, easeOfCommunication (on a scale of 1 to 5) )
    std::cout << maths.getGrade(6) << "\n";

    Maths maths1{ 15, 3 };
    std::cout << maths1.getGrade(2) << "\n";

    Physics phys{ 4, 2.5 };
    std::cout << phys.getGrade(5) << "\n";

    Physics phys1{ -6, 4 };
    std::cout << phys1.getGrade(9) << "\n";

    for (int i = 0; i < 40; ++i)
        std::cout << maths.recalculateGrade() << " "; // possible grades if exam grade is unknown
    std::cout << "\n";                                // (randomly generated)

    for (int i = 0; i < 40; ++i)
        std::cout << maths1.recalculateGrade() << " ";
    std::cout << "\n";

    for (int i = 0; i < 40; ++i)
        std::cout << phys.recalculateGrade() << " ";
    std::cout << "\n";

    for (int i = 0; i < 40; ++i)
        std::cout << phys1.recalculateGrade() << " ";
    std::cout << "\n";

    return EXIT_SUCCESS;
}