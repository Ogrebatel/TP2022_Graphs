//
// Created by John on 14.12.2022.
//

#ifndef SET_GRAPH_AVL_H
#define SET_GRAPH_AVL_H

#include <iostream>

template<typename T>
struct Node {
    T value;
    int height = 1;
    Node *left;
    Node *right;
    Node *parent;

    Node() = default;
    Node(const Node &other) = default;
    Node(Node &&other) noexcept = default;

    explicit Node(T a) : value(a),
                         height(1),
                         left(nullptr),
                         right(nullptr),
                         parent(nullptr) {}

    Node &operator=(const Node &other) = default;
    Node &operator=(Node &&other) noexcept = default;

    ~Node() = default;
};


template<typename T, typename Comparator = std::less<T>>
class AVL {
public:
    Node<T> *_root;
    size_t _size = 0;
    Comparator cmp;
    Node<T> fictive;

    class iterator;

    AVL();

    template<class InputIterator>
    AVL(InputIterator first, InputIterator last);
    AVL(const std::initializer_list<T> &initList);

    AVL(const AVL &other);
    AVL(AVL &&other) noexcept;

    AVL &operator=(const AVL &other);
    AVL &operator=(AVL &&other) noexcept;

    void insert(const T &value);
    void erase(T value);

    [[nodiscard]] iterator begin() const noexcept;
    [[nodiscard]] iterator end() const noexcept;

    iterator find(T value) const;
    iterator lowerBound(T value) const;

    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;

    ~AVL();

private:

    bool lt(const T &lhs, const T &rhs) const;
    bool eq(const T &lhs, const T &rhs) const;
    bool gt(const T &lhs, const T &rhs) const;

    void fixFictive();

    Node<T> *find(Node<T> *node, const T &value) const;
    Node<T>* lowerBound(Node<T>* node, const T &value) const;

    Node<T> *insert(Node<T> *node, const T &value);
    Node<T> *erase(Node<T> *node, const T &value);

    Node<T> *minValueNode(Node<T> *node) const;
    Node<T> *maxValueNode(Node<T> *node) const;

    int height(Node<T> *node);
    void fixHeight(Node<T> *node);

    Node<T> *rotateRight(Node<T> *OldTop);
    Node<T> *rotateLeft(Node<T> *OldTop);

    int balanceFactor(Node<T> *node);
    Node<T> *balance(Node<T> *p);

    void remove_tree(Node<T> *node);
};

template<typename T, typename Comparator>
AVL<T, Comparator>::AVL() : _root(nullptr), _size(0), cmp(Comparator()), fictive() {}

template<typename T, typename Comparator>
template<class InputIterator>
AVL<T, Comparator>::AVL(InputIterator first, InputIterator last) : AVL() {
    for (auto iter = first; iter != last; ++iter) {
        insert(*iter);
    }
    fixFictive();
}

template<typename T, typename Comparator>
AVL<T, Comparator>::AVL(const std::initializer_list<T> &initList) : AVL(initList.begin(), initList.end()) {}

template<typename T, typename Comparator>
AVL<T, Comparator>::AVL(const AVL &other) : AVL(other.begin(), other.end()) {}

template<typename T, typename Comparator>
AVL<T, Comparator>::AVL(AVL &&other) noexcept: _root(other._root), _size(other._size), cmp(Comparator()), fictive(other.fictive) {}

template<typename T, typename Comparator>
AVL<T, Comparator> &AVL<T, Comparator>::operator=(const AVL &other) {
    if(&other == this){
        return *this;
    }

    remove_tree(_root);
    _size = 0;
    _root = nullptr;
    for (auto &iter: other) {
        insert(iter);
    }
    fixFictive();
    return *this;
}

template<typename T, typename Comparator>
AVL<T, Comparator> &AVL<T, Comparator>::operator=(AVL &&other) noexcept {
    remove_tree(_root);
    _root = other._root;
    _size = other._size;
    fixFictive();
    return *this;
}

