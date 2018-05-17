#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "NodeList.h"

using namespace std;
class DynamicList
{
    public:
        void inserir(string a)
        {
            if(!head)
            {
                head= new NodeList(a);
                tail=head;
            }
            else
            {
                inserir(head,a);
            }
        }

    private:
        NodeList* head=NULL;
        NodeList* tail=NULL;

        void inserir(NodeList* no,string a)
        {
            if(no->getNoNext())
                inserir(no->getNoNext(),a);
            else
            {
                no->setNoNext(new NodeList(a));
                tail=no->getNoNext();
            }
        }
};

#endif // DYNAMICLIST_H
