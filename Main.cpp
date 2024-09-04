#include<iostream>
#include<Windows.h>
using namespace std;

class Person
{
protected:
    char* name;
    int age;
public:
    Person() = default;
    Person(const char* Name, int Age)
    {
        cout << "Construct Person\n";
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
        age = Age;
    }

    void Print() const
    {
        cout << "Output Person\n";
        cout << "Name: " << name << endl
            << "Age: " << age << endl;
    }

    void Input()
    {
        cout << "Enter name: ";
        char buff[20];
        cin.getline(buff, 20);
        name = new char[strlen(buff) + 1];
        strcpy_s(name, strlen(buff) + 1, buff);
        cout << "Enter age: ";
        cin >> age;
    }

    ~Person()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
        cout << "Destruct Person\n";
        Sleep(1000);
    }
};

class Student : public Person // child class
{
    char* Univer;
public:
    Student() = default;
    Student(const char* n, int a, const char* u) : Person(n, a)
    {
        cout << "Construct Student\n";
        Univer = new char[strlen(u) + 1];
        strcpy_s(Univer, strlen(u) + 1, u);
    }

    ~Student()
    {
        if (Univer != nullptr)
        {
            delete[] Univer;
        }
        cout << "Destruct Univer\n";
        Sleep(1000);
    }

    void Print() // перевизначення
    {
        cout << "Output Student\n";
        /*cout << name << ", " << age << endl;*/
        Person::Print();
        cout << "University: " << Univer << endl;
    }
    void Input(const char* u)// заміщення
    {
        delete[] Univer;
        Univer = new char[strlen(u) + 1];
        strcpy_s(Univer, strlen(u) + 1, u);
        Person::Input();
    }
};

class Teacher : public Person
{
    int sallary;
    const char* subject[3];

public:
    Teacher() :sallary(0), subject{ "Math", "Physics", "Chemistry" } {}
    Teacher(const char* n, int a, int sallary) : Person(n, a), sallary(sallary)
    {
        cout << "Construct Teacher\n";
        subject[0] = "Math";
        subject[1] = "Physics";
        subject[2] = "Chemistry";
    }
    ~Teacher()
    {
        delete[] subject;
        cout << "Destruct Teacher\n";
    }
    void Print()
    {
        cout << "Output Teacher\n";
        Person::Print();
        cout << "Sallary: " << sallary << endl;
        cout << "Subject: ";
        for (int i = 0; i < 3; i++)
        {
            cout << subject[i] << " ";

        }
        cout << endl;
    }
    void Input()
    {
        Person::Input();
        cout << "Enter sallary: ";
        cin >> sallary;
    }
};

class Driver : public Person // child class
{
    char* number_auto;
    char* number_serial;
    char* number_license;
public:
    Driver() = default;
    Driver(const char* n, int a, const char* t, const char* s, const char* l) : Person(n, a)
    {
        cout << "Construct Driver\n";
        number_auto = new char[strlen(t) + 1];
        strcpy_s(number_auto, strlen(t) + 1, t);
        number_serial = new char[strlen(s) + 1];
        strcpy_s(number_serial, strlen(s) + 1, s);
        number_license = new char[strlen(l) + 1];
        strcpy_s(number_license, strlen(l) + 1, l);
    }

    ~Driver()
    {
        if (number_auto != nullptr  number_serial != nullptr  number_license != nullptr)
        {
            delete[] number_auto;
            delete[] number_serial;
            delete[] number_license;
        }
        cout << "Destruct driver\n";
        Sleep(1000);
    }

    void Print() // перевизначення
    {
        cout << "Output Student\n";
        /*cout << name << ", " << age << endl;*/
        Person::Print();
        cout << "Number auto: " << number_auto << endl;
        cout << "Number serial: " << number_serial << endl;
        cout << "Number license: " << number_license << endl;
    }

    void Input(const char* t, const char* s, const char* l)// заміщення
    {
        delete[] number_auto;
        delete[] number_serial;
        delete[] number_license;
        number_auto = new char[strlen(t) + 1];
        strcpy_s(number_auto, strlen(t) + 1, t);
        number_serial = new char[strlen(s) + 1];
        strcpy_s(number_serial, strlen(s) + 1, s);
        number_license = new char[strlen(l) + 1];
        strcpy_s(number_license, strlen(l) + 1, l);
        Person::Input();
    }
};

int main()
{
    Driver d("Nic", 42, "merc", "u", "be");
    d.Print();

    Teacher t("Tony", 20, 10000);
    t.Print();
    t.Input();
    t.Print();

    system("pause");
}


