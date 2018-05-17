#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(int d) {
        left=NULL;
        right=NULL;
        dado=d;
        }

        Node* getRight(){return right;}
        Node* getLeft(){return left;}
        int getDado(){return dado;}
        void setRight(Node* no){right=no;}
        void setLeft(Node* no){left=no;}
        void setDado(int d){dado=d;}
        void setHeight(int d){height =d;}

    private:
        Node* left;
        Node* right;
        int height;
        int dado;
};

#endif // NODE_H
