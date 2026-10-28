#include <iostream>
using namespace std;

// Forward declaration needed because ClassA's friend declaration
// refers to ClassB before ClassB has been fully defined.
class ClassB;

class ClassA {
private:
    int num;   // private member - normally not accessible outside the class

public:
    ClassA(int n) : num(n) {}

    void display() const {
        cout << "ClassA number = " << num << endl;
    }

    // Declares swapNumbers() as a friend: it is NOT a member of ClassA,
    // but it is still allowed to access ClassA's private data.
    friend void swapNumbers(ClassA &a, ClassB &b);
};

class ClassB {
private:
    int num;   // private member

public:
    ClassB(int n) : num(n) {}

    void display() const {
        cout << "ClassB number = " << num << endl;
    }

    // Same function is also declared a friend of ClassB,
    // so it can access ClassB's private data too.
    friend void swapNumbers(ClassA &a, ClassB &b);
};

// Definition of the friend function.
// Because it is a friend of BOTH classes, it can directly touch
// a.num and b.num even though "num" is private in each class.
void swapNumbers(ClassA &a, ClassB &b) {
    int temp = a.num;
    a.num = b.num;
    b.num = temp;
}

int main() {
    int x, y;

    cout << "Enter first number (for ClassA object)  : ";
    cin  >> x;
    cout << "Enter second number (for ClassB object) : ";
    cin  >> y;

    ClassA objA(x);
    ClassB objB(y);

    cout << "\nBefore swapping:\n";
    objA.display();
    objB.display();

    swapNumbers(objA, objB);   // friend function call - not objA.swapNumbers(...)

    cout << "\nAfter swapping:\n";
    objA.display();
    objB.display();

    return 0;
}
