#include <iostream>
#include <deque>

template < class T, class Container = std::deque<T>>
class queue
{
public:
    using container_type = Container;
    using value_type = typename container_type::value_type;
    using size_type = typename Container::size_type;
    using reference	= typename Container::reference;
    using const_reference = typename Container::const_reference;
private:
    container_type storage;
public:

    queue() = default;
    queue(std::initializer_list<value_type> _list)
    {
        for(typename std::initializer_list<value_type>::iterator i = _list.begin(); i != _list.end(); ++i)
            storage.push_back(*i);
    }

    reference front()
    {
        return storage.front();
    }
    reference back()
    {
        return storage.back();
    }
    bool empty() const
    {
        return storage.empty();
    }
    size_type size() const
    {
        return storage.size();
    }

    void push(const value_type& value)
    {
        storage.push_front(value);
    }
    void pop()
    {
        storage.pop_front();
    }
    void swap(queue<value_type>& other) noexcept
    {
        queue<value_type> temp;
        temp = other;
        other = *this;
        *this = temp;
    }
};

int main()
{
    queue<int> arr;
    for(int i = 0; i < 10; ++i)
        arr.push(i);
    arr.pop();
    for(int i = 0; i < 10; ++i)
        std::cout << arr.front();
    return 0;
}
