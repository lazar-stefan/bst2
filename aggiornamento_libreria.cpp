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
Node *nodocancellazione(Node *r, int k)
{
    if (r == nullptr)
        return r;
    if (r->val > k)
    {
        r->left_child = nodocancellazione(r->left_child, k);
    }
    else
    {
        if (r->val < k)
        {
            r->right_child = nodocancellazione(r->right_child, k);
        }
    }
    if (r->left_child == nullptr && r->right_child == nullptr)
    {
        delete r;
        return nullptr;
    }
    else
    {
        if (r->left_child == nullptr)
        {
            Node *t = r->right_child;
            delete r;
            return t;
        }
        else
        {
            if (r->right_child == nullptr)
            {
                Node *t = r->left_child;
                delete r;
                return t;
            }
            else
            {
                Node *prec = r;
                Node *succ = r->right_child;

                while (succ->left_child != nullptr)
                {
                    prec = succ;
                    succ = succ->left_child;
                }

                r->val = succ->val;

                if (prec->left_child == succ)
                    prec->left_child = nodocancellazione(succ, succ->val);
                else
                    prec->right_child = nodocancellazione(succ, succ->val);
            }
        }
    }
    return r;
}
int altezza(Node* r) {
    if (r == nullptr) {
        cout << "l'albero è vuoto quindi l'altezza è 0" << endl;
        return 0;
    }
    int h1 = altezza(r->left_child);
    cout << "l'altezza del albero sinistro è: " << r->val << " è " << h1 << endl;

    int h2 = altezza(r->right_child);
    cout << "l'altezza del albero destro è: " << r->val << " è " << h2 << endl;

    int max;
    if (h1 > h2)
        max = h1;
    else
        max = h2;

    int h3= 1 + max;
    cout << "Altezza totale del nodo " << r->val << " = " << h3 << endl;

    return h3;
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
    int n;
    cout << "che noumero vuoi cancellare? ";
    cin >> n;
    root = nodocancellazione(root, n);
    cout << "dopo la cancellazione è: ";
    attraversamento2(root);
    cout << endl;
    altezza(root);
    return 0;
}