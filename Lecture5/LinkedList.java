public class LinkedList {
  private static class Node { //LinkedList.Node
    int v;
    Node next;
  }

  private Node head;
  public LinkedList(){
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
    Node temp = new Node();
    temp.v = v;
    temp.next = null;
    p.next = temp;

  }

  public void addStart(int v){
    Node temp = new Node();
    temp.v =v;
    temp.next = head;
    head = temp;
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
    LinkedList a = new LinkedList();
    for (int i = 10; i >0; i--)
      a.addStart(i); //numbers going backward but you also build backward
    System.out.println(a);
  }
}
