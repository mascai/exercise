

struct IStrategy {
    virtual int solve() = 0;
};

struct Easy : IStrategy{
    int solve() override {
        return 0;
    }
};

struct Hard : IStrategy{
    int solve() override {
        return 10;
    }
};

class Solver {
public:
    Solver(IStrategy* strat_) : strat(strat_) {}
    void solve() {
        std::cout << strat->solve() << std::endl;
    }
private:
    IStrategy* strat = nullptr;
};

int main() {
    IStrategy* easy = new Easy();   
    IStrategy* hard = new Hard();

    Solver hardSolver(hard);
    hardSolver.solve();   

    Solver easySolver(easy);
    easySolver.solve();
}
