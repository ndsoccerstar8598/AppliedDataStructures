public class Perm2019s{
  private int p[];
  private void swap(int i, int j){
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
  }
  public Perm2019s(int N){
    p = new int[N];
    for(int i =0; i <N; i++)
      p[i]=i;
    print();
    perm(N-1);
  }

  public void print(){
    for(int i=0; i< p.length; i++)
      System.out.print(p[i]+ " ");
    System.out.println();
  }

  public void perm(int N){
      if(N==0){
        print();
        return;
      }
      for(int c=0; c<= N; c++){
        swap(c,N);
        perm(N-1);
        swap(c,N);
      }
  }

  public void perm2(int N){
      if(N==0){
        print();
        return;
      }
      for(int c=0; c<= N; c++){
        perm2(N-1);
        swap(c,N);
      }
  }

  public static void main(String[] args){
    Perm2019s p = new Perm2019s(4);
  }
}
