#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Person
{
protected:
    string lastName;
    string firstName;
    string patronymic;
    char gender;
    string birthDate;

public:
    Person(string ln, string fn, string pn, char g, string bd)
        : lastName(ln), firstName(fn), patronymic(pn), gender(g), birthDate(bd) {}

    virtual ~Person() {}

    virtual void display() const
    {
        cout << "Name: " << lastName << " " << firstName << " " << patronymic << endl;
        cout << "Gender: " << gender << endl;
        cout << "Birth Date: " << birthDate << endl;
    }

    string getLastName() const
    {
        return lastName;
    }
};

class Teacher : public Person
{
private:
    string position;
    vector<string> subjects;

public:
    Teacher(string ln, string fn, string pn, char g, string bd, string pos)
        : Person(ln, fn, pn, g, bd), position(pos) {}

    void addSubject(const string &subject)
    {
        subjects.push_back(subject);
    }

    void display() const override
    {
        Person::display();
        cout << "Position: " << position << endl;
        cout << "Subjects: ";
        for (const auto &subject : subjects)
        {
            cout << subject << " ";
        }
        cout << endl;
    }
};

class Student : public Person
{
private:
    string groupNumber;
    map<string, int> grades;

public:
    Student(string ln, string fn, string pn, char g, string bd, string group)
        : Person(ln, fn, pn, g, bd), groupNumber(group) {}

    void addGrade(const string &subject, int grade)
    {
        grades[subject] = grade;
    }

    void display() const override
    {
        Person::display();
        cout << "Group Number: " << groupNumber << endl;
        cout << "Grades: ";
        for (const auto &entry : grades)
        {
            cout << entry.first << ": " << entry.second << " ";
        }
        cout << endl;
    }
};

vector<Teacher> readTeachersFromFile(const string &filename)
{
    vector<Teacher> teachers;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return teachers;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string ln, fn, pn, bd, pos, subjectsStr;
        char g;
        getline(iss, ln, ',');
        getline(iss, fn, ',');
        getline(iss, pn, ',');
        iss >> g;
        iss.ignore();
        getline(iss, bd, ',');
        getline(iss, pos, ',');
        getline(iss, subjectsStr);

        Teacher teacher(ln, fn, pn, g, bd, pos);
        stringstream subjectsStream(subjectsStr);
        string subject;
        while (getline(subjectsStream, subject, ';'))
        {
            teacher.addSubject(subject);
        }
        teachers.push_back(teacher);
    }
    file.close();
    return teachers;
}

vector<Student> readStudentsFromFile(const string &filename)
{
    vector<Student> students;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return students;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string ln, fn, pn, bd, group, gradesStr;
        char g;
        getline(iss, ln, ',');
        getline(iss, fn, ',');
        getline(iss, pn, ',');
        iss >> g;
        iss.ignore();
        getline(iss, bd, ',');
        getline(iss, group, ',');
        getline(iss, gradesStr);

        Student student(ln, fn, pn, g, bd, group);
        stringstream gradesStream(gradesStr);
        string gradeEntry;
        while (getline(gradesStream, gradeEntry, ';'))
        {
            stringstream entryStream(gradeEntry);
            string subject;
            int grade;
            getline(entryStream, subject, ':');
            entryStream >> grade;
            student.addGrade(subject, grade);
        }
        students.push_back(student);
    }
    file.close();
    return students;
}

template <typename T>
void sortAndDisplay(const vector<T> &persons)
{
    vector<T> sortedPersons = persons;
    sort(sortedPersons.begin(), sortedPersons.end(),
         [](const T &a, const T &b)
         { return a.getLastName() < b.getLastName(); });

    for (const auto &person : sortedPersons)
    {
        person.display();
        cout << "-----------------------" << endl;
    }
}

int main()
{

    vector<Teacher> teachers = readTeachersFromFile("teachers.txt");
    vector<Student> students = readStudentsFromFile("students.txt");

    cout << "Teachers Information:" << endl;
    sortAndDisplay(teachers);

    cout << "Students Information:" << endl;
    sortAndDisplay(students);

    return 0;
}
