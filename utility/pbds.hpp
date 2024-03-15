#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<std::pair<T, __gnu_pbds::null_type>>>
using ordered_set = __gnu_pbds::tree<
    T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update, Alloc>;

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<Key, T>>>
using ordered_map = __gnu_pbds::tree<
    Key,
    T,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update, Alloc>;

// find_by_order(k) returns an iterator to the k-th largest element (counting from zero),
// order_of_key(x) returns the number of items in a set that are strictly smaller than x; or equivlently, the index of the first item greater or equal to x
