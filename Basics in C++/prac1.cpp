#include <iostream>
using namespace std;

#define V 4
void bfs(int graph[V][V],int start,int end)
{
	bool visited[V]={false};
	int parent[V],i;
	for (i=0;i<V;i++)
	parent[i]= -1;
	
	int queue[V], rear=0 ,front=0;
	visited [start]= true;
	queue[rear++]= start;
	
	while(front<rear)
	{
		int curr = queue[front++];
		cout << curr << "";
		
		for (i =0;i< V;i++)
		{
			if (graph[curr][i]== 1 && !visited[i])
			{
				visited[i]= true;
				parent[i]= curr;
				queue[rear++]= i;
				
			}
		}
	}
	cout << "\nShortest path from " << start << " to " << end << ": ";
	
	int path[V],j,idx=0;
	for (j=end ; j!= -1 ; j=parent[j])
	path[idx++]= j;
		
	for (i= idx-1; i>=0;i--)
	cout << path[i] << " ";
}
int main(){
	int graph[V][V]={
	{0,1,0,1}, // A
        {1,0,1,0}, // B
        {0,1,0,1}, // C
        {1,0,1,0} // D
};
bfs (graph, 0, 3);
return 0;
}
