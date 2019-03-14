class RBtree{
private:
  class Node{
  public:
    int val;
    enum Color{red, black};
    Color c;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v, Node* l, Node* r, Node* p): val(v), left(l), right(r), parent(p), c(red){}
  };
  Node* root;
  Node* parent(Node* p){ return p->parent; }
  Node* grandparent(Node* n){
    if(n->parent==nullptr)
      return nullptr;
    return parent(n);
  }
public:
  RBtree(): root(nullptr){}
  void add(int v){
    Node* p = root;
    if (p == nullptr){
      root = new Node(v, nullptr, nullptr, nullptr);
    }
    else{
      do{
        if (v > p->val){
          if(p->right == nullptr){
            p->right = new Node(v, nullptr, nullptr,p);
            fixUpTree(p->right);
            return;
          }
          else{
            p = p->right;
          }
        }
        else{ //Value is less than or equal to p value
          if(p->left == nullptr){
            p->left = new Node(v, nullptr, nullptr,p);
            return;
          }
          else{
            p = p->left;
          }
        }
      } while(p!=nullptr);
    }
  }

  void rotate_left(struct node* n) {
    Node* nnew = n->right;
    Node* p = parent(n);
    //assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
    n->right = nnew->left;
    nnew->left = n;
    n->parent = nnew;
    // handle other child/parent pointers
    if (n->right != nullptr)
      n->right->parent = n;
      if (p != nullptr) // initially n could be the root
      {
        if (n == p->left)
          p->left = nnew;
        else if (n == p->right) // if (...) is excessive
          p->right = nnew;
      }
      nnew->parent = p;
  }

  void rotate_right(struct node* n) {
    Node* nnew = n->left;
    Node* p = parent(n);
    //assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
    n->left = nnew->right;
    nnew->right = n;
    n->parent = nnew;
    // handle other child/parent pointers
    if (n->left != nullptr)
      n->left->parent = n;
      if (p != nullptr) // initially n could be the root
      {
        if (n == p->left)
          p->left = nnew;
        else if (n == p->right) // if (...) is excessive
          p->right = nnew;
      }
      nnew->parent = p;
  }

  void insertFixUpTree(Node* n){
    if (parent(n) == nullptr) {
      n->color = black;
    }
    else if (parent(n)->color == black) {
      return;
    }
    else if (uncle(n) != NULL && uncle(n)->color == red) { //if you have an uncle and his color is red
      case3(n);
    }
    else {
      case4(n);
    }
  }

  void insert_case3(struct node* n)
  {
    parent(n)->color = black; //set your parent to black
    uncle(n)->color = black; //set your uncle to black
    Node* g = grandparent(n);
    g->color = red; //set your grandparent to red
    insertFixUpTree(g);
  }

  void insert_case4(struct node* n)
  {
    struct node* p = parent(n);
    struct node* g = grandparent(n);

    if (n == p->right && p == g->left) {
      rotate_left(p);
      n = n->left;
    } else if (n == p->left && p == g->right) {
      rotate_right(p);
      n = n->right;
    }

    if (n == p->left)
     rotate_right(g);
    else
     rotate_left(g);
    p->color = black;
    if(p != nullptr)
     g->color = red;
    }
  }
};
