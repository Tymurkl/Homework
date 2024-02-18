#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <sstream>

struct Node {
    int data;
    Node* next;
};

unsigned int uniqueWordsCount(const std::string& line) {
    std::set<std::string> uniqueWords;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

std::string mostOccuredWord(const std::string& line) {
    std::map<std::string, int> wordFrequency;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
        wordFrequency[word]++;
    }

    std::string mostOccurredWord;
    int maxFrequency = 0;

    for (const auto& pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostOccurredWord = pair.first;
        }
    }

    return mostOccurredWord;
}

bool isBalanced(const std::string& expression) {
    std::stack<char> brackets;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty()) {
                return false;
            }

            char openBracket = brackets.top();
            brackets.pop();

            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '[')) {
                return false;
            }
        }
    }

    return brackets.empty();
}

bool has_cycle(Node* head) {
    if (!head) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    std::string line = "Hello Hey Hello Bye Hey";
    std::cout << "Unique Words Count: " << uniqueWordsCount(line) << std::endl;
    std::cout << "Most Occurred Word: " << mostOccuredWord(line) << std::endl;

    std::string expression1 = "{[()]}" ;
    std::string expression2 = "[{]}";
    std::cout << "Expression 1: " << (isBalanced(expression1) ? "OK" : "NOT OK") << std::endl;
    std::cout << "Expression 2: " << (isBalanced(expression2) ? "OK" : "NOT OK") << std::endl;


    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = head; // Встановлення циклу

    std::cout << "Has Cycle: " << (has_cycle(head) ? "Yes" : "No") << std::endl;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
