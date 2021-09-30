#include <iostream>
#include <vector>
#include <string>

struct Lesson;
struct Student;

void printVector(std::vector<Student*>);
void printVector(std::vector<Lesson*>);

struct Student
{
    Student(std::string _name = "default_student", std::vector<Lesson*> _lessons = { nullptr }) :
        name{ _name }, lessons{ _lessons } {}

    std::string name;
    std::vector<Lesson*> lessons;

    void printLessonsList()
    {
        std::cout << "Lessons of " << name << ":" << std::endl;
        printVector(lessons);
    }
};

struct Lesson
{
    Lesson(std::string _name = "default_lesson", std::vector<Student*> _students = { nullptr }) :
        name{ _name }, students{ _students } {}

    std::string name;
    std::vector<Student*> students;

    void printStudentsList()
    {
        std::cout << "Students of " << name << ":" << std::endl;
        printVector(students);
    }
};

void printVector(std::vector<Student*> students)
{
    for (Student* studentPtr : students)
    {
        if (studentPtr != nullptr)
        {
            std::cout << studentPtr->name << ' ';
        }
        else
        {
            std::cout << "No students";
        }
    }
    std::cout << std::endl << std::endl;
}

void printVector(std::vector<Lesson*> lessons)
{
    for (Lesson* lessonPtr : lessons)
    {
        if (lessonPtr != nullptr)
        {
            std::cout << lessonPtr->name << ' ';
        }
        else
        {
            std::cout << "No lessons";
        }
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    using namespace std;

    int numberOfStudent;
    cout << "Enter number of students: " << endl;
    cin >> numberOfStudent;
    cout << endl;

    vector<Student> students(numberOfStudent);
    vector<Student*> studentsPtrs(numberOfStudent);

    cout << "Enter " << numberOfStudent << " students:" << endl;
    {
        string input = "";

        for (int i = 0; i < numberOfStudent; ++i)
        {
            cin >> input;
            students[i] = { input }; // student with entered name
            studentsPtrs[i] = &students[i]; // pointer to the student
        }
        cout << endl;
    }
    int k = 0;

    vector<vector<Lesson>> vectorOfLessons(numberOfStudent);
    vector<vector<Lesson*>> vectorOfLessonsPtrs(numberOfStudent);

    for (Student* ptr : studentsPtrs)
    {
        cout << "Enter number of lessons of " << ptr->name << " :" << endl;
        int numberOfLessons;
        cin >> numberOfLessons;
        cout << endl;

        string input = "";

        cout << "Enter lessons of " << ptr->name << " :" << endl;

        for (int i = 0; i < numberOfLessons; ++i)
        {
            cin >> input; // Name of lesson
            vectorOfLessons[k].push_back({ input }); // Add lesson with name input to vector of lessons of student № k
            vectorOfLessonsPtrs[k].push_back(&vectorOfLessons[k][i]); // Add ptr on added lesson to vector of ptrs on lessons of student № k
        }

        ptr->lessons = vectorOfLessonsPtrs[k]; // assign vector of ptrs to student.lessons
        cout << endl;
        ++k;
    }

    for (Student* ptr : studentsPtrs) // пробегаем по указателям на студентов
    {
        for (Lesson* lesson : ptr->lessons) // пробегаем по указателям на уроки студента
        {
            lesson->students.push_back(ptr); // добавляем к уроку указатель на студента
        }
    }

    for (Student* ptr : studentsPtrs) // print LessonsList of all students
    {
        ptr->printLessonsList();
    }

    return EXIT_SUCCESS;
}