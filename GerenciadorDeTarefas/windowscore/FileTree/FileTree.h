#ifdef _WIN32

#ifndef TREEFILES_H
#define TREEFILES_H

#include <windows.h>
#include <iostream>
#include <unordered_map>

struct TrieNode {
    std::string name;
    bool isDirectory;
    std::unordered_map<std::string, TrieNode*> children;

    TrieNode(const std::string& n, bool isDir) : name(n), isDirectory(isDir) {}
};

class FileTree {
public:
    static FileTree& getInstance() {
        static FileTree instance;  // A instância é criada apenas na primeira chamada
        return instance;
    }

    FileTree() : root("", true) {}
    void insert(const std::string& path, bool isDirectory);
    TrieNode* find(const std::string& path);
    void remove(const std::string& path);

private:
    TrieNode root;

    void removeHelper(TrieNode* parent, TrieNode* current, const std::string& path, size_t level) {
        // Caso base: Verifica se todos os caracteres do caminho foram processados
        if (level == path.length()) {
            // Marca o nó como não existente (pode ser removido)
            current->name = "";
            return;
        }

        // Obtém o próximo caractere no caminho
        std::string directory = getNextDirectory(path, level);

        // Verifica se o próximo nó no caminho existe
        auto it = current->children.find(directory);
        if (it != current->children.end()) {
            TrieNode* nextNode = it->second;

            // Chama recursivamente para o próximo nível da árvore
            removeHelper(current, nextNode, path, level + directory.length() + 1);

            // Remove o nó se não houver subnós e não for um diretório existente
            if (!nextNode->isDirectory && nextNode->children.empty() && nextNode->name.empty()) {
                current->children.erase(directory);
                delete nextNode;
            }
        }
    }

    std::string getNextDirectory(const std::string& path, size_t& level) {
        size_t end = path.find('/', level);
        if (end == std::string::npos) {
            end = path.length();
        }

        std::string directory = path.substr(level, end - level);
        level = end + 1; // Atualiza o índice para o próximo caractere
        return directory;
    }

};

#endif // TREEFILES_H
#endif
