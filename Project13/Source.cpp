#include <iostream>
using namespace std;

// Base class
class Base {
private:
    int privateBase = 1;
protected:
    int protectedBase = 2;
public:
    int publicBase = 3;
    void accessBase() {
        cout << "Base class access: " << privateBase << ", " << protectedBase << ", " << publicBase << endl;
    }
};

// Derived class with public inheritance
class DerivedPublic : public Base {
private:
    int privateDerived = 4;
public:
    void accessDerived() {
        // cout << "DerivedPublic class access privateBase: " << privateBase << endl; // Error: privateBase is private in Base
        cout << "DerivedPublic class access protectedBase: " << protectedBase << endl;
        cout << "DerivedPublic class access publicBase: " << publicBase << endl;
    }
};

// Derived class with protected inheritance
class DerivedProtected : protected Base {
private:
    int privateDerived = 5;
public:
    void accessDerived() {
        // cout << "DerivedProtected class access privateBase: " << privateBase << endl; // Error: privateBase is private in Base
        cout << "DerivedProtected class access protectedBase: " << protectedBase << endl;
        // cout << "DerivedProtected class access publicBase: " << publicBase << endl; // Error: publicBase is protected in DerivedProtected
    }
};

// Derived class with private inheritance
class DerivedPrivate : private Base {
private:
    int privateDerived = 6;
public:
    void accessDerived() {
        // cout << "DerivedPrivate class access privateBase: " << privateBase << endl; // Error: privateBase is private in Base
        // cout << "DerivedPrivate class access protectedBase: " << protectedBase << endl; // Error: protectedBase is private in DerivedPrivate
        // cout << "DerivedPrivate class access publicBase: " << publicBase << endl; // Error: publicBase is private in DerivedPrivate
    }
};

// Further derived class from DerivedPublic
class FurtherDerived : public DerivedPublic {
public:
    void accessFurtherDerived() {
        // cout << "FurtherDerived class access privateBase: " << privateBase << endl; // Error: privateBase is not accessible
        cout << "FurtherDerived class access protectedBase: " << protectedBase << endl;
        cout << "FurtherDerived class access publicBase: " << publicBase << endl;
    }
};

int main() {
    Base base;
    DerivedPublic derivedPublic;
    DerivedProtected derivedProtected;
    DerivedPrivate derivedPrivate;
    FurtherDerived furtherDerived;

    base.accessBase();
    derivedPublic.accessDerived();
    derivedProtected.accessDerived();
    derivedPrivate.accessDerived();
    furtherDerived.accessFurtherDerived();
    return 0;
}
