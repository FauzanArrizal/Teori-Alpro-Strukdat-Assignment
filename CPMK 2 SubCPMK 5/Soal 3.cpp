#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    char val;
    ListNode* next;
};

void push(ListNode** head, char val) {
    ListNode* newNode = new ListNode;
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* slow = head;
    stack<char> s;

    while (slow != NULL) {
        s.push(slow->val);
        slow = slow->next;
    }

    while (head != NULL) {
        if (head->val != s.top()) {
            return false;
        }
        s.pop();
        head = head->next;
    }

    return true;
}

int main() {
    ListNode* head = NULL;
    string input;

    cout << "Masukkan sebuah string: ";
    getline(cin, input); // Menerima input string dari pengguna

    for (char ch : input) {
        push(&head, ch);
    }

    printList(head);

    if (isPalindrome(head)) {
        cout << "String tersebut adalah Palindrom." << endl;
    } else {
        cout << "String tersebut BUKAN Palindrom." << endl;
    }

    return 0;
}