#include <iostream>
using namespace std;

// Abstraksi strategi memasak
class CookStrategy {
public:
    virtual void cook() = 0;
    virtual ~CookStrategy() {}
};

// Implementasi strategi: wajan
class WokStrategy : public CookStrategy {
public:
    void cook() override {
        cout << "Masak pakai wajan! 🔥" << endl;
    }
};

// Implementasi strategi: pressure cooker
class PressureCookerStrategy : public CookStrategy {
public:
    void cook() override {
        cout << "Masak pakai pressure cooker! 💨" << endl;
    }
};

// Context: Chef
class Chef {
private:
    CookStrategy* strategy;

public:
    Chef(CookStrategy* s) : strategy(s) {}

    void prepareDish() {
        cout << "Chef mulai memasak..." << endl;
        strategy->cook();
    }
};

int main() {
    WokStrategy wok;
    PressureCookerStrategy cooker;

    Chef chef1(&wok);
    chef1.prepareDish();

    Chef chef2(&cooker);
    chef2.prepareDish();

    return 0;
}
