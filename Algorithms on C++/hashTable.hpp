// Интерфейс хеш-таблицы
#include <vector>

// Хеш-функция
template<class T>
int Hash (T& data);

// Элемент цепочки в хеш-таблице
template<class T>
struct CHashTableNode {
  T Data;
  CHashTableNode<T>* Next;
};

// Хеш-таблица
template<class T>
class CHashTable {
  public: 
    CHashTable( int initialSize );
    bool Has( T& key ) const;
    void Add( T& key );
    bool Delete( T& key );
  private:
    std::vector<CHashTableNode<T>*> table;  
};