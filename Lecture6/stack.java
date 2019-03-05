public class stack{
  private int[] stack;
  private int sp;
  public stack(int n){
    stack = new int[n];
    sp =0;
  }
  public void push(int v){
    stack[sp++] =v;
  }
  public void pop() {
    return stack[--sp];
  }
  public boolean isEmpty(){
    return sp == 0;
  }
}
