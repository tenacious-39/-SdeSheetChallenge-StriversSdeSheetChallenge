void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int V = matrix.size();
	    for(int i = 0; i < V; i++){
	        matrix[i][i] = 0;
	    }
	    
	    for(int k = 0; k < V; k++){
	        for(int i = 0; i < V; i++){
	            for(int j = 0; j < V; j++){
	                if(matrix[i][k] != -1 && matrix[k][j] != -1 && (matrix[i][j] == -1 or matrix[i][j] > matrix[i][k]+matrix[k][j]))
	                    matrix[i][j] = matrix[i][k]+matrix[k][j];
	                
	            }
	        }
	    }
	}
