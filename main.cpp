#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Fruit
{
protected:
    string _type;

public:
    string GetType() { return _type; }
};

class Orange : public Fruit
{
public:
    Orange(string name)
    {
        this->_type.append(name);
    }
};

class FruitJuice : public Fruit
{
    Fruit *_f;

public:
    FruitJuice(Fruit *f) : _f(f)
    {
        this->_type.append(_f->GetType() + " Juice");
    }
};

class FruitPie : public Fruit
{
    Fruit *_f;

public:
    FruitPie(Fruit *f) : _f(f)
    {
        this->_type.append(_f->GetType() + " Pie");
    }
};

int main()
{
    Fruit *o = new Orange("Jeruk Bali");
    FruitJuice *fj = new FruitJuice(o);
    FruitPie *fp = new FruitPie(o);
    cout << fj->GetType() << endl;
    cout << fp->GetType() << endl;
}