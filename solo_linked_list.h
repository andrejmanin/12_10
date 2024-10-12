#include <iostream>

using namespace std;

template <typename T>
class Element {
public:
    T _data = NULL;
    Element* _next = nullptr;

    explicit Element(T data) : _data(data) {}
    ~Element() = default;
};

template <typename T>
class List {
    Element<T>* _head;
    Element<T>* _tail;
    int _size;

public:
    List() : _head(nullptr), _tail(nullptr), _size(0) {}
    ~List() {
        Element<T>* temp = _head;
        while (temp != nullptr) {
            temp = temp->_next;
            delete _head;
            _head = temp;
        }
        _tail = nullptr;
    }

    void push_back(T data) {
        Element<T>* temp = new Element<T>(data);
        if (_tail == nullptr) {
            _head = temp;
            _tail = temp;
        } else {
            _tail->_next = temp;
            _tail = temp;
        }
        _size++;
    }

    void push_front(T data) {
        Element<T>* temp = new Element<T>(data);
        if (_head == nullptr) {
            _head = temp;
            _tail = temp;
        } else {
            temp->_next = _head;
            _head = temp;
        }
        _size++;
    }

    void pop_front() {
        if (_head == nullptr) {
            return;
        } else if(_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
        } else {
            Element<T>* temp = _head;
            _head = temp->_next;
            delete temp;
        }
        _size--;
    }

    void pop_back() {
        if(_tail == nullptr) {
            return;
        } else if(_tail == _head) {
            delete _tail;
            _tail = nullptr;
            _head = nullptr;
        } else {
            Element<T>* temp = _head;
            while(temp->_next != _tail) {
                temp = temp->_next;
            }
            delete _tail;
            _tail = temp;
            temp->_next = nullptr;
        }
        _size--;
    }

    void print() {
        if (_head == nullptr) {
            cout << "Empty List" << endl;
        } else {
            Element<T>* temp = _head;
            while (temp != _tail) {
                cout << temp->_data << endl;
                temp = temp->_next;
            }
            cout << _tail->_data << endl;
        }
    }

    void clear() {
        if (_head == nullptr) {
            return;
        } else if(_head == _tail) {
            pop_back();
        } else {
            while (_head != _tail) {
                pop_front();
            }
            delete _tail;
            _tail = nullptr;
            _head = nullptr;
        }
    }
};