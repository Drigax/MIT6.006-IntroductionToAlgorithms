#include <iterator>
#include <memory>

#define UNUSED(x) (void)(x)

template<typename T>
class resizable_array_list
{
public:
    resizable_array_list();
    resizable_array_list(std::iterator<T, long, const T*, const T&> begin,
                         std::iterator<T, long, const T*, const T&> end);

    std::iterator<std::bidirectional_iterator_tag,
                T, long, const T*, const T&> 
                begin();
    
    std::iterator<std::bidirectional_iterator_tag,
                T, long, const T*, const T&> 
                end();
    
    T& first();
    T& last();

    void clear();
    
    int count();
    
    T& operator[](int idx);
    const T& operator[](int idx) const;
    
    T& get(int idx);
    void set(int idx, T& val);

    void insert_at(int idx, T& val);
    void delete_at(int idx, T& val);

    void insert_first(T& val);
    void insert_last(T& val);

    void delete_first();
    void delete_last();
    
private:
    std::unique_ptr<T[]> storage;
    
    void resize();
    void resize(long new_item_count, long first_element_offset);

    long storage_size = 5;
    const int resize_factor = 2;
    long item_count = 0;
    
};
