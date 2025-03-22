// FIRST (simple version)

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

// SECOND VERSION

#include <iostream>
#include <exception>
#include <string>
#include <thread>
#include <vector>
#include <memory>

using namespace std;

// Forward declaration
class DrawStrategy;

/**
 * @brief Abstract base class for shapes
 */
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;  // Modern C++ way to declare virtual destructor
};

/**
 * @brief Circle shape implementation
 */
class Circle : public Shape {
public:
    // Constructor with explicit initialization and nullptr check
    explicit Circle(shared_ptr<DrawStrategy> strat, int radius = 0) 
        : strat_(std::move(strat))
        , radius_(radius) {
        if (!strat_) {
            throw std::invalid_argument("Strategy cannot be null");
        }
    }

    void draw() override;
    
    // Const-correct getter
    [[nodiscard]] int getRadius() const noexcept {
        return radius_;
    }

    // Add setter with validation
    void setRadius(int r) {
        if (r < 0) {
            throw std::invalid_argument("Radius cannot be negative");
        }
        radius_ = r;
    }

private:
    int radius_{0};  // Member initialization
    shared_ptr<DrawStrategy> strat_;  // Using shared_ptr instead of unique_ptr for strategy
};

/**
 * @brief Rectangle shape implementation
 */
class Rectangle : public Shape {
public:
    explicit Rectangle(shared_ptr<DrawStrategy> strat, int width = 0, int height = 0)
        : strat_(std::move(strat))
        , width_(width)
        , height_(height) {
        if (!strat_) {
            throw std::invalid_argument("Strategy cannot be null");
        }
    }

    void draw() override;

    // Add getters and setters
    [[nodiscard]] int getWidth() const noexcept { return width_; }
    [[nodiscard]] int getHeight() const noexcept { return height_; }

    void setDimensions(int w, int h) {
        if (w < 0 || h < 0) {
            throw std::invalid_argument("Dimensions cannot be negative");
        }
        width_ = w;
        height_ = h;
    }

private:
    int width_{0};
    int height_{0};
    shared_ptr<DrawStrategy> strat_;
};

/**
 * @brief Drawing strategy interface
 */
class DrawStrategy {
public:
    virtual void draw(const Circle* circle) = 0;
    virtual void draw(const Rectangle* rect) = 0;
    virtual ~DrawStrategy() = default;
};

/**
 * @brief OpenGL implementation of drawing strategy
 */
class DrawStrategyOpenGL : public DrawStrategy {
public:
    void draw(const Circle* circle) override {
        if (!circle) {
            throw std::invalid_argument("Circle pointer is null");
        }
        cout << "CircleOpenGL: radius = " << circle->getRadius() << endl;
    }

    void draw(const Rectangle* rect) override {
        if (!rect) {
            throw std::invalid_argument("Rectangle pointer is null");
        }
        cout << "RectangleOpenGL: width = " << rect->getWidth() 
             << ", height = " << rect->getHeight() << endl;
    }
};

void Circle::draw() {
    strat_->draw(this);
}

void Rectangle::draw() {
    strat_->draw(this);
}

int main() {
    try {
        // Create a vector of shapes and a shared drawing strategy
        vector<unique_ptr<Shape>> shapes;
        auto strategy = make_shared<DrawStrategyOpenGL>();

        // Create shapes with different parameters
        shapes.emplace_back(make_unique<Circle>(strategy, 5));
        shapes.emplace_back(make_unique<Rectangle>(strategy, 10, 20));

        // Draw all shapes
        for (const auto& shape : shapes) {
            shape->draw();
        }

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
