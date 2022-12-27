#include <climits>
#include <iostream>
#include <vector>
using namespace std;

string str2;

class leaf {
public:
    char element;
    int priority;
    leaf *left;
    leaf *right;
    leaf *next;

    leaf(char element, int priority) {
        this->element = element;
        this->priority = priority;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class hufftree {
public:
    leaf *head;

    hufftree() {
        head = NULL;
    }

    void add(char value, int priority) {
        leaf *node = new leaf(value, priority);

        if (head == NULL) {
            head = node;
            return;
        }
        leaf *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }

    void add(leaf *node) {
        if (head == NULL) {
            head = node;
            return;
        }
        leaf *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }

    leaf *remove() {
        if (head == NULL) {
            return NULL;
        }
        int largest = INT_MAX;
        leaf *temp = head;

        while (temp != NULL) {
            if (temp->priority < largest)
                largest = temp->priority;
            temp = temp->next;
        }

        temp = head;
        while (temp->priority != largest)
            temp = temp->next;

        removefrom_q(temp);
        return temp;
    }

    void removefrom_q(leaf *delete1) {
        if (head == delete1) {
            head = head->next;
            return;
        }
        leaf *temp = head;
        while (temp->next != delete1)
            temp = temp->next;
        temp->next = delete1->next;
        delete1->next = NULL;
    }

    int counter() {
        leaf *temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void maketree() {
        while (counter() > 1) {
            leaf *left = remove();
            leaf *right = remove();
            leaf *newleaf = new leaf('#', left->priority + right->priority);
            newleaf->left = left;
            newleaf->right = right;
            add(newleaf);
        }
    }

    void encrypt(leaf *root, string array) {
        if (root == NULL)
            return;
        if (root->element != '#') {
            str2 += array;
            cout << root->element << ": " << array << endl;
        }
        encrypt(root->left, array + "0");
        encrypt(root->right, array + "1");
    }

    void decrupt(string str2) {
        string decodedString;
        leaf *temp = head;
        for (int i = 0; i < str2.size(); i++) {
            if (str2[i] == '0')
                temp = temp->left;
            else
                temp = temp->right;

            if (temp->left == NULL && temp->right == NULL) {
                for (int i = 0; i < temp->priority; i++)
                    decodedString += temp->element;
                temp = head;
            }
        }
        cout << "decruptd string: " << decodedString;
    }
};

int main() {
    hufftree q;
    q.add('A', 45);
    q.add('B', 13);
    q.add('C', 12);
    q.add('D', 16);
    q.add('E', 9);
    q.add('F', 5);
    q.maketree();
    cout << "hufftree Codes for each character: " << endl;
    q.encrypt(q.head, "");
    cout << "encryptd string: " << str2 << endl;
    q.decrupt(str2);
    return 0;
}
