#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "NodeList.h"

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

    private:
        NodeList<T>* head=NULL;
        NodeList<T>* tail=NULL;

};

#endif // DYNAMICLIST_H
