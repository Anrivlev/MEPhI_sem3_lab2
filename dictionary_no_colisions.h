#include "sequence.h"


template <class TKey, class TElement>
class Dictionary
{
protected:

    BinaryTree<PairKE<TKey, ArraySequence<TElement>>>* dict;

public:
    Dictionary(const TKey key, const ArraySequence<TElement> elem, bool (*cmp)(PairKE<TKey, ArraySequence<TElement>>, PairKE<TKey, ArraySequence<TElement>>))
    {
        PairKE<TKey, TElement> spair = PairKE<TKey, ArraySequence<TElement>>(key, elem);
        this->dict = new BinaryTree<PairKE<TKey, ArraySequence<TElement>>>(spair, cmp);
    }
    ~Dictionary() = default;
    int getCount()
    {
        return this->dict->getSize();
    }
    TElement get(TKey key)
    {
        PairKE<TKey, ArraySequence<TElement>> spair = PairKE<TKey, ArraySequence<TElement>>();
        spair.setKey(key);
        if(this->dict->exist(spair))
        {
            return this->dict->getElem(dict->search(spair)).getElem();
        }
        throw std::out_of_range(NO_ELEMENT);
    }
    bool containsKey(TKey key)
    {
        PairKE<TKey, ArraySequence<TElement>> spair = PairKE<TKey, ArraySequence<TElement>>();
        spair.setKey(key);
        return this->dict->exist(spair);
    }
    void add(TKey key, ArraySequence<TElement> element)
    {
        PairKE<TKey, ArraySequence<TElement>> spair = PairKE<TKey, ArraySequence<TElement>>(key, element);
        if(this->dict->exist(spair))
        {
            return;
        }
        this->dict->add(spair);
    }
    void remove(TKey key)
    {
        PairKE<TKey, ArraySequence<TElement>> spair = PairKE<TKey, ArraySequence<TElement>>(key);
        if(this->dict->exist(spair))
        {
            this->dict->erase(spair);
            return;
        }
        throw std::out_of_range(NO_ELEMENT);
    }
    void print()
    {
        this->dict->printAll();
    }
    void showDFS()
    {
        this->dict->showDFS();
    }
    string toString()
    {
        return this->dict->toString();
    }
};