#include <iostream>
using namespace std;
struct xzt
{
    int data;
    xzt* next;
};
xzt* newkk(int data)
{
    xzt* temp = new xzt;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void inorder(xzt* root)
{
    if (root != NULL)
    {
        cout << root->data;
        inorder(root->next);
    }
}
xzt* _push(xzt** node, int data)
{
    xzt* temp = new xzt;
    temp->data = data;
    temp->next = *node;
    *node = temp;
    return 0;
}
xzt* insert(xzt* node, int data, int Qs[])
{
    if (node == NULL)
        return newkk(data);
    node->next = insert(node->next, data, Qs);

    return node;
}

int Qs[2000001] = {}, k;
int main()
{

    xzt* root = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i == 0)
            root = insert(root, x, Qs);
        else
            insert(root, x, Qs);
    }
    while (root != NULL)
    {
        Qs[root->data]++;
        root = root->next;
    }

    long long re = 0;
    int a;
    cin >> a;

    int wasd;
    for (int i = 0; i <= a / 2; i++)
    {

        if (a - i == i)
            re += (Qs[i] * (Qs[i] - 1)) / 2;
        else
            re += (Qs[i]) * (Qs[a - i]);
    }
    cout << re << " ways";
}