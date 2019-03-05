public class LinkedListV2 {
  private static class Node { //LinkedList.Node
    int v;
    Node next;
    public Node(int v, Node n){
      this.v = v;
      next = n;
    }
  }

  private Node head;
  public LinkedListV2(){
    head = null;
  }

  public void addEnd(int v){
    Node p;
    if (head == null){
      addStart(v);
      return;
    }
    //invariant: head is not null, list has at least 1 element
    for (p=head; p.next !=null; p=p.next)
      //p is not in scope
      //p =null
    ;
    p.next = new Node(v, null);

  }

  public void addStart(int v){
    head = new Node(v, head); //still four units of work 
  }

  public void removeEnd(){
    if (head == null)
      return; //idk what to here so just exit
    if (head.next == null){
      head = null;
      return;
    }
    //invariant: there are at least 2 elements
    Node p,q;
    for (p=head, q= p.next; q.next !=null; p = q, q = q.next)
      ;
    p.next = null;
  }

  public void removeStart(){
    head = head.next;
  }
  public String toString() {
    StringBuilder b = new StringBuilder();

    for (Node p=head; p!=null; p=p.next)
      b.append(p.v).append(' ');
    return b.toString();
  }

  public static void main(String[] args){
    LinkedListV2 a = new LinkedListV2();
    for (int i = 10; i >0; i--)
      a.addStart(i); //numbers going backward but you also build backward
    System.out.println(a);
  }
}
