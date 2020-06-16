//
// Created by Administrator on 2020/6/15.
//

#ifndef STUDENTBIRTHDAY_LIST_H
#define STUDENTBIRTHDAY_LIST_H

#include "ListNode.h"

template<typename T>
class List {
private:
    ListNode<T> *head, *trail;
    uint size;

    void extend(ListNode<T> *node);

    void update();

    void setTrail(ListNode<T> *node);

    void setHead(ListNode<T> *node);

public:
    List<T>();

    ListNode<T> *getHead();

    ListNode<T> *getTrail();

    uint getSize();

    void add(T data);

    void insert(T data, uint posi);

    T operator[](unsigned int index);

    List<T> &operator=(List list);

    bool isEmpty();

    ~List();

};

template<typename T>
void List<T>::add(T data) {
    auto *node = new ListNode<T>;
    node->setData(data);
    extend(node);
}

template<typename T>
ListNode<T> *List<T>::getHead() {
    return this->head;
}

template<typename T>
ListNode<T> *List<T>::getTrail() {
    return this->trail;
}

template<typename T>
void List<T>::extend(ListNode<T> *node) {
    if (this->getSize() == 0) {
        this->head = this->trail = node;
    } else {
        this->trail->setSuc(node);
        node->setPre(trail);
        update();
    }
    size++;
}

template<typename T>
List<T>::List() {
    head = trail = nullptr;
    size = 0;
}

template<typename T>
uint List<T>::getSize() {
    return this->size;
}

template<typename T>
T List<T>::operator[](unsigned int index) {
    if (index >= this->getSize() || index < 0)
        return *(new T);
    ListNode<T> *ptr = this->getHead();
    while (index--)
        ptr = ptr->getSuc();
    return ptr->getData();
}

template<typename T>
void List<T>::insert(T data, uint posi) {
    posi--;
    if (posi > this->getSize() || posi < 0)return;

    List<T> newList;
    int index = 0;
    for (; index < posi; index++)
        newList.add((*this)[index]);
    newList.add(data);
    index++;
    for (; index < this->getSize() + 1; index++)
        newList.add((*this)[index - 1]);
    *(this) = newList;
}

template<typename T>
bool List<T>::isEmpty() {
    return this->getSize() == 0;
}

template<typename T>
void List<T>::update() {
    ListNode<T> *ptr = this->getTrail();
    while (ptr->getSuc() != nullptr) {
        this->setTrail(this->getTrail()->getSuc());
        ptr = this->getTrail();
    }
    ptr = this->getHead();
    while (ptr->getPre() != nullptr) {
        this->setHead(this->getHead()->getPre());
        ptr = this->getHead();
    }
}

template<typename T>
void List<T>::setTrail(ListNode<T> *node) {
    this->trail = node;
}

template<typename T>
void List<T>::setHead(ListNode<T> *node) {
    this->head = node;
}

template<typename T>
List<T> &List<T>::operator=(List list) {
    this->head = list.getHead();
    this->trail = list.getTrail();
    this->size = list.getSize();
    return *this;
}

template<typename T>
List<T>::~List() = default;

#endif //STUDENTBIRTHDAY_LIST_H
