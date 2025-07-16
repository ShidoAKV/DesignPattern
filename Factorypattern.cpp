#include <bits/stdc++.h>
using namespace std;

// Abstract class
class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

// Three types of burgers
class Basic : public Burger {
public:
    void prepare() override {
        cout << "Preparing the Basic burger" << endl;
    }
};

class Standard : public Burger {
public:
    void prepare() override {
        cout << "Preparing the Standard burger" << endl;
    }
};

class Premium : public Burger {
public:
    void prepare() override {
        cout << "Preparing the Premium burger" << endl;
    }
};

// Abstract factory class
class BurgerFactory {
public:
    virtual Burger* createBurger(string type) = 0;
    virtual ~BurgerFactory() {}
};

// BurgerSingh factory
class BurgerSingh : public BurgerFactory {
public:
    Burger* createBurger(string type) override {
        if (type == "basic") {
            return new Basic();
        } else if (type == "standard") {
            return new Standard();
        } else if (type == "premium") {
            return new Premium();
        } else {
            return nullptr;
        }
    }
};

// BurgerKing factory
class BurgerKing : public BurgerFactory {
public:
    Burger* createBurger(string type) override {
        if (type == "basic") {
            return new Basic();
        } else if (type == "standard") {
            return new Standard();
        } else if (type == "premium") {
            return new Premium();
        } else {
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory* factory = new BurgerSingh();
    Burger* myBurger = factory->createBurger("basic");

    if (myBurger) {
        myBurger->prepare();
        delete myBurger;
    } else {
        cout << "Invalid burger type selected." << endl;
    }

    delete factory;
    return 0;
}
