#include <memory>
#include <vector>
#include <functional>
#include <iostream>
#include <optional>
#include <stack>
#include <random>

template <typename T>
struct Tree {
    struct Node {
        T value = T{};
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* add(auto&& ... args) {
        storage_.push_back(std::make_unique<Node>(std::forward<decltype(args)>(args)...));
        return storage_.back().get();
    }
    Node* root;
private:
    std::vector<std::unique_ptr<Node>> storage_;
};

using Node = Tree<int64_t>::Node;

// in-order traversal
void in_order(Node* node, const std::function<void(Node*)>& visitor) {
    if (node == nullptr) return;
    in_order(node->left, visitor);
    visitor(node);
    in_order(node->right, visitor);
}

void add_sorted(Tree<int64_t>& tree, Node* node, int64_t value) {
    if (value <= node->value) {
        if (node->left == nullptr)
            node->left = tree.add(value);
        else
            add_sorted(tree, node->left, value);
    }
    else {
        if (node->right == nullptr)
            node->right = tree.add(value);
        else
            add_sorted(tree, node->right, value);
    }
}

void in_order_nonrecursive(Node* root, const std::function<void(Node*)>& visitor) {
    std::stack<Node*> s;
    Node* current = root;
    while (current != nullptr || !s.empty()) {
        // Explore left
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        // Now going back up the left path visit each node, then explore the right child.
        // This works, because the left child was already visited as we go up the path.
        current = s.top();
        s.pop();
        visitor(current);
        current = current->right;
    }
}

int main() {
    Tree<int64_t> tree;
    // Generate a sorted binary tree with 10 nodes
    std::mt19937 gen(0); // change the seed for a different output
    std::uniform_int_distribution<> dist(0, 1000);
    tree.root = tree.add(dist(gen));
    for (int i = 0; i < 9; i++) {
        add_sorted(tree, tree.root, dist(gen));
    }

    // in-order traversal will print the values in sorted order
    in_order(tree.root, [](Node* node) {
        std::cout << node->value << " ";
        });
    std::cout << "\n";
    // stdlibc++: 424 545 549 593 603 624 715 845 848 858 
    // libc++: 9 192 359 559 629 684 707 723 763 835

    // Same output as above
    in_order_nonrecursive(tree.root, [](Node* node) {
        std::cout << node->value << " ";
        });
    std::cout << "\n";
}