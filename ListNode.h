//
// Created by Administrator on 2020/6/15.
//

#ifndef STUDENTBIRTHDAY_LISTNODE_H
#define STUDENTBIRTHDAY_LISTNODE_H

template<typename T>
class ListNode {
private:
    ListNode<T> *pre, *suc;
    T data;

public:
    ListNode();

    ListNode<T> *getPre();

    ListNode<T> *getSuc();

    T getData();

    void setPre(ListNode<T> *node);

    void setSuc(ListNode<T> *node);

    void setData(T DATA);

};

template<typename T>
T ListNode<T>::getData() {
    return this->data;
}

template<typename T>
ListNode<T> *ListNode<T>::getPre() {
    return this->pre;
}

template<typename T>
ListNode<T> *ListNode<T>::getSuc() {
    return this->suc;
}

template<typename T>
void ListNode<T>::setPre(ListNode<T> *node) {
    this->pre = node;
}

template<typename T>
void ListNode<T>::setSuc(ListNode<T> *node) {
    this->suc = node;
}

template<typename T>
void ListNode<T>::setData(T DATA) {
    this->data = DATA;
}

template<typename T>
ListNode<T>::ListNode() {
    pre = suc = nullptr;
    data = 0;
}

#endif //STUDENTBIRTHDAY_LISTNODE_H
