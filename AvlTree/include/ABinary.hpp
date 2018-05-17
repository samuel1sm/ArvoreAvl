#ifndef ABINARY_H
#define ABINARY_H
#include "Node.hpp"

using namespace std;
class ABinary
{
    public:
        ABinary() {}

        void insertNewNode(string a)
        {
            if(!root)
                root=new Node(a);
            else
                insertNewNode(a,root);

        }

    private:
        Node* root=NULL;

        void insertNewNode(string a,Node* no)
        {
            if(no->getDado()>a)
            {
                if(no->getLeft())
                    insertNewNode(a,no->getLeft());
                else
                    no->setLeft(new Node(a));
            }
            else
            {
                if(no->getRight())
                    insertNewNode(a,no->getRight());
                else
                    no->setRight(new Node(a));
            }

        }




};

#endif // ABINARY_H
