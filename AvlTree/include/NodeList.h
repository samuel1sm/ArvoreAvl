#ifndef NODELIST_H
#define NODELIST_H
#include <locale>

using namespace std;
template <class T>

class NodeList
{
public:
    NodeList(T f)
    {

        frase=f;
        noNext=NULL;

    }

    NodeList<T>* getNoNext()
    {
        return noNext;
    }
    T getFrase()
    {
        return frase;
    }
    void setNoNext(NodeList* a )
    {
        noNext =a;
    }
    void setFrase(T a)
    {
        frase = a;
    }

private:
    NodeList* noNext;
    T frase;


};

#endif // NODELIST_H
