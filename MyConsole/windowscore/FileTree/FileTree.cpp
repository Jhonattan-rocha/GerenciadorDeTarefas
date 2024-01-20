#include "FileTree.h"

void FileTree::insert(const std::string& path, bool isDirectory) {
    TrieNode* current = &root;
    size_t start = 0;
    size_t end = path.find('/', start);

    while (end != std::string::npos) {
        std::string directory = path.substr(start, end - start);
        if (current->children.find(directory) == current->children.end()) {
            current->children[directory] = new TrieNode(directory, true);
        }
        current = current->children[directory];
        start = end + 1;
        end = path.find('/', start);
    }

    // Último componente do caminho
    std::string lastComponent = path.substr(start);
    if (current->children.find(lastComponent) == current->children.end()) {
        current->children[lastComponent] = new TrieNode(lastComponent, isDirectory);
    }
}

TrieNode* FileTree::find(const std::string& path) {
    TrieNode* current = &root;
    size_t start = 0;
    size_t end = path.find('/', start);

    while (end != std::string::npos) {
        std::string directory = path.substr(start, end - start);
        if (current->children.find(directory) == current->children.end()) {
            return nullptr; // Diretório não encontrado
        }
        current = current->children[directory];
        start = end + 1;
        end = path.find('/', start);
    }

    // Último componente do caminho
    std::string lastComponent = path.substr(start);
    if (current->children.find(lastComponent) == current->children.end()) {
        return nullptr; // Arquivo/diretório não encontrado
    }

    return current->children[lastComponent];
}

void FileTree::remove(const std::string& path) {
    TrieNode* nodeToRemove = find(path);
    if (nodeToRemove) {
        removeHelper(&root, nodeToRemove, path, 0);
    }
}
