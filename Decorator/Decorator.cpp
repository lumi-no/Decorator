#include <iostream>
#include <string>


class Component {
public:
    virtual ~Component() = default;
    virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};

class Decorator : public Component {
protected:
    Component* component_; 

public:
    Decorator(Component* component) : component_(component) {}
    virtual ~Decorator() {
        delete component_;
    }

    std::string Operation() const override {
        return component_->Operation();
    }
};


class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    std::string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};


class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    std::string Operation() const override {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};


void ClientCode(const Component* component) {
    std::cout << "Результат: " << component->Operation() << std::endl;
}

int main() {
  
    Component* simple = new ConcreteComponent;
    std::cout << "Клієнт: Я отримую простий компонент:\n";
    ClientCode(simple);


    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "\nКлієнт: Тепер я отримую декорований компонент:\n";
    ClientCode(decorator2);

    delete decorator2;

    return 0;
}
