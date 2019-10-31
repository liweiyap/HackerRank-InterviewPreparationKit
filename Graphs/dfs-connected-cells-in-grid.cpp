#include <vector>
#include <stack>


// IN: grid of 0s and 1s
// OUT: adjacency list containing an edge for every connected pair of 1s
std::vector<std::vector<int> > createAdjList_Grid(std::vector<std::vector<int> > grid){
    // get dimensions of grid
    int n_rows = grid.size();
    int n_cols = grid[0].size();
    int n_vertices = n_rows * n_cols;
    
    // create new adjacency list
    std::vector<std::vector<int> > adj_list;
    adj_list.resize(n_vertices, std::vector<int>(0));
    
    // fill adjacency list
    for (int idx_row = 0; idx_row < n_rows; ++idx_row){
        for (int idx_col = 0; idx_col < n_cols; ++idx_col){
            // if cell is filled
            if (grid[idx_row][idx_col] == 1){
                // define indices for neighbouring cells
                int lb_row = idx_row == 0 ? 0:idx_row-1;
                int ub_row = idx_row == n_rows-1 ? n_rows-1:idx_row+1;
                int lb_col = idx_col == 0 ? 0:idx_col-1;
                int ub_col = idx_col == n_cols-1 ? n_cols-1:idx_col+1;

                // if neighbouring cells are filled
                for (int nb_row = lb_row; nb_row <= ub_row; ++nb_row){
                    for (int nb_col = lb_col; nb_col <= ub_col; ++nb_col){
                        if (!(idx_row == nb_row && idx_col == nb_col) && grid[nb_row][nb_col] == 1){
                            // add edge to adjacency list
                            adj_list[idx_row*n_cols+idx_col].push_back(nb_row*n_cols+nb_col+1);
                            adj_list[nb_row*n_cols+nb_col].push_back(idx_row*n_cols+idx_col+1);
                        }  // end if (neighbouring cells)
                    }  // end for (neighbouring cells)
                }  //  end for (neighbouring cells)
                
            }  // end if (current cell)
        }  // end for (current cell)
    }  // end for (current cell)
    
    return adj_list;
}  // end of helper fn createAdjList_Grid


// IN: vector of vector representing grid of 0s and 1s
// OUT: number of cells in largest region of 1s in grid
int maxRegion(std::vector<std::vector<int> > grid){
    // get dimensions of grid
    int n_rows = grid.size();
    int n_cols = grid[0].size();
    int n_cells = n_rows * n_cols;

    // call helper fn to create adjacency list for cells in grid
    std::vector<std::vector<int> > adj_list = createAdjList_Grid(grid);
    
    // initialise vector of booleans for whether a cell has been visited before in depth first search algorithm
    std::vector<bool> visited(n_cells, false);
    
    // initialise stack for depth first search
    std::stack<int> s;
    
    int max_value = 1;
    int cur_value;
    
    // run depth first search algorithm: iterate over all cells
    for (int adj_list_it = 1; adj_list_it <= adj_list.size(); ++adj_list_it){
        // set cur_value to minimum
        cur_value = 1;
        
        // if cell has an edge with at least 1 neighbouring cell
        if (adj_list[adj_list_it-1].size() > 0){
            // use the current cell as the source
            int source_vertex = adj_list_it;
            
            // push source cell onto stack
            s.push(source_vertex);
            
            // stack is not empty as long as all cells that can be reached from source have not yet been discovered
            while (!s.empty()){
                // visit cell and pop cell from top of stack
                int discovered_vertex = s.top();
                visited[discovered_vertex-1] = true;
                s.pop();
                
                // iterate over all neighbouring cells that share an edge with current cell
                for (auto vertex_it = adj_list[discovered_vertex-1].begin(); vertex_it != adj_list[discovered_vertex-1].end(); ++vertex_it){
                    // if not visited
                    if (!visited[*vertex_it-1]){
                        // visit and push
                        visited[*vertex_it-1] = true;
                        s.push(*vertex_it);
                        
                        // update cur_value
                        ++cur_value;
                    }  // end if
                }  // end for
            }  // end while
            
        }  // end for
        
        // compare cur_value to max_value. If cur_value is greater than max_value, update.
        max_value = cur_value > max_value ? cur_value : max_value;
    }

    return max_value;
}
