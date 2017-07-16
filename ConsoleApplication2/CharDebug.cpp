#include "CharDebug.h"



CharDebug::CharDebug()
{
}


CharDebug::~CharDebug()
{
}

typedef struct _person
{
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
}Person;

size_t stringLength(const char* string) {
    size_t length = 0;
    while (*(string++)) {
        length++;
    }
    return length;
}

void debug() {
    char header[] = "Media player";
    cout << header << endl;

    char* header2 = (char*)malloc(strlen("Media player") + 1);
    strcpy(header2, "Media player");

    cout << header2 << endl;
    if (strcmp(header2, "Media player") == 0) {
        cout << "equal " << endl;
    }
    else
    {
        cout << "none equal " << endl;
    }
}

char* strtoLow(const char* string) {
    char* tmp = (char*)malloc(strlen(string) + 1);
    char* start = tmp;
    while(*string != 0) {
        *tmp++ = tolower(*string++);
    }
    *tmp = 0;
    return start;
}


void initialPersion(Person* person, const char* fn, const char* ln, const char* title, size_t age) {
    person->firstName = (char*)malloc(sizeof(fn) + 1);
    strcpy(person->firstName, fn);

    person->lastName = (char*)malloc(sizeof(ln) + 1);
    strcpy(person->lastName, ln);

    person->title = (char*)malloc(sizeof(title) + 1);
    strcpy(person->title, title);

    person->age = age;

}

void showPs(const Person* person) {
    cout << person->firstName << endl;
    cout << person->lastName << endl;
    cout << person->title << endl;
    cout << person->age << endl;

}


void dealPerson(Person* person) {
    free(person->firstName);
    free(person->lastName);
    free(person->title);

}

/*
template<class T>
class NameObject {
public:
    NameObject(string& name, const T& value);
private:
    string& nameValue;
    const T objectValue;
};
*/

int main_CharDebug() {
    char* header2 = (char*)malloc(strlen("Media player") + 1);
    strcpy(header2, "Media player");
    cout << header2 << endl;

    size_t len = stringLength(header2);
    cout << len << endl;

    char* low2 = strtoLow(header2);
    cout << low2 << endl;

    Person person;

    person.firstName = (char*)malloc(strlen("ww") + 1);
    person.firstName = "ww";

    person.lastName = "bb";
    person.title = "tt";
    person.age = 12;

    cout << person.firstName << endl;

    Person ps;
    initialPersion(&ps, "le", "qq", "cpp", 12);
    showPs(&ps);

    dealPerson(&ps);

    string newDog("new");
    string oldDag("old");
    /*NameObject<int> p(newDog, 2);
    NameObject<int> s(oldDag, 2);*/


    return -1;
}


class Window {
private:
    string fistname;
public:
    string name() const;
    virtual void display() const;
};

string Window::name() const {
    return fistname;
}

void Window::display() const {
    cout << "i am window" << endl;
}

class WindowWithScrollBars : public Window {
    virtual void display() const;
};

void WindowWithScrollBars::display() const{
    cout << "i am WindowWithScrollBars" << endl;
}


void printDisplay(Window* w) {
    w->display();
}

void printDisplayYiny(const Window& w) {
    w.display();
}

int main() {
    cout << "debug" << endl;

    Window* w = new Window;
    WindowWithScrollBars* wd = new WindowWithScrollBars;
    printDisplay(w);
    printDisplay(wd);


    Window w2;
    WindowWithScrollBars wd2;

    printDisplayYiny(w2);
    printDisplayYiny(wd2);

    return -1;
}