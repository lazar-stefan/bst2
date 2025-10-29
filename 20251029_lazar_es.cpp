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
        new Node(val2);
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
    Node *dad{nullptr};
    Node *current{r};
    while (current != nullptr)
    {
        if (val < r->val)
        {
            dad = current;
            current = current->left_child;
            dad->left_child = new Node(val);
        }
        else if (val > current->val)
        {
            dad = current;
            current = current->right_child;
            dad->right_child = new Node(val);
        }
    }
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
    Node *dad{nullptr};
    Node *current{r};
    if (current->val == val)
    {
        return true;
    }
    while (current != nullptr)
    {
        if (val == current->val)
        {
            return true;
        }
        else
        {
            if (val < r->val)
            {
                dad = current;
                current = current->left_child;
            }
            else if (val > current->val)
            {
                dad = current;
                current = current->right_child;
            }
        }
    }
    return false;
}
void attraversamento1(Node *node)
{

    if (node == nullptr){
        return;
    }
    cout << node->val << " ";
    attraversamento1(node->left_child);
    attraversamento1(node->right_child);
}
int main()
{
    int v;
    cout << "dimmi il tuo valore:" << endl;
    cin >> v;
    Node n(v);

    int num;
    cout << "quanti valori vuoi inserire? " << endl;
    cin >> num;
    int val2{0};
    for (int i = 0; i < num; i++)
    {
        cout << "che valore vuoi inserire? ";
        cin >> val2;
        inserimento_iterativo(&n, val2);
    }

    int valore;
    cout << "quale valore vuoi controllare se è presente? " << endl;
    cin >> valore;
    if (ricerca_ricorsivo(&n, valore))
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
    if (ricerca_iterativo(&n, valor))
    {
        cout << "l'elemento è presante" << endl;
    }
    else
    {
        cout << "l'elemento non è presente" << endl;
    }
    attraversamento1(&n);
    return 0;
}