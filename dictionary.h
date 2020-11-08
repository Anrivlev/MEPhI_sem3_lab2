#pragma once

#include "binary_tree.h"

template<class TKey, class TElement>
class PairKE
{
private:
    TKey key = (TKey)(0);
    TElement element = (TElement)(0);
public:
    PairKE(TKey key, TElement element=(TElement)(0))
    {
        this->key = key;
        this->element = element;
    }
    ~PairKE() = default;
    TElement getElem()
    {
        return this->element;
    }
    TKey getKey()
    {
        return this->key;
    }
    bool operator<(const pairKE a, const pairKE b)
    {
        return a->TKey < b->TKey;
    }
    bool operator>(const pairKE a, const pairKE b)
    {
        return a->TKey > b->TKey;
    }
    bool operator<=(const pairKE a, const pairKE b)
    {
        return a->TKey <= b->TKey;
    }
    bool operator>=(const pairKE a, const pairKE b)
    {
        return a->TKey < b->TKey;
    }
    bool operator!=(const pairKE a, const pairKE b)
    {
        return a->TKey != b->TKey;
    }
    bool operator==(const pairKE a, const pairKE b)
    {
        return a->TKey == b->TKey;
    }
};


template <class TKey, class TElement>
class Dictionary
{
private:

    BinaryTree<PairKE<TKey, TElement>* dict;

public:
    void Dictionary(const TKey key, const TElement elem, bool (*cmp)(T, T))
    {
        this->dict = new BinaryTree<T>(elem, cmp);
    }
    void ~Dictionary() =default;
    int GetCount()
    {
        return this->dict->getSize();
    }
    TElement Get(TKey key)
    {
        PairKE<TKey, TElement> spair = PairKE(key);
        if(this->dict->exist(spair))
        {
            return this->dict->getElem(spair).getElem();
        }
        throw out_of_range(IndexOutOfRangeEx);
    }
    bool ContainsKey(TKey key)
    {
        PairKE<TKey, TElement> spair = PairKE(key);
        return this->dict->exist(spair);
    }
    void Add(TKey key, TElement element)
    {

    }
    void Remove(TKey key)
    {

    }
};