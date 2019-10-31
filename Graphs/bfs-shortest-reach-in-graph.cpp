#include <vector>
#include <queue>

class Graph{
public:
    
    // constructor
    // IN: number of vertices
    // initialise adjacency list as a vector of vectors
    Graph(int n): n_vertices(n){
        adj_list.resize(n_vertices, std::vector<int>(0));
        for (unsigned int idx_vertices = 0; idx_vertices < n_vertices; ++idx_vertices){
            adj_list[idx_vertices].push_back(idx_vertices);
        }
    }  // end of constructor
    
    
    // IN: indices of two vertices connected by a single edge
    // add edge to adjacency list
    void add_edge(int u, int v){
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }  // end of add_edge fn
    
    
    // IN: index of start vertex
    // run breadth first search algorithm
    // OUT: STL vector of the distance between each vertex and start vertex
    std::vector<int> shortest_reach(int start){
        // if vertex has not been visited, then let the distance to start vertex be -1
        std::vector<int> dist_from_start(n_vertices, -1);
        
        // the source vertex itself has a distance of 0
        dist_from_start[start] = 0;
        
        // initialise queue and enqueue start vertex
        std::queue<int> q;
        q.push(start);
        
        // queue is not empty as long as all vertices that can be reached from source have not yet been discovered
        while (!q.empty()){
            // dequeue the vertex at the front of the queue
            int discovered_vertex = q.front();
            q.pop();
            
            /*
             for all neighbours of dequeued/discovered vertex that are directly
             connected by an edge, check if neighbour has already been
             discovered/visited before.

             if not already discovered, then update its distance accordingly. Enqueue.
            */
            for (auto vertex_it = adj_list[discovered_vertex].begin()+1; vertex_it != adj_list[discovered_vertex].end(); ++vertex_it){
                if (dist_from_start[*vertex_it] == -1){
                    dist_from_start[*vertex_it] = dist_from_start[discovered_vertex] + 6;
                    q.push(*vertex_it);
                }  // end if
            }  // end for
        }  // end while
        
        // return distance between each vertex and start vertex
        // if a given vertex is not connected to start vertex, its distance remains -1
        return dist_from_start;
    }  // end of shortest_reach fn
    
    
private:
    int n_vertices;
    std::vector<std::vector<int>> adj_list;
};
