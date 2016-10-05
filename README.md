# ShortestPath

###This is my own implementation of Floyd Warshall shortest path algorithm

###This programs input is a sequence of ints in the following format <br />
number of nodes <br />
number of connections made between nodes <br />
number of queries made
  
  start node <br />
  end node<br />
  weight of path between nodes <br />
    (one set of these per number of connections previously defined)
   
  query start node<br />
  query end node<br />
    (one set of these per number of queries previously defined)
    
###This programs output will be 
  "No Path" <br />
        (if the path doesn't exist)
  
  "cost = 0" <br />
  "START-END"<br />
        (if the start and end node are the same)
  
  "cost = COST_TO_TRAVERS"<br />
  "START-NEXT_NODE-NEXT_NODE-...-END"<br />
        (the total cost and the path from start node and end node if it is neither of the two previous cases)
        
        
###Simple sample input and output (comments will be made in parenthesis and is not part of the input) 
####Input
5 (node count)<br />
4 (number of connections)<br />
3 (number of queires)<br />
2 3 6 (connect of node 2 to node 3 with a weight of 6)<br />
2 4 3 (connect of node 2 to node 4 with a weight of 3)<br />
4 5 2 (connect of node 4 to node 5 with a weight of 5)<br />
3 5 -2 (connect of node 3 to node 5 with a weight of -2)<br />
1 5 (queires path from node 1 to node 5)<br />
2 2 (queires path from node 2 to node 2)<br />
2 5 (queires path from node 2 to node 5)<br />
####Output
No Path (output for queires path from node 1 to node 5)<br />
cost = 0 (output for queires path from node 2 to node 2)<br />
2-2<br />
cost = 4 (output for queires path from node 2 to node 5)<br />
2-3-5<br />



  
