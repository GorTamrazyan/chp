#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Node 
{
    char character;
    int count;
    Node* left;
    Node* right;

    Node(char c, int co) : character(c), count(co), left(nullptr), right(nullptr) {}
};

bool 
compair(Node* a, Node* b) 
{
    if (a->count == b->count) 
        return a->character < b->character;
    return a->count < b->count;
}

Node* 
buildHuffmanTree(string& text) 
{

    unordered_map<char, int> countsMap;

    for (char c : text)
        countsMap[c]++;

    vector<Node*> nodes;
    for (auto& pair : countsMap)
        nodes.push_back(new Node(pair.first, pair.second));

    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), compair);

        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* newNode = new Node('\0', left->count + right->count);
        newNode->left = left;
        newNode->right = right;

        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
        nodes.push_back(newNode);
    }

    return nodes[0];
}

void 
generateHuffmanCodes(Node* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        huffmanCodes[root->character] = code;
        return;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

string 
encode(string& text, unordered_map<char, string>& huffmanCodes) 
{
    string encoded = "";
    for (char c : text)
        encoded += huffmanCodes.at(c);

    return encoded;
}

string 
decode(Node* root, string& encoded) 
{
    string decoded = "";
    Node* current = root;

    for (char bit : encoded) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;

        if (!current->left && !current->right) {
            decoded += current->character;
            current = root;
        }
    }

    return decoded;
}

int 
main() 
{

    string text;
    cout << "Enter text: ";
    getline(cin, text);

    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman codes: " << endl;
    for (auto& pair : huffmanCodes)
        cout << pair.first << ": " << pair.second << endl;

    string encoded = encode(text, huffmanCodes);
    cout << "Encoded: " << encoded << endl;
    
    string decoded = decode(root, encoded);
    cout << "Decoded: " << decoded << endl;

    return 0;
}