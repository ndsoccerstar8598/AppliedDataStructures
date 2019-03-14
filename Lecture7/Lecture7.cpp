/*  Trees: Will only be learning about Binary and RB trees
    RB Trees will not be tested

    Binary Tree:
      root: start of the Treee
      every node has AT MOST 2 Children
      nodes with NO children = leaf nodes
      branches cannot rejoin\

      At best Binary Trees are O(log n)
        This will happen only if the tree is balanced
      At worst Binary Trees are O(n^2)
        This will happen when the numbers are added to the tree in sorted order

                    3
                  /   \
                1      4
              /  \   / \
            1           5
      InOrder: Left,Self,Right (1,1,3,4,5)
      inorder(node n){
        if n.left != null
          inorder(n.left)
        print (val)
        if n.right != null
          inorder(n.right)
      }

      inorder(node n){
        if n==null
          return
        inorder(n.left)
        print val
        inorder(n.right)
      }
      PreOrder: Self, Left, Right
      preorder(node n){
        print (val)
        if n.left != null
          inorder(n.left)
        if n.right != null
          inorder(n.right)
      }

      inorder(node n){
        if n==null
          return
        print val
        inorder(n.left)
        inorder(n.right)
      }
      PostOrder: Left,Right,Self
      preorder(node n){
        if n.left != null
          inorder(n.left)
        if n.right != null
          inorder(n.right)
        print (val)
      }

      inorder(node n){
        if n==null
          return
        inorder(n.left)
        inorder(n.right)
        print val
      }
--------------------------------------------------------------------------------
    Red Black Trees
      Add an extra bit of either true or false (red or black )
      These suck butt
--------------------------------------------------------------------------------
    Trie
     3 Tasks:
      1. Insert a Word
      2. Is this word in the dictionary?
      3. Are there any words that start with this in the dictionary

      class Trie {
      private:
        class Node {
     		 Node* next[26];
     		  bool isWord;
  	    }

  	    Node root;
      public:
  	   Trie( ) { // set up the empty trie root contains all null pointers }
  	   insert(word){ //O(k) where k is the length of the word
  		   Node* p = root
  		   for i ← 0 to length(word)
         if (p.next( word[i] ) == null)
          p.next[word[i] ] = new Node()
          p = p.next[word[i]]
         }
         p.isWord ← true
       }

       boolean ← contains(word) {
        Node* p ← root
	      for i ← 0 to length (word)
          if p.next[ word[i] ] == null
		        return false
          end
          p← p.next[ word[i] ]
        end
		    return p.isWord
	     end

       containsPrefix(word)		return true is word starts with “CATA”
		     Node* p ← root
		     for i ← 0 to length (word)
          if p.next[ word[i] ] == null
		        return false
          end
          p← p.next[ word[i] ]
        end
		    return true
	     end



*/
