#include "dictionary.h"
#include "matrix.h"

template<class T1, class T2>
class Pair
{
private:
    T1 elem1;
    T2 elem2;
public:
    Pair = default;
    Pair(T1 elem1, T2 elem2)
    {
        this->elem1 = elem1;
        this->elem2 = elem2;
    }
    ~Pair() = default;
    T1 getFirst() const
    {
        return this->elem1;
    }
    T2 getSecond() const
    {
        return this->elem2;
    }
    void setFirst(T1 elem1)
    {
        this->elem1 = elem1;
    }
    void setSecond(T2 elem2)
    {
        this->elem2 = elem2;
    }
    bool operator<(const Pair another)
    {
        if (this->elem1 != another.elem1)
            return this->elem1 < another.elem1;
        else return this->elem2 < another.elem2;
    }
    bool operator>(const Pair another)
    {
        if (this->elem1 != another.elem1)
            return this->elem1 > another.elem1;
        else return this->elem2 > another.elem2;
    }
    bool operator<=(const Pair another)
    {
        return this->elem1 <= another.elem1;
    }
    bool operator>=(const Pair another)
    {
        return this->elem1 >= another.elem1;
    }
    bool operator!=(const Pair another)
    {
        if (this->elem1 != another.elem1)
            return this->elem2 != another.elem2;
        else return false;
    }
    bool operator==(const Pair another)
    {
        if (this->elem1 == another.elem1)
            return this->elem2 == another.elem2;
        else return false;
    }
};
template <class T1, class T2>
std::ostream& operator<< (std::ostream &out, const Pair<T1, T2> pair)
{
    return out << "(" << pair.getFirst() << "; " << pair.getSecond() << ")";
}

template <class T>
class SparseMatrix
{
private:
    Dictionary<Pair<int, int>, T> *dict;
    int rows = 0;
    int columns = 0;
public:
    SparseMatrix(Matrix m)
    {
        this->rows = m.GetRows();
        this->columns = m.GetColumns();
        this->dict = new Dictionary<Pair<int, int>, T>();
        for (int i = 0; i < m.GetRows(); i++)
        {
            for (int j = 0; j < m.GetColumns(); i++)
            {
                this->set(i, j, m.Get(i, j));
            }
        }
    }
    SparseMatrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        this->dict = new Dictionary<Pair<int, int>, T>();
    }
    ~SparseMatrix() = default;
    void set(int x, int y, T value)
    {
        this->set(Pair<int, int>(x,y), value);
    }
    void set(Pair<T, T> pair, T value)
    {
        if (pair.getFirst() >= this->rows or pair.getSecond() >= this->columns)
        {
            throw std::out_of_range("OUT OF RANGE");
        }
        if (value != (T)0)
            this->dict->add(pair value);
    }
    void setToZero(int x, int y)
    {
        this->setToZero(Pair<int, int>(x,y));
    }
    void setToZero(Pair<T, T> pair)
    {
        if (pair.getFirst() >= this->rows or pair.getSecond() >= this->columns)
        {
            throw std::out_of_range("OUT OF RANGE");
        }
        this->dict->remove(pair);
    }
    bool isNotZero(int x, int y)
    {
        return this->isNotZero(Pair<int,int>(x,y));
    }
    bool isNotZero(Pair<T, T> pair)
    {
        return this->dict->containsKey(pair)
    }
    T get(int x, int y)
    {
        if (x >= this->rows or y >= this->columns)
        {
            throw std::out_of_range("OUT OF RANGE");
        }
        Pair<int, int> pair = Pair(x, y);
        if (this->isNotZero(pair))
        {
            return this->dict->get(pair);
        } else return (T)0;
    }
    int getAmountOfNonZero()
    {
        return dict->getCount();
    }
    int getRows()
    {
        return this->rows;
    }
    int getColumns()
    {
        return this->columns;
    }
    void setRows(int a)
    {
        this->rows = a;
    }
    void setColumns(int a)
    {
        this->columns = a;
    }
};
