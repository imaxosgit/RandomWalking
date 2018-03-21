#ifndef PAIR
#define PAIR

template<class T>
class Pair {
    T first, second;

public:
    Pair(T _first,T _second) {
        first = _first;
        second = _second;
    }

    T getFirst() const { return first; }
    T getSecond() const { return second; }

    void setFirst(const T &newFirst) { first = newFirst; }
    void setSecond(const T &newSecond) { second = newSecond; }

};

#endif // PAIR

