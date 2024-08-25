#include <iterator>
#include <memory>

#define UNUSED(x) (void)(x)

template<typename T>
class resizable_array_list
{
public:
    resizable_array_list();
    resizable_array_list(std::iterator<T, unsigned long, const T*, const T&> begin,
                         std::iterator<T, unsigned long, const T*, const T&> end);

    std::iterator<std::bidirectional_iterator_tag,
                T, unsigned long, const T*, const T&> 
                begin();
    
    std::iterator<std::bidirectional_iterator_tag,
                T, unsigned long, const T*, const T&> 
                end();
    
    T& first();
    T& last();

    void clear();
    
    unsigned long count();
    
    T& operator[](unsigned long idx);
    const T& operator[](unsigned long idx) const;
    
    T& get(unsigned long idx);
    void set(unsigned long idx, T& val);

    void insert_at(unsigned long idx, T& val);
    void delete_at(unsigned long idx, T& val);

    void insert_first(T& val);
    void insert_last(T& val);

    void delete_first();
    void delete_last();
    
private:
    std::unique_ptr<T[]> storage;
    
    void resize();
    void resize(unsigned long new_item_count, unsigned long first_element_offset);

    unsigned long storage_size = 5;
    const unsigned long resize_factor = 2;
    unsigned long item_count = 0;
    
};
