#include <cmath>
#include <iostream>
#include <limits>
#include <fstream>
#include <stack>

using namespace std;

constexpr double inf = std::numeric_limits<double>::infinity();
class MatrixGraph{
private:
  int v; //always a square matrix
  double* w;//a for adjacency
public:
  MatrixGraph(int v): v(v){
    w = new double[v*v];
    for(int i=0;i< v*v; i++)
      w[i] = inf;
  }

  void setEdge(int to, int from, double newW){ //since bidirectional we store both r->c and c->r
    w[to * v + from] = newW;
    w[from * v + to] = newW;
  }

  double getW(int from, int to){
    return w[from * v + to];
  }

  friend istream& operator>>(istream& s, MatrixGraph& g){
    s >> g.v;
    string val;
    for(int i=0; i < g.v; i++){
      for(int j=0; j < g.v; j++){
        s >> val;
        if(val == "inf")
          g.setEdge(i,j,inf);
        else
          g.setEdge(i,j,std::stod(val));
      }
    }
  }
  void floydWarshall(){ //O(v^3)
    double* dist = new double[v*v]; //need some sort of matrix here
    for(int i=0; i < v*v; i++)
        dist[i] = w[i]; //puts infinity in the ones that are infinity, and the correct weight for the ones are not infinity
    for(int i=0; i < v; i++)
        dist[i*v+i]=0;
    for(int i=0; i < v; i++)
        for(int j=0; j < v; j++)
            for(int k=0; k < v; k++)
                if(dist[i*v+j] > dist[i*v+k] + dist[k*v+j])
                    dist[i*v+j] = dist[i*v+k] + dist[k*v+j];

    //print the coefficients
    for(int i=0; i < v; i++){
        for(int j=0; j < v; j++){
            cout << dist[i*v+j] << '\t';
        }
        cout << '\n';
    }
    delete [] dist;
  }

  void dfs(int v0){
    bool* planned = new bool[v];
    dfs(v0, planned);
    delete [] planned;
  }

  void dfs(int v0, bool * planned){ //O(v^2)
    stack<int> toVisit;
    for(int i =0; i< v; i++)//O(v)
      planned[i]=false;

    toVisit.push(v0);
    planned[v0] = true;

    while(!toVisit.empty()){
      int v = toVisit.top();
      toVisit.pop();
      cout << v << '\t';
      for(int i =0; i< v; i++)// O(v)
        if(getW(v,i) < inf && !planned[i]){
          toVisit.push(i);
          planned[i]=true;
        }
    }
  }

  bool IsConnected(){ //O(v^2)
    bool* planned = new bool[v];
    dfs(v0, planned);

    bool connected = true;
    for(int i=0;i<v;i++)
      if(planned[i] == false){
        connected = false;
        break;
      }
    delete [] planned;
    return connected;
  }

};

int main(){
  MatrixGraph g(5);
  g.setEdge(1,5,.5);
  g.setEdge(1,4,1.5);
  ifstream f("test.gr");
  f >> g;
  g.floydWarshall(); //we'll just print out
  g.dfs(0); //start from vertex 0
}
