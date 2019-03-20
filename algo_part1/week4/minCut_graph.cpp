#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream> 

struct Vertex {
   int vertex;
   std::vector<int> edges;
   std::vector<int> contracted;
};

struct Edge {
   int v1;
   int v2;
};

struct Graph {
   int vertexCount;
   std::vector<Vertex> vertex_G;
   std::vector<Edge> edge_G;
};

Graph createGraph() {
    std::fstream f;
    f.open("kargerMinCut.txt",std::ios::in);
   //f.open("testCase2.txt",std::ios::in);
    //std::string s = "1       37      79      164     155     32      87      39      113     15      18      78      175     140     200     4       160     97      191     100     91      20      69      198     196";

    //std::string s;
    //getline(f,s);
    Graph g;
    int vertexNum;
    int i ;
    g.vertexCount = 0;
    for(std::string s; std::getline(f,s);){
      std::istringstream str(s);
      Vertex v;
      str >> vertexNum;
      v.vertex = vertexNum;
      while(str >> i) {
           Edge e;
           e.v1 = vertexNum;
           e.v2 = i;
           v.edges.push_back(i);
           if(i > vertexNum) {
             g.edge_G.push_back(e); 
           }
      }
      g.vertex_G.push_back(v);
      g.vertexCount++;     
    }
   //print the values
   /* std::vector<Vertex>::iterator it;
    for(it = g.vertex_G.begin(); it != g.vertex_G.end(); it++) {
       std::cout << it->vertex << "->";
       std::vector<int>::iterator j;
       for(j = it->edges.begin(); j !=  it->edges.end() ; j++) {
          std::cout << *j << "-" ;     
       }
       std::cout << std::endl;
    }
    std::vector<Edge>::iterator ite;
    for (ite = g.edge_G.begin(); ite != g.edge_G.end(); ite++) {
       // std::cout << ite->v1 << " " << ite->v2 << std::endl;
           
    }*/
    return g ;
}
      
void randomContraction(Graph &g) {
   int index = rand() % (g.edge_G.size());
    //std::cout << "index" << " " << index << std::endl;
   Edge randEdge = g.edge_G[index];
   //std::cout << "Random edge: " << randEdge.v1 << "<=>" << randEdge.v2 << " "; 
   //merge v2 in v1 and update the g.edge_G
   int vertV1 =  randEdge.v1;
   int vertV2 =  randEdge.v2;  
   //create a new list of edges,since v2 is merged into v1, v2 in all edges will be replaced by v1
   std::vector<Edge> newEdges;
   
   std::vector<Edge>::iterator it;
   for(it = g.edge_G.begin(); it != g.edge_G.end() ; it++) {
      if(it->v2 == vertV2) {
         it->v2 = vertV1;
      }
      if(it->v1 == vertV2){
         it->v1 = vertV1;
      }
      if(it->v1 != it->v2) {
        newEdges.push_back(*it);
      }
   }
   g.edge_G = newEdges;
   std::vector<Edge>::iterator ite;
   //std::cout << "printing edges for debugging each time" << std::endl;
   /*for (ite = g.edge_G.begin(); ite != g.edge_G.end(); ite++) {
        std::cout << ite->v1 << " " << ite->v2 << "---" ;

    }*/
    //std::cout << std:: endl;
   //modify vertices
   //taking forward v1 and removing v2
   //g.vertex_G[randEdge.v1-1].contracted.push_back(g.vertex_G[randEdge.v1-1].vertex);
   g.vertex_G[randEdge.v2-1].vertex = 0; //removing means making it 0
   //add rest of the items
   g.vertexCount--; 
   //std::cout << "vertexCount : " << g.vertexCount << std::endl;     
}
  

int minCut(Graph &g2) {
   Graph g = g2;
   int min_cut_best =g.edge_G.size();
   std::cout << "Intial min cut best : " << min_cut_best << std::endl;
   int count = g.vertex_G.size() * g.vertex_G.size();
   //int count = 1;
   while(count > 0) {
     g = g2;
     while(g.vertexCount > 2) {
       srand(time(NULL));
       //std::cout << std::endl;
     //  std::cout << "vertexCount : " << g.vertexCount << " Edge count : " << g.edge_G.size() << std::endl;
       randomContraction(g);
     }
     int min_cut = g.edge_G.size();
     std::cout << "Count each time: " << min_cut << std::endl; 
     if( min_cut < min_cut_best) {
       min_cut_best = min_cut;
       std::cout << "Count / Min CUT VALUE : " << count << " " << min_cut_best << std::endl;
     }  
    count--;
   }
   return min_cut_best;
}
       
int main() {

  Graph g = createGraph();
  int minCutValue = minCut(g);
  std::cout << "Min Cut : " << minCutValue << std::endl;

  /*std::vector<Vertex>::iterator it;
    for(it = g.vertex_G.begin(); it != g.vertex_G.end(); it++) {
       std::cout << it->vertex << "->";
    }
    //std::cout << std::endl;
std::vector<Edge>::iterator ite;
    for (ite = g.edge_G.begin(); ite != g.edge_G.end(); ite++) {
       std::cout << ite->v1 << " " << ite->v2 << "/";

    }*/  
    //std::cout << std::endl;
  return 0;
}   
