#ifndef ABINARY_H
#define ABINARY_H
#include "Node.hpp"

using namespace std;
class ABinary
{
public:
    ABinary() {}

    void insertNode(string a)
    {
        root=insertNode(root,a);
    }
    void a()
    {

        a(root);

    }

     void a(Node* node)
    {
        if(node->getLeft())
            a(node->getLeft());
        if(node->getRight())
            a(node->getRight());
        cout<<node->getDado()<<" Altura = "<<node->getH()<<endl;


    }

private:
    Node* root=NULL;

    Node* insertNode(Node* node,string word)
    {

        if(!node)
        {
            node=new Node(word);
            return node;

        }
        else if(word < node->getDado())
        {

            node->setLeft(insertNode(node->getLeft(),word));
            node->setH(calculateHeight(node));


        }
        else
        {
            node->setRight(insertNode(node->getRight(),word));
            node->setH(calculateHeight(node));
        }

        node->setH(calculateHeight(node));

        int aux=getbF(node);

        if(aux==2){
            if(getbF(node->getLeft())<0)
                return doubleRotateRight(node);
            else
                return rotateRight(node);
        }
        else if(aux==-2)
        {
            if(getbF(node->getRight())>0)
                return doubleRotateLeft(node);
            else
                return rotateLeft(node);
        }


    }

    Node* rotateRight(Node* x)
    {
        cout<<"Roda para direita"<<endl;
        Node* aux = x->getLeft();
        x->setLeft(x->getLeft()->getRight());
        aux->setRight(x);
        aux->setH(calculateHeight(aux));
        x->setH(calculateHeight(x));
        return aux;
    }

    Node* rotateLeft(Node* x)
    {
        cout<<"Roda para esquerda"<<endl;
        Node* aux = x->getRight();
        x->setRight(x->getRight()->getLeft());
        aux->setLeft(x);

        aux->setH(calculateHeight(aux));
        x->setH(calculateHeight(x));
        return aux;
    }

    Node* doubleRotateLeft(Node* x)
    {
        x->setRight(rotateRight(x->getRight()));
        x= rotateLeft(x);
        return x;
    }

    Node* doubleRotateRight(Node* x)
    {
        x->setLeft(rotateLeft(x->getLeft()));
        x=rotateRight(x);
        return x;

    }

    /*  Node* balance(Node* node)
      {
          Node* aux=node;
          if(node->getBf()== 2)
          {
              if((node->getLeft())->getBf()<0)
                  aux = doubleRotateLeft(node);
              else
                  aux = rotateLeft(node);
          }
          else if(node->getBf()== -2)
          {
              if((node->getRight())->getBf()>0)
                  aux = doubleRotateRight(node);
              else
                  aux = rotateRight(node);
          }

          return aux;
      }*/

    int calculateHeight(Node* node)
    {

        if (node == NULL)
            return 0; // altura da árvore vazia
        else
        {
            int l = calculateHeight (node->getLeft());
            int r = calculateHeight (node->getRight());
            if (l < r)
                return r + 1;
            else
                return l + 1;
        }

    }

    int getbF(Node* node)
    {
        if(node->getLeft() && !node->getRight())
        {
                return node->getLeft()->getH()-0;
        }
        else if(!node->getLeft() && node->getRight())
        {
                return 0-node->getRight()->getH();
        }
        else
        {
                return node->getLeft()->getH()-node->getRight()->getH();
        }

    }
};

#endif // ABINARY_H
