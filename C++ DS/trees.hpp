// Узел двоичного дерева с данными типа int
struct CBinaryNode {
  int Data;
  CBinaryNode* Left; // NULL, если нет
  CBinaryNode* Right; // NULL, если нет
  CBinaryNode* Parent; // NULL, если корень
};

// Узел дерева с произвольным ветвлением
struct CTreeNode {
  int Data;
  CTreeNode* Next; // NULL, если нет следующих
  CTreeNode* First; // NULL, если нет дочерних
  CTreeNode* Parant; // NULL, если корень
};

