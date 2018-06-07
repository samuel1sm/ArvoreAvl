#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "NodeList.h"
#include <locale>


using namespace std;
template <class T>
class DynamicList
{
public:
    void inserir(T a)
    {
        setlocale (LC_ALL,"Portuguese");
        if(!head)
        {
            head= new NodeList<T>(a);
            tail=head;
        }
        else
        {
            tail->setNoNext(new NodeList<T>(a));
            tail=tail->getNoNext();
        }
    }

    NodeList<T>* getHead()
    {
        setlocale (LC_ALL,"Portuguese");
        return head;
    }

    void clearList()
    {

        setlocale (LC_ALL,"Portuguese");

        head=NULL;
        tail=NULL;
    }

private:
    NodeList<T>* head=NULL;
    NodeList<T>* tail=NULL;

};

#endif // DYNAMICLIST_H
