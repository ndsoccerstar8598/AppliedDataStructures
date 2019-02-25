class BadGrowArray{
  private int[] data;
  private int length;

  public BadGrowArray(){
    data = null;
    len =0;
  }
  public void insertEnd(int v){
    int[] old = data;
    data = new int[len+1];
    for (int i = 0; i < len; i++)
      data[i] = old[i];
    data[len] = v;
  }

  public void insertStart(int v){
    int[] old = data;
    data = new int[len+1];
    data[0]=v;
    for(int i =0; i<len;i++)
      data[i+1] = old[i];
    len++
  }
  public void insert(int i,int v){ //O(n)
    int[] old = data; //O(1)
    data = new int[len+1]; //O(1)
    //The complexity of both the loops below O(n)
    for (int j = 0; j < i; j++)
      data[j] = old[j];
    data[i]=v;
    for (int j = i; j < len;j++)
      data[j+1]=tempj;
    len++;
  }

  int removeStart(){ //O(n)
    int temp = data[0];
    --len;
    for (int i =0; i < len;i++)
      data[i] = data[i+1];
    //this leaks memory because the end memory location is not deallocated
  }

  public int removeEnd(){//O(1)
    int temp = data[len-1];
    len--;
    return temp;
  }

  public int get(int pos){
    return data[pos];
  }
  public int getSize(){//O(1)
    return len;
  }
  public int toString(){
    //StringBuilder b = new StringBuilder();
    //b.append( );
    //return b.toString();
    String s = "";
    for (int i =0; i<length;i++)
      s+=data[i]+ ' ';
    return s; 
  }

  public static void main (String[] args){
    BadGrowArray b = new BadGrowArray();
    final int n = 10;
    for(int i =0; i<n;i++)
      b.insertEnd(i);
    for(int i =0; i<n;i++)
      b.insertStart(i);
    b.insert(5,99);
    System.out.println(b.toString);
  }
}
