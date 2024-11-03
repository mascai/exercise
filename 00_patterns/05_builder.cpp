#include <iostream>
#include <memory>


using namespace std;

class Engine {
public:
    void setPower(int power) { power_ = power;}
    int getPower() { return power_;}
private:
    int power_;
};

class Body {
public:
    void setSize(int size) { size_ = size;}
    int getSize() { return size_;}
private:
    int size_;
};

struct Car {
    Body body_;
    Engine engine_;
};


class ICarBuilder {
public:
    virtual void buildEngine() = 0;
    virtual void buildBody() = 0;
    virtual unique_ptr<Car> getCar() = 0;
protected:
    unique_ptr<Car> car_;
};


class TeslaModelXBuilder : public ICarBuilder {
public:
    TeslaModelXBuilder() {
        car_.reset(new Car);
    }

    void buildEngine() { car_->engine_.setPower(200);}
    void buildBody() { car_->body_.setSize(3);}
    unique_ptr<Car> getCar() {
        cout << "Car TeslaModelX is ready. EnginePower: " << car_->engine_.getPower() << " BodySize: " << car_->body_.getSize() << endl;
        return std::move(car_);
    }
};


class TeslaModelSBuilder : public ICarBuilder {
public:
    TeslaModelSBuilder() {
        car_.reset(new Car);
    }

    void buildEngine() { car_->engine_.setPower(100);}
    void buildBody() { car_->body_.setSize(5);}
    unique_ptr<Car> getCar() {
        cout << "Car TeslaModelS is ready. EnginePower: " << car_->engine_.getPower() << " BodySize: " << car_->body_.getSize() << endl;
        return std::move(car_);
    }
};


class Director {
public:
    unique_ptr<Car> buildCar(ICarBuilder& builder) {
        builder.buildBody();
        builder.buildEngine();
        return builder.getCar();
    }
};


int main() {
    TeslaModelSBuilder builerS;
    TeslaModelXBuilder builerX;

    Director director;
    director.buildCar(builerS);
    director.buildCar(builerX);
}