template<typename T, typename Comparator>
void AVL<T, Comparator>::insert(const T &value) {
    _root = insert(_root, value);
    fixFictive();
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::insert(Node<T> *node, const T &value) {
    if (!node) {
        ++_size;
        return new Node(value);
    }

    if (gt(node->value, value)) {
        node->left = insert(node->left, value);
        node->left->parent = node;
    }
    if (lt(node->value, value)) {
        node->right = insert(node->right, value);
        node->right->parent = node;
    }

    return balance(node);
}

template<typename T, typename Comparator>
void AVL<T, Comparator>::erase(T value) {
    _root = erase(_root, value);
    fixFictive();
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::erase(Node<T> *node, const T &value) {
    if (node == nullptr)
        return node;

    if (lt(value, node->value)) {
        node->left = erase(node->left, value);

    } else if (gt(value, node->value)) {
        node->right = erase(node->right, value);

    } else {
        if ((node->left == nullptr) && (node->right == nullptr)) {
            delete node;
            --_size;
            node = nullptr;

        } else if ((node->left == nullptr) ^ (node->right == nullptr)) {
            Node<T> *parent = node->parent;
            Node<T> *temp = (node->left ? node->left : node->right);
            *node = *temp;//
            node->parent = parent;
            delete temp;
            --_size;

        } else {
            Node<T> *temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = erase(node->right, temp->value);
        }
    }

    if (node == nullptr)
        return node;

    return balance(node);
}

template<typename T, typename Comparator>
typename AVL<T, Comparator>::iterator AVL<T, Comparator>::begin() const noexcept {
    return iterator(minValueNode(_root) ? minValueNode(_root) : &fictive);
}

template<typename T, typename Comparator>
typename AVL<T, Comparator>::iterator AVL<T, Comparator>::end() const noexcept {
    return iterator(&fictive);
}

template<typename T, typename Comparator>
typename AVL<T, Comparator>::iterator AVL<T, Comparator>::find(T value) const {
    return iterator(find(_root, value) ? find(_root, value) : &fictive);
}

template<typename T, typename Comparator>
typename AVL<T, Comparator>::iterator AVL<T, Comparator>::lowerBound(T value) const {
    return iterator(lowerBound(_root, value) ? lowerBound(_root, value) : &fictive);
}

template<typename T, typename Comparator>
size_t AVL<T, Comparator>::size() const {
    return _size;
}

template<typename T, typename Comparator>
bool AVL<T, Comparator>::empty() const {
    return _size == 0;
}

template<typename T, typename Comparator>
AVL<T, Comparator>::~AVL() {
    remove_tree(_root);
}

template<typename T, typename Comparator>
bool AVL<T, Comparator>::lt(const T &lhs, const T &rhs) const {
    return cmp(lhs, rhs);
}

template<typename T, typename Comparator>
bool AVL<T, Comparator>::eq(const T &lhs, const T &rhs) const {
    return !lt(lhs, rhs) && !lt(rhs, lhs);
}

template<typename T, typename Comparator>
bool AVL<T, Comparator>::gt(const T &lhs, const T &rhs) const {
    return !lt(lhs, rhs) && !eq(lhs, rhs);
}

template<typename T, typename Comparator>
void AVL<T, Comparator>::fixFictive() {
    if(_root){
        fictive.left = fictive.right = _root;
        _root->parent = &fictive;
    }
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::find(Node<T> *node, const T &value) const {
    if (!node) {
        return nullptr;
    }

    if (gt(node->value, value)) {
        return find(node->left, value);
    }
    if (lt(node->value, value)) {
        return find(node->right, value);
    }
    return node;
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::lowerBound(Node<T> *node, const T &value) const {
    if (!node) {
        return nullptr;
    }

    if (lt(node->value, value)){
        return lowerBound(node->right, value);
    }

    if (gt(node->value, value)) {
        Node<T>* tmp = lowerBound(node->left, value);
        if (tmp){
            return tmp;
        } else {
            return node;
        }
    }
    return node;
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::minValueNode(Node<T> *node) const {
    if (!node)
        return node;
    while (node->left) {
        node = node->left;
    }
    return node;
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::maxValueNode(Node<T> *node) const {
    if (!node)
        return node;
    while (node->right) {
        node = node->right;
    }
    return node;
}

template<typename T, typename Comparator>
int AVL<T, Comparator>::height(Node<T> *node) {
    return node ? node->height : 0;
}

template<typename T, typename Comparator>
void AVL<T, Comparator>::fixHeight(Node<T> *node) {
    node->height = ((height(node->right) > height(node->left)) ?
                    height(node->right) : height(node->left)) + 1;
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::rotateRight(Node<T> *OldTop) {
    Node<T> *newTop = OldTop->left;
    OldTop->left = newTop->right;
    newTop->right = OldTop;

    fixHeight(OldTop);
    fixHeight(newTop);

    newTop->parent = OldTop->parent;
    OldTop->parent = newTop;
    if (OldTop->left) {
        OldTop->left->parent = OldTop;
    }
    return newTop;
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::rotateLeft(Node<T> *OldTop) {
    Node<T> *newTop = OldTop->right;
    OldTop->right = newTop->left;
    newTop->left = OldTop;

    fixHeight(OldTop);
    fixHeight(newTop);

    newTop->parent = OldTop->parent;
    OldTop->parent = newTop;
    if (OldTop->right) {
        OldTop->right->parent = OldTop;
    }
    return newTop;
}

template<typename T, typename Comparator>
int AVL<T, Comparator>::balanceFactor(Node<T> *node) {
    return (height(node->right) - height(node->left));
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::balance(Node<T> *p) {
    fixHeight(p);
    if (balanceFactor(p) == 2) {
        if (balanceFactor(p->right) < 0)
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }

    if (balanceFactor(p) == -2) {
        if (balanceFactor(p->left) > 0)
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p;
}

template<typename T, typename Comparator>
void AVL<T, Comparator>::remove_tree(Node<T> *node) {
    if (node == nullptr) {
        return;
    }
    remove_tree(node->left);
    remove_tree(node->right);
    delete node;
}

template <typename T, typename Comparator>
class AVL<T, Comparator>::iterator {
public:
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::bidirectional_iterator_tag;

    iterator() noexcept;

    explicit iterator(const Node<T> *node) noexcept;

    const iterator &operator++() noexcept;
    const iterator operator++(int) noexcept;

    const iterator &operator--() noexcept;
    const iterator operator--(int) noexcept;

    bool operator!=(const iterator &other) const noexcept;
    bool operator==(const iterator &other) const noexcept;

    const T &operator*() const noexcept;
    const T *operator->() const;

private:
    const Node<T> *current_node;

    Node<T> *minValueNode(Node<T> *node) const;

    Node<T> *maxValueNode(Node<T> *node) const;
};

template<typename T, typename Comparator>
AVL<T, Comparator>::iterator::iterator() noexcept: current_node(nullptr) {}

template<typename T, typename Comparator>
AVL<T, Comparator>::iterator::iterator(const Node<T> *node) noexcept: current_node(node) {}

template<typename T, typename Comparator>
const typename AVL<T, Comparator>::iterator &AVL<T, Comparator>::iterator::operator++() noexcept {
    Node<T> *tmp;
    if ((tmp = minValueNode(current_node->right)) != nullptr) {
        current_node = tmp;
        return *this;
    }
    while ((current_node->parent != nullptr)
           && current_node->parent->right == current_node) {
        current_node = current_node->parent;
    }
    if(current_node->parent != nullptr)
        current_node = current_node->parent;
    return *this;
}

template<typename T, typename Comparator>
const typename AVL<T, Comparator>::iterator AVL<T, Comparator>::iterator::operator++(int) noexcept {
    iterator tempIter = *this;
    ++*this;
    return tempIter;
}

template<typename T, typename Comparator>
const typename AVL<T, Comparator>::iterator &AVL<T, Comparator>::iterator::operator--() noexcept {
    Node<T> *tmp;
    if ((tmp = maxValueNode(current_node->left)) != nullptr) {
        current_node = tmp;
        return *this;
    }
    while ((current_node->parent != nullptr)
           && current_node->parent->left == current_node) {
        current_node = current_node->parent;
    }
    current_node = current_node->parent;
    return *this;
}

template<typename T, typename Comparator>
const typename AVL<T, Comparator>::iterator AVL<T, Comparator>::iterator::operator--(int) noexcept {
    iterator tempIter = *this;
    --*this;
    return tempIter;
}

template<typename T, typename Comparator>
bool AVL<T, Comparator>::iterator::operator!=(const AVL<T, Comparator>::iterator &other) const noexcept {
    return current_node != other.current_node;
}

template<typename T, typename Comparator>
bool AVL<T, Comparator>::iterator::operator==(const AVL<T, Comparator>::iterator &other) const noexcept {
    return current_node == other.current_node;
}

template<typename T, typename Comparator>
const T &AVL<T, Comparator>::iterator::operator*() const noexcept {
    return current_node->value;
}

template<typename T, typename Comparator>
const T *AVL<T, Comparator>::iterator::operator->() const {
    return &current_node->value;
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::iterator::minValueNode(Node<T> *node) const {
    if (!node)
        return node;
    while (node->left) {
        node = node->left;
    }
    return node;
}

template<typename T, typename Comparator>
Node<T> *AVL<T, Comparator>::iterator::maxValueNode(Node<T> *node) const {
    if (!node)
        return node;
    while (node->right) {
        node = node->right;
    }
    return node;
}

#endif //SET_GRAPH_AVL_H
