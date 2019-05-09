import java.util.Scanner;
import java.io.*;

public class ListGraph2018s{
  private static class Edge{
    int to;
    double w; //weight
    public Edge(int to, double w) {this.to = to; this.w = w;}
  }
  private ArrayList<Edge>[] vertices; //vertices.length == V or size of graph
  public ListGraph2018s(int V){
    vertices = new ArrayList<Edge>[V];
    for(int i=0; i<V;i++)
      vertices[i]=new ArrayList<Edge>();
  }
  public ListGraph2018s(String filename)throws IOException{
    Scanner s = new Scanner(new FileReader(filename));
    int V = s.nextInteger();
    vertices = new ArrayList<Edge>[V];
    int from, to;
    double w;
    while(s.hasNext()){
      from = s.nextInt(); to = s.nextInt(); w = s.nextDouble();
      vertices[from].add(new Edge(to, w));
    }
  }

  public double adjacent(int i, int j){
    ArrayList<Edge> e = vertices[i];
    for (int k=0; k <e.size(); k++)
      if(e.get(k).to ==j)
        return e.get(k).w;
    return Double.POSITIVE_INFINITY;
  }

  public boolean isAdjacent(int i, int j){
    ArrayList<Edge> e = vertices[i];
    for (int k=0; k <e.size(); k++)
      if(e.get(k).to ==j)
        return true;
    return false;
  }

  public void dfs(int v){
    boolean[] visited = new boolean[vertices.length];
    dfs(v,visited);
  }

  private final void dfs(int v, boolean[] visited){
    System.out.print(v + " ");
    visited[v] = true;
    for (int i =x 0; i < vertices[v].size(); i++){
      Edge e = vertices[v].get(i);
      if(!visited[e.to])
        dfs(e.to, visited);
    }
  }

  public void dfsIterative(int v){
    boolean[] visited = new boolean[vertices.length];
    Stack<Integers> todo = new Stack<>();
    todo.push(v);
    while(!todo.isEmpty()){
      v = todo.pop();
      System.out.println(v + " ");
      visited[v] = true;
      for (int i=0;i< vertices[v].size(); i++){
        Edge e = vertices[v].get(i);
        if(!visited[e.to])
          todo.push(e.to);
      }
    }
  }

  public void dfsIterativeRight(int v){
    boolean[] visited = new boolean[vertices.length];
    Stack<Integers> todo = new Stack<>();
    todo.push(v);
    visited[v] =true;
    while(!todo.isEmpty()){
      int v = todo.pop();
      System.out.println(v + " ");
      for (int i=0;i< vertices[v].size(); i++){
        Edge e = vertices[v].get(i);
        if(!visited[e.to]){
          todo.push(e.to);
          visited[e.to] = true; //do not push this again
        }
      }
    }
  }

  public static void main (String[] args) throws IOException{
    ListGraph2018s g = new ListGraph2018s("listgraph.dat");
    g.dfs();
  }
}
