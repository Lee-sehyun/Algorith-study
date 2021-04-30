#include <iostream>

using namespace std;

template <typename T>
class node
{
private:
    T data;
    node *left;
    node *right;

public:
    node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    void setdata(T data)
    {
        this->data = data;
    }
    void setLeft(node *left)
    {
        this->left = left;
    }
    void setRight(node *right)
    {
        this->right = right;
    }
    T getdata()
    {
        return data;
    }
    node *getLeft()
    {
        return left;
    }
    node *getRight()
    {
        return right;
    }
};

template <typename T>
class tree
{
private:
    node<T> *root;

public:
    tree()
    {
        root = NULL;
    }
    ~tree()
    {
        DeleteALL(root);
    }
    void DeleteALL(node<T> *head)
    {
        if (head->getLeft() != NULL)
        {
            DeleteALL(head->getLeft());
        }
        if (head->getRight() != NULL)
        {
            DeleteALL(head->getRight());
        }
        delete head;
    }
    void insert(T data)
    {
        if (root == NULL)
            root = new node<T>(data);
        else
            insert(data, root);
    }
    void insert(T data, node<T> *head)
    {
        if (head->getdata() > data)
        {
            if (head->getLeft() == NULL)
            {
                head->setLeft(new node<T>(data));
            }
            else
            {
                insert(data, head->getLeft());
            }
        }
        else
        {
            if (head->getRight() == NULL)
            {
                head->setRight(new node<T>(data));
            }
            else
            {
                insert(data, head->getRight());
            }
        }
    }
    // void Delete(T data, node *head = this->root){
    //     if()
    // }
    void preorder()
    {
        preorder(root);
        cout << "\n";
    }
    void preorder(node<T> *head)
    {
        cout << head->getdata() << " ";
        if (head->getLeft() != NULL)
        {
            preorder(head->getLeft());
        }
        if (head->getRight() != NULL)
        {
            preorder(head->getRight());
        }
    }
    void inorder()
    {
        inorder(root);
        cout << "\n";
    }
    void inorder(node<T> *head)
    {
        if (head->getLeft() != NULL)
        {
            inorder(head->getLeft());
        }
        cout << head->getdata() << " ";
        if (head->getRight() != NULL)
        {
            inorder(head->getRight());
        }
    }
    void postorder()
    {
        postorder(root);
        cout << "\n";
    }
    void postorder(node<T> *head)
    {
        if (head->getLeft() != NULL)
        {
            postorder(head->getLeft());
        }
        if (head->getRight() != NULL)
        {
            postorder(head->getRight());
        }
        cout << head->getdata() << " ";
    }
};

int main()
{
    tree<int> t;
    t.insert(4);
    t.insert(2);
    t.insert(1);
    t.insert(3);
    t.insert(6);
    t.insert(5);
    t.insert(7);
    /*
                4
        2               6
    1       3       5       7
    */

    t.preorder();
    t.inorder();
    t.postorder();

    return 0;
}