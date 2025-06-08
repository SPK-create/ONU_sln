#include <iostream>
#include <queue>
using namespace std;

// Узел бинарного дерева для сохранения частот символов
struct TreeNode {
    char ch;
    int freq;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Добавляет узлы в бинарное дерево поиска
TreeNode* insert(TreeNode* root, char ch, int freq) {
    if (!root) return new TreeNode(ch, freq);

    if (ch < root->ch)
        root->left = insert(root->left, ch, freq);
    else if (ch > root->ch)
        root->right = insert(root->right, ch, freq);
    else
        root->freq++; // Если символ уже есть, увеличить его частоту

    return root;
}

// Поиск символа в дереве
TreeNode* find(TreeNode* root, char ch) {
    if (!root) return nullptr;
    if (root->ch == ch) return root;

    if (ch < root->ch)
        return find(root->left, ch);
    return find(root->right, ch);
}

// Построение дерева Хаффмана
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f, HuffmanNode* l = nullptr, HuffmanNode* r = nullptr)
        : ch(c), freq(f), left(l), right(r) {
    }
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};


// Функция обхода дерева частот и добавления узлов в приоритетную очередь
void traverse(TreeNode* node, priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare>& pq) {
    if (!node) return;

    pq.push(new HuffmanNode(node->ch, node->freq));
    traverse(node->left, pq);
    traverse(node->right, pq);
}

// Генерация кодов Хаффмана
void generateCodes(HuffmanNode* root, string code, vector<pair<char, string>>& codes) {
    if (!root) return;
    if (root->ch != '\0')
        codes.emplace_back(root->ch, code);

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Обход готового дерева для визуализации в виде графа (GraphvizOnline)
void TreeTraversal(HuffmanNode* root) {
    if (root->left != nullptr) {
        cout << root->ch << "_" << root->freq << "--" << root->left->ch << "_" << root->left->freq << endl;
        TreeTraversal(root->left);
    }
    if (root->right != nullptr) {
        cout << root->ch << "_" << root->freq << "--" << root->right->ch << "_" << root->right->freq << endl;
        TreeTraversal(root->right);
    }
}

void DecodeMessage(string& str, HuffmanNode* root) {
    HuffmanNode* tmp_root = root;
    cout << "Decoded message is: ";
    for (int i = 0; i < str.size(); i++) {
        //cout << "(" << str[i] << ")"; for debug
        if (str[i] == '0') { // Двигаемся по дереву влево, если это возможно
            tmp_root = tmp_root->left;
            if (tmp_root->left == nullptr || tmp_root->right == nullptr) { //Если дети - нулев. указ., то мы достигли конечной ноды (буквы)
                cout << tmp_root->ch;
                tmp_root = root;
            }
        }
        else { //str[i] = 1 - двигаемся вправо, если это возможно
            tmp_root = tmp_root->right;
            if (tmp_root->left == nullptr || tmp_root->right == nullptr) { //Если дети - нулев. указ., то мы достигли конечной ноды (буквы)
                cout << tmp_root->ch;
                tmp_root = root;
            }
        }
    }
    cout << endl;
}

int main() {
    string text = "BUZHENKO";

    // Создание дерева частот символов
    TreeNode* freqTree = nullptr;
    for (char ch : text) {
        TreeNode* node = find(freqTree, ch);
        if (node)
            node->freq++;
        else
            freqTree = insert(freqTree, ch, 1);
    }

    // Создание очереди для построения дерева Хаффмана
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    traverse(freqTree, pq);

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq, left, right);
        pq.push(parent);
    }

    HuffmanNode* root = pq.top();
    vector<pair<char, string>> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Вывод кодов
    cout << "Huffman codes:\n";
    for (const auto& pair : huffmanCodes)
        cout << pair.first << ": " << pair.second << '\n';

    cout << endl;
    TreeTraversal(root);
    cout << endl;

    cout << "Enter coded message using codes gived upside: " << endl;
    string s;
    cin >> s;
    DecodeMessage(s, root);

    return 0;

}