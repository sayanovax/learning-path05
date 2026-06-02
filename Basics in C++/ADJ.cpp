#include <iostream>
using namespace std;
class Graph{
	private:
		int vertices;
		int **adjMatrix;
		bool isDirected;
	public:
		Graph(int v, bool directed = false){
			vertices = v;
			isDirected = directed;
			adjMatrix = new int*[vertices];
			for (int i = 0; i < vertices; ++i){
				adjMatrix[i] = new int[vertices];
				for (int j=0; j<vertices; ++j){
					adjMatrix[i][j]=0;
				}
			}
			
		}
	void addEdge(int i,int j){
             adjMatrix[i][j]=1;
             if(!isDirected){
	        adjMatrix[j][i]=1;
	     }
	}	
	void display(){
		cout<<"Adjacency Matrix:\n";
		for (int i=0; i<vertices; ++i){
			for (int j=0; j<vertices; ++j){
				cout<<adjMatrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	~Graph() {
		for (int i=0; i<vertices; ++i){
			delete[]
			adjMatrix[i];
		}
		delete[] adjMatrix;
	}
};

int main(){
	int V,E;
	cout<<"Enter number of vertices : ";
	cin>>V;
	Graph g(V);
	cout<<"Enter number of edges : ";
	cin>>E;
	
	cout<<"Enter edges (format: from to):\n";
	for(int i=0; i<E; ++i){
		int from, to;
		cin>>from>>to;
		g.addEdge(from,to);
	}
	g.display();
	return 0;
}

