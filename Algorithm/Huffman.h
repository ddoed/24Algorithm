#pragma once

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

namespace EnCoding
{
    // Ʈ�� ��� ����ü ����
    struct Node {
        char ch;           // ����
        int freq;          // �󵵼�
        int char_count;    // �ش� ��带 �����ϴ� ���� ����
        Node* left, * right; // ����, ������ �ڽ� ���

        Node(char ch, int freq, int char_count = 1)
            : ch(ch), freq(freq), char_count(char_count), left(nullptr), right(nullptr) {}
    };

    // �켱���� ť���� ����ϴ� �� �Լ�
    struct Compare {
        bool operator()(Node* left, Node* right) {
            // �󵵰� ���� ���
            if (left->freq == right->freq) {
                // ���� ������ ���� ���� �켱
                if (left->char_count != right->char_count) {
                    return left->char_count > right->char_count;
                }
                // �󵵿� ���� ���� ��� ������ '\0' ��带 ���������� ����
                return left->ch > right->ch;
            }
            // �󵵰� �ٸ� ��� �󵵰� ���� ��尡 �켱
            return left->freq > right->freq;
        }
    };

    // ������ Ʈ������ �ڵ带 �����ϴ� ��� �Լ�
    void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
        if (!root) return;

        // ���� ����� ��� ���ڿ� �ش��ϴ� �ڵ� ���ڿ��� �ʿ� ����
        if (!root->left && !root->right) {
            huffmanCode[root->ch] = str;
        }

        // ���ʿ� 0�� �߰��ϰ� ��� ȣ��
        encode(root->left, str + "0", huffmanCode);
        // �����ʿ� 1�� �߰��ϰ� ��� ȣ��
        encode(root->right, str + "1", huffmanCode);
    }

    // ������ �ڵ� ���� �Լ�
    void buildHuffmanTree(const string& text) {
        // �� ����� ���� ��
        unordered_map<char, int> freq;
        for (char ch : text) {
            freq[ch]++;
        }

        // �켱���� ť�� ����Ͽ� �󵵰� ���� ���ں��� ó��
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (auto pair : freq) {
            pq.push(new Node(pair.first, pair.second));
        }

        // Ʈ�� ���� ���� ����� ����� �߰��Ͽ� Ȯ��
        while (pq.size() > 1) {
            // ���� �󵵰� ���� �� ��带 ����
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();


            // �����: ������ ��� ���
            cout << "Combining nodes: " << (left->ch ? left->ch : '*') << "(" << left->freq << ") and "
                << (right->ch ? right->ch : '*') << "(" << right->freq << ")\n";

            // �� ��带 ���� ���ο� ���� ��带 ���� (���� ���� ����)
            int sum = left->freq + right->freq;
            int char_count = left->char_count + right->char_count; // �� ����� ���� ���� �ջ�
            Node* newNode = new Node('\0', sum, char_count);
            newNode->left = left;
            newNode->right = right;

            // ���ο� ��带 �켱���� ť�� ����
            pq.push(newNode);
        }

        // ���� Ʈ�� ��Ʈ ���
        Node* root = pq.top();

        // ������ �ڵ� ���� ��
        unordered_map<char, string> huffmanCode;
        encode(root, "", huffmanCode);

        // ������ �ڵ� ���
        cout << "Huffman Codes:\n";
        cout << "���ڿ��� �� ���� : " << root->freq << '\n';
        for (auto pair : huffmanCode) {
            cout << pair.first << " " << pair.second << "\n";
        }
    }
    void Test() {
        string text = "APPLEBANANAMANGOJUICE";
        buildHuffmanTree(text);
    }
}
