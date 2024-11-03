#include <iostream>


using namespace std;


class IWidget {
public:
    virtual void draw() = 0;
};


class LinuxButton : public IWidget{
public:
    void draw() {
        cout << "LinuxButton"  << endl;
    }
};

class LinuxMenu : public IWidget {
public:
    void draw() {
        cout << "LinuxMenu" << endl;
    }
};


class WinButton : public IWidget{
public:
    void draw() {
        cout << "WinButton"  << endl;
    }
};

class WinMenu : public IWidget {
public:
    void draw() {
        cout << "WinMenu" << endl;
    }
};


class IFactory {
public:
    virtual IWidget* create_button() = 0;
    virtual IWidget* create_menu() = 0;
};


class LinuxFactory : public IFactory {
public:
    IWidget* create_button() {
        return new LinuxButton();
    }

    IWidget* create_menu() {
        return new LinuxMenu();
    }
};


class Winactory : public IFactory {
public:
    IWidget* create_button() {
        return new WinButton();
    }

    IWidget* create_menu() {
        return new WinMenu();
    }
};


class Client {
public:
    Client(IFactory* factory) {
        factory_ = factory;
    }

    void draw_window() {
        IWidget* button = factory_->create_button();
        IWidget* menu = factory_->create_menu();

        button->draw();
        menu->draw();
    }
private:
    IFactory* factory_;
};

int main() {
    cout << "Hello user" << endl;
    Client client(new LinuxFactory);
    client.draw_window();
}
