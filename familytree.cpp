#include <iostream>
using namespace std;

struct tree {
    tree *left;
    tree *right;
    string name, relation;
    int age;
};

tree *create_node() {
    tree *temp = new tree;
    temp->left = NULL;
    temp->right = NULL;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter relation: ";
    cin >> temp->relation;
    cout << "Enter age: ";
    cin >> temp->age;
    return temp;
}

tree *insert(tree *root) {
    char ch;
    do {
        tree *ptr = create_node();
        if (root == NULL) {
            root = ptr;
        } else {
            char dir;
            tree *temp = root;
            while (temp != NULL) {
                cout << "Which direction you want to add(left=l/right=r): ";
                cin >> dir;
                if (dir == 'l') {
                    if (temp->left == NULL) {
                        temp->left = ptr;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else if (dir == 'r') {
                    if (temp->right == NULL) {
                        temp->right = ptr;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
        cout << "Do you want to continue(1/0): ";
        cin >> ch;
    } while (ch == '1');
    return root;
}

void inorder_dis(tree *h) {
    if (h == NULL) {
        return;
    }
    inorder_dis(h->left);
    cout << h->name << "\t" << h->relation << "\t" << h->age << endl;
    inorder_dis(h->right);
}

void preorder_dis(tree *h) {
    if (h == NULL) {
        return;
    }
    cout << h->name << "\t" << h->relation << "\t" << h->age << endl;
    preorder_dis(h->left);
    preorder_dis(h->right);
}

void postorder_dis(tree *h) {
    if (h == NULL) {
        return;
    }
    postorder_dis(h->left);
    postorder_dis(h->right);
    cout << h->name << "\t" << h->relation << "\t" << h->age << endl;
}

void search(tree *root, string name) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }
    if (root->name == name) {
        cout << "Name: " << root->name << endl;
        cout << "Relation: " << root->relation << endl;
        cout << "Age: " << root->age << endl;
        return;
    }
    search(root->left, name);
    search(root->right, name);
}

int main() {
    tree *h = NULL;
    int ch, che;
    string search_name;
    do {
        cout << "1. Insert\n2. Preorder Display\n3. Inorder Display\n4. Postorder Display\n5. Search\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                h = insert(h);
                break;
            case 2:
                cout << "----------------------------------------------" << endl;
                cout << "Preorder Traversal" << endl;
                preorder_dis(h);
                break;
            case 3:
                cout << "----------------------------------------------" << endl;
                cout << "Inorder Traversal" << endl;
                inorder_dis(h);
                break;
            case 4:
                cout << "----------------------------------------------" << endl;
                cout << "Postorder Traversal" << endl;
                postorder_dis(h);
                break;
            case 5:
                cout << "Enter name to search: ";
                cin >> search_name;
                search(h, search_name);
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
        cout << "Do you want to continue (1/0): ";
        cin >> che;
    } while (che == 1);
    return 0;
}
