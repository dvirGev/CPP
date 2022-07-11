#include <iostream>
using namespace std;
class A
{
private:
    /* data */
public:
    virtual void print() = 0;
};
class B : public A
{
    public:
    B():A(){}
    void stam()
    {
        cout << "stam" << endl;
    }
    virtual void print()
    {
        cout << "print" << endl;
    }
};

int main(int argc, char const *argv[])
{
    B b;
    A *a = &b;
    a->print();
    return 0;
}

