#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node* next;
    Node* prev;

public:
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}

    T& GetData()
    {
        return data;
    }

    void SetData(T data)
    {
        this->data = data;
    }

    Node* GetNext() const
    {
        return next;
    }

    void SetNext(Node* next)
    {
        this->next = next;
    }

    Node* GetPrev() const
    {
        return prev;
    }

    void SetPrev(Node* prev)
    {
        this->prev = prev;
    }
};

template <typename T>
class Stack
{
private:
    Node<T>* top;
    size_t size;

public:
    Stack() : top(nullptr), size(0) {}

    size_t GetSize() const
    {
        return size;
    }

    void Push(const T& data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->SetNext(top);
        top = newNode;
        size++;
    }

    T& Peek()
    {
        if (top == nullptr)
        {
            throw runtime_error("Stack is empty");
        }
        return top->GetData();
    }

    void Pop()
    {
        if (top == nullptr)
        {
            throw runtime_error("Stack is empty");
        }
        Node<T>* temp = top;
        top = top->GetNext();
        delete temp;
        size--;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            Node<T>* temp = top;
            top = top->GetNext();
            delete temp;
        }
    }
};

template <typename T>
class Deque
{
private:
    Node<T>* front;
    Node<T>* rear;
    size_t size;

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}

    size_t GetSize() const
    {
        return size;
    }

    void PushFront(const T& data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->SetNext(front);
        if (front != nullptr)
        {
            front->SetPrev(newNode);
        }
        front = newNode;
        if (rear == nullptr)
        {
            rear = front;
        }
        size++;
    }

    void PushBack(const T& data)
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->SetPrev(rear);
        if (rear != nullptr)
        {
            rear->SetNext(newNode);
        }
        rear = newNode;
        if (front == nullptr)
        {
            front = rear;
        }
        size++;
    }

    T& PeekFront()
    {
        if (front == nullptr)
        {
            throw runtime_error("Deque is empty");
        }
        return front->GetData();
    }

    T& PeekBack()
    {
        if (rear == nullptr)
        {
            throw runtime_error("Deque is empty");
        }
        return rear->GetData();
    }

    void PopFront()
    {
        if (front == nullptr)
        {
            throw runtime_error("Deque is empty");
        }
        Node<T>* temp = front;
        front = front->GetNext();
        if (front != nullptr)
        {
            front->SetPrev(nullptr);
        }
        else
        {
            rear = nullptr;
        }
        delete temp;
        size--;
    }

    void PopBack()
    {
        if (rear == nullptr)
        {
            throw runtime_error("Deque is empty");
        }
        Node<T>* temp = rear;
        rear = rear->GetPrev();
        if (rear != nullptr)
        {
            rear->SetNext(nullptr);
        }
        else
        {
            front = nullptr;
        }
        delete temp;
        size--;
    }

    ~Deque()
    {
        while (front != nullptr)
        {
            Node<T>* temp = front;
            front = front->GetNext();
            delete temp;
        }
    }
};

int main()
{
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(6);
    stack.Push(9);
    stack.Push(123);

    cout << "Stack elements (top to bottom):" << endl;
    while (stack.GetSize() != 0)
    {
        cout << stack.Peek() << endl;
        stack.Pop();
    }

    Deque<int> deque;
    deque.PushBack(10);
    deque.PushFront(20);
    deque.PushBack(30);
    deque.PushFront(40);

    cout << "Deque elements (front to back):" << endl;
    while (deque.GetSize() != 0)
    {
        cout << deque.PeekFront() << endl;
        deque.PopFront();
    }

    return 0;
}
