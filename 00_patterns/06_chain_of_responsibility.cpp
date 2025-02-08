#include <iostream>
#include <exception>
#include <string>
#include <thread>
#include <vector>

using namespace std;


class IWorker {
public:
    virtual IWorker* setNextWorker(IWorker* worker) = 0;
    virtual string execute(const string& command) = 0;
};


class AbstractWorker : public IWorker {
public:
    AbstractWorker() {}
    IWorker* setNextWorker(IWorker* worker) override {
        nextWorker = worker;
        return worker;
    }

    string execute(const string& command) override {
        if (nextWorker) {
            return nextWorker->execute(command);
        }
        return {};
    }
private:
    IWorker* nextWorker = nullptr;
};


class BackendWorker : public AbstractWorker {
    string execute(const string& command) {
        if (command == "create backend") {
            return "Backend created by BackendWorker";
        }
        return AbstractWorker::execute(command);
    }
};


class FrontendWorker : public AbstractWorker {
    string execute(const string& command) {
        if (command == "create frontend") {
            return "Frontend created by FrontendWorker";
        }
        return AbstractWorker::execute(command);
    }
};


class AdmindWorker : public AbstractWorker {
    string execute(const string& command) {
        if (command == "deploy project") {
            return "Deployed by AdmindWorker";
        }
        return AbstractWorker::execute(command);
    }
};


void runCommand(const string& command, IWorker* worker) {
    const string command_res = worker->execute(command);
    if (command_res.empty()) {
        cout << "Error: no workers for command " << command << endl;
    } else {
        cout << command_res << endl;
    }
}


int main() {
    BackendWorker* backendWorker = new BackendWorker();
    FrontendWorker* frontendWorker = new FrontendWorker();
    AdmindWorker* admindWorker = new AdmindWorker();

    admindWorker->setNextWorker(backendWorker)->setNextWorker(frontendWorker);
    vector<string> commands {"create backend", "create frontend", "deploy project"};
    for (auto& command : commands) {
        runCommand(command, admindWorker);
    }
}

/*
Backend created by BackendWorker
Frontend created by FrontendWorker
Deployed by AdmindWorker
*/
