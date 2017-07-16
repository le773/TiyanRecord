#include "EffectCpp20.h"



EffectCpp20::EffectCpp20()
{
}


EffectCpp20::~EffectCpp20()
{
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

void WindowWithScrollBars::display() const {
    cout << "i am WindowWithScrollBars" << endl;
}


void printDisplay(Window* w) {
    w->display();
}

void printDisplayYiny(const Window& w) {
    w.display();
}

int main_EffectCpp20() {
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