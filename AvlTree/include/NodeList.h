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
                setlocale (LC_ALL,"Portuguese");

        frase=f;
        noNext=NULL;

    }

    NodeList<T>* getNoNext()
    {
        setlocale (LC_ALL,"Portuguese");
        return noNext;
    }
    T getFrase()
    {
        setlocale (LC_ALL,"Portuguese");
        return frase;
    }
    void setNoNext(NodeList* a )
    {
        setlocale (LC_ALL,"Portuguese");
        noNext =a;
    }
    void setFrase(T a)
    {
        setlocale (LC_ALL,"Portuguese");
        frase = a;
    }

private:
    NodeList* noNext;
    T frase;


};

#endif // NODELIST_H
