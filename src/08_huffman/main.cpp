#include <bits/stdc++.h>
using namespace std;


struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    
    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}


Node* buildHuffmanTree(const string& text, unordered_map<char, string>& huffmanCode) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top();
    generateCodes(root, "", huffmanCode);
    return root;
}


string encode(const string& text, unordered_map<char, string>& huffmanCode) {
    string encoded;
    for (char ch : text)
        encoded += huffmanCode[ch];
    return encoded;
}


string decode(Node* root, const string& encoded) {
    string decoded;
    Node* curr = root;

    for (char bit : encoded) {
        curr = (bit == '0') ? curr->left : curr->right;

        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    string text = "BCCABBDDAECCBBAEDDCC";

    unordered_map<char, string> huffmanCode;
    Node* root = buildHuffmanTree(text, huffmanCode);

    cout << "codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << ": " << pair.second << '\n';

    string encoded = encode(text, huffmanCode);
    cout << "encoding: " << encoded << "\n";

    string decoded = decode(root, encoded);
    cout << "decoding: " << decoded << "\n";

    return 0;
}
