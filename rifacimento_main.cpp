#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *left_child;
    Node *right_child;

    Node(int v)
    {
        val = v;
        left_child = nullptr;
        right_child = nullptr;
    }
    Node(const Node &other)
    {
        val = other.val;
        left_child = other.left_child;
        right_child = other.right_child;
    }
    Node(const Node *other)
    {
        val = other->val;
        left_child = other->left_child;
        right_child = other->right_child;
    }
};
Node *inserimento_ricorsivo(Node *ptr, int val2)
{
    if (ptr == nullptr)
    {
        return new Node(val2);
    }
    if (ptr->val == val2)
    {
        return ptr;
    }

    if (val2 < ptr->val)
    {
        ptr->left_child = inserimento_ricorsivo(ptr->left_child, val2);
    }
    else
    {
        ptr->right_child = inserimento_ricorsivo(ptr->right_child, val2);
    }
    return ptr;
}
Node *inserimento_iterativo(Node *r, int val)
{
    Node *newNode = new Node(val);
    if (r == nullptr)
        return newNode;

    Node *current = r;
    Node *dad = nullptr;

    while (current != nullptr)
    {
        dad = current;
        if (val < current->val)
            current = current->left_child;
        else if (val > current->val)
            current = current->right_child;
        else
            return r;
    }
    if (val < dad->val)
        dad->left_child = newNode;
    else
        dad->right_child = newNode;

    return r;
}

bool ricerca_ricorsivo(Node *ptr, int val2)
{
    if (ptr == nullptr)
    {
        return false;
    }
    if (ptr->val == val2)
    {
        return true;
    }
    if (val2 < ptr->val)
    {
        return ricerca_ricorsivo(ptr->left_child, val2);
    }
    else
    {
        return ricerca_ricorsivo(ptr->right_child, val2);
    }
    return false;
}
bool ricerca_iterativo(Node *r, int val)
{
    Node *current = r;
    while (current != nullptr)
    {
        if (val == current->val)
            return true;
        else if (val < current->val)
            current = current->left_child;
        else
            current = current->right_child;
    }
    return false;
}

void attraversamento1(Node *node)
{

    if (node == nullptr)
    {
        return;
    }
    cout << node->val << " ";
    attraversamento1(node->left_child);
    attraversamento1(node->right_child);
}
void attraversamento2(Node *node)
{

    if (node == nullptr)
    {
        return;
    }
    attraversamento2(node->left_child);
    cout << node->val << " ";
    attraversamento2(node->right_child);
}
void attraversamento3(Node *node)
{

    if (node == nullptr)
    {
        return;
    }
    attraversamento3(node->left_child);
    attraversamento3(node->right_child);
    cout << node->val << " ";
}
int main()
{
    int v;
    cout << "dimmi il tuo valore:" << endl;
    cin >> v;
    
    int num;
    cout << "quanti valori vuoi inserire? " << endl;
    cin >> num;
    int val2{0};
    Node *root = new Node(v);
    for (int i = 0; i < num; i++)
    {
        cout << "che valore vuoi inserire? ";
        cin >> val2;
        root = inserimento_iterativo(root, val2);
    }

    int valore;
    cout << "quale valore vuoi controllare se è presente? " << endl;
    cin >> valore;
    if (ricerca_ricorsivo(root, valore))
    {
        cout << "l'elemento è presante" << endl;
    }
    else
    {
        cout << "l'elemento non è presente" << endl;
    }

    int valor;
    cout << "quale valore vuoi controllare se è presente? " << endl;
    cin >> valor;
    if (ricerca_iterativo(root, valor))
    {
        cout << "l'elemento è presante" << endl;
    }
    else
    {
        cout << "l'elemento non è presente" << endl;
    }
    attraversamento1(root);
    attraversamento2(root);
    attraversamento3(root);
    return 0;
}