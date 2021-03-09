#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int num;
    int x;
    int y;
    node *left;
    node *right;
    
    void init(int num, int x, int y)
    {
        this->num = num;
        this->x = x;
        this->y = y;
        this->left = NULL;
        this->right = NULL;
    }
};

int cmp(node a, node b)
{
    if (a.y != b.y)
        return a.y > b.y;
    return a.x < b.x;
}

void add(node *parent, node *child)
{
    if (parent->x < child->x)
    {
        if (parent->right)
            add(parent->right, child);
        else
            parent->right = child;      
    }
    else
    {
        if (parent->left)
            add(parent->left, child);
        else
            parent->left = child;
    }
}

void preorder(node *tmp, vector<int> &v)
{
    v.push_back(tmp->num);
    if (tmp->left)
    {
        preorder(tmp->left, v);
    }
    if (tmp->right)
    {
        preorder(tmp->right, v);
    }
}

void postorder(node *tmp, vector<int> &v)
{
    if (tmp->left)
    {
        postorder(tmp->left, v);
    }
    if (tmp->right)
    {
        postorder(tmp->right, v);
    }
    v.push_back(tmp->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer(2);
    vector<node> tree;
    node n, *head;
    int i;
    
    for (i = 0; i < nodeinfo.size(); i++)
    {
        n.init(i + 1, nodeinfo[i][0], nodeinfo[i][1]);
        tree.push_back(n);
    }
    sort(tree.begin(), tree.end(), cmp);
    head = &tree.front();
    for (i = 1; i < tree.size(); i++)
    {
        add(head, &tree[i]);
    }
    preorder(head, answer[0]);
    postorder(head, answer[1]);
    return answer;
}
