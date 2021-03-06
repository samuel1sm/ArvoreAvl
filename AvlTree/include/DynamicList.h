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
        return head;
    }

    void clearList()
    {


        head=NULL;
        tail=NULL;
    }

private:
    NodeList<T>* head=NULL;
    NodeList<T>* tail=NULL;

};

#endif // DYNAMICLIST_H
