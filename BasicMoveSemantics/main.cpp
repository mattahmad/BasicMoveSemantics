#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    
    A() : s("default") {}
    
    A(const A& o) : s(o.s) { cout << "move failed!\n";}
    
    A(A&& o) : s(move(o.s)) {}
    
    string printObj() { return s; }
    
private:
    string s;
};

A temp(A a) {
    return a;
}
    
int main(int argc, const char * argv[]) {

    A a1 = temp(A());
    
    cout << "before move() : a1 = " << a1.printObj() << endl;
    A a2 = move(a1);
    cout << "after move() : a1 = " << a1.printObj() << endl;
    cout << "after move() : a2 = " << a2.printObj() << endl;
    
    return 0;
}
