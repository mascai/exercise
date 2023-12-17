#include <iostream>

using namespace std;


class IWidget {
public:
    virtual void draw() = 0;
};

class LinuxButton : public IWidget {
public:
    void draw() {
        cout << "LinuxButton" << endl;
    }
};

class LinuxMenu : public IWidget {
public:
    void draw() {
        cout << "LinuxMenu" << endl;
    }
};

class WindowsButton : public IWidget {
public:
    void draw() {
        cout << "WindowsButton" << endl;
    }
};

class WindowsMenu : public IWidget {
public:
    void draw() {
        cout << "WindowsMenu" << endl;
    }
};

class IFactory {
public:
    virtual IWidget* create_button() = 0;
    virtual IWidget* create_menu() = 0;
};


class WindowsFactory : public IFactory {
public:
    IWidget* create_button() {
        return new WindowsButton();
    }

    IWidget* create_menu() {
        return new WindowsMenu();
    }
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

class Client {
private:
    IFactory* factory;
public:
    Client(IFactory* f) {
        factory = f;
    }
    void draw() {
    IWidget *w = factory->create_button();
    w->draw();
    display_window_one();
    display_window_two();
  }

  void display_window_one() {
    IWidget *w[] = {
        factory->create_button(),
        factory->create_menu()
    };
    w[0]->draw();
    w[1]->draw();
  }

  void display_window_two() {
    IWidget *w[] = {
        factory->create_menu(),
        factory->create_button()
    };
    w[0]->draw();
    w[1]->draw();
  }
};

int main() {
    Client client(new LinuxFactory());
    client.draw();
}
