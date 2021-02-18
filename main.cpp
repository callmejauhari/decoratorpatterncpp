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
    ~FruitJuice(){
        delete _f;
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
    ~FruitPie()
    {
        delete _f;
    }
};

int main()
{
    Fruit *o = new Orange("Jeruk Bali");
    Fruit *ot = new Orange("Jeruk Thaiand");
    FruitJuice *fj = new FruitJuice(o);
    FruitPie *fp = new FruitPie(ot);
    cout << fj->GetType() << endl;
    cout << fp->GetType() << endl;
    return 0;
}