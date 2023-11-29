    #include <iostream>
    #include <vector>
    #include <list>
    #include <string>
    #include <algorithm> // find

    using namespace std;

    struct Team;
    struct Employee;

    class IObserver {
    public:
        virtual void on_event(Team& team, const Employee&) = 0;
    };

    struct Employee {
        Employee(const string& name) : name_(name) {}
        bool operator==(const Employee& other) const {
            return name_ == other.name_;
        }
    public:
        string name_ = 0;
    };

    struct Team {
        Team(const string& name): name_(name) {}
        
        void add_employee(Employee& new_employee) {
            // Add new employee and notify observers
            if (find(begin(employees_), end(employees_), new_employee) == employees_.end()){
                employees_.push_back(new_employee);
                for (auto observer : observers_) {
                    observer->on_event(*this, new_employee);
                }
            }
        }

        void add_observer(IObserver& observer) {
            observers_.push_back(&observer);
        }
    public:
        string name_;
        vector<Employee> employees_;
        list<IObserver*> observers_;
    };


    class FinDepartment: public IObserver {
    public:
        void on_event(Team& team, const Employee& e) {
            cout << "FinDepartment: Increase team " << team.name_ << " budget" << endl;
            cout << "FinDepartment: Process employee " << e.name_ << " data" << endl;
        }
    };


    class SecurityDepartment: public IObserver {
    public:
        void on_event(Team& team, const Employee& e) {
            cout << "SecurityDepartment: Check employee " << e.name_  << endl;
            cout << "SecurityDepartment: Check team " << team.name_ << " and new employee relations" << endl;
        }
    };


    int main() {
        Team team = Team("team1");
        SecurityDepartment security;
        FinDepartment fin;
        team.add_observer(security);
        team.add_observer(fin);

        Employee employee1 {"Alisa"};
        team.add_employee(employee1);
    }
