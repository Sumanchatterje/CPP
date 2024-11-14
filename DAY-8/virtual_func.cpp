#include <bits/stdc++.h>
using namespace std;
// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};
// Derived class Dog
class Dog : public Animal {
public:
    void sound() override {  // Overrides base class function
        cout << "Woof Woof" << endl;
    }
};
// Derived class Cat
class Cat : public Animal {
public:
    void sound() override {  // Overrides base class function
        cout << "Meow Meow" << endl;
    }
};
int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    //Animal animal1,animal2;
    animal1->sound();  // Calls Dog's sound method
    animal2->sound();  // Calls Cat's sound method
   delete animal1;
    delete animal2;

    return 0;
}
