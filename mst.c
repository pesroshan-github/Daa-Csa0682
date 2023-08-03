#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES - 1) / 2)
struct Edge {
int source;
int destination;
int weight;
};
void swap(struct Edge *a, struct Edge *b) {
struct Edge temp = *a;
*a = *b;
*b = temp;
}
void sortByWeight(struct Edge edges[], int numEdges) {
for (int i = 0; i < numEdges; i++) {
for (int j = i + 1; j < numEdges; j++) {
if (edges[i].weight > edges[j].weight) {
swap(&edges[i], &edges[j]);
}
}
}
}

int main() {
int numVertices, numEdges;

printf("Enter the number of vertices: ");
scanf("%d", &numVertices);

printf("Enter the number of edges: ");
scanf("%d", &numEdges);
struct Edge edges[MAX_EDGES];
printf("Enter the source, destination, and weight of each edge:\n");
for (int i = 0; i < numEdges; i++)
{
scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
}
sortByWeight(edges, numEdges);
int parent[MAX_VERTICES];
for (int i = 0; i < numVertices; i++) 
{
parent[i] = i; 
}
int selectedEdges = 0;
int mstWeight = 0;
printf("Minimum Spanning Tree Edges:\n");
for (int i = 0; i < numEdges && selectedEdges < numVertices - 1; i++) 
{
int sourceParent = parent[edges[i].source];
int destinationParent = parent[edges[i].destination];
if (sourceParent != destinationParent) {
printf("%d - %d (Weight: %d)\n", edges[i].source, edges[i].destination, edges[i].weight);
mstWeight += edges[i].weight;
for (int j = 0; j < numVertices; j++) 
{
if (parent[j] == destinationParent) 
{
parent[j] = sourceParent;
}
}
selectedEdges++;
}
}

printf("Total Weight of the Minimum Spanning Tree: %d\n", mstWeight);

return 0;
}
