//Check problem description for corner cases:
  //No edges (highly up to problem description - is 0 edges all edges?)
  //Isolated vertices with no connected edges (typically these graphs can still have an Euler tour)

void DFS(vector<vector<int>> &AL,vector<bool>&visited,int v) {
  if (visited[v])
    return;
  else {
    visited[v] = true;
    for (int u : AL[v])
      DFS(AL,visited,u);
  }
}

bool eulerCheck(vector<vector<int>> &AL) {
  //check if an euler tour is possible on undirected graph
  
  //check for even degree
  for (vector<int> v : AL) {
    if (div(v.size(),2).rem == 1)
      return false;
  }

  //check for connected, starting from a vertex with at least one edge.
  vector<bool> visited(AL.size(),false);
  int start;
  for (start=0;AL[start].size()==0;start++) {};
  DFS(AL,visited,start);
  for (int i=0;i<visited.size();i++) {
    if (visited[i] == false && AL[i].size() != 0) //we were unable to reach the vertex and it has an edge attached to it. Therefore the graph is disconnected. If it has no edge attached, while the graph is still not connected to it, this doesn't affect the Euler tour property.
     return false;
  }
  return true;
}


//Should work for directed graph - not fully tested
vector<int> findEulerianTour(vector<vector<int>> &AL,int start) {
  vector<int> stack,result,amountOfUsedConns(AL.size(),0);
  stack.push_back(start);
  while (!stack.empty()){
    int top = stack.back();
    if (amountOfUsedConns[top] == AL[top].size()) {
      stack.pop_back();
      result.push_back(top);
    } else {
      stack.push_back(AL[top][amountOfUsedConns[top]]); //remember indexing
      ++amountOfUsedConns[top];
    }
  }
  //may need to reverse;
  return result;
}


//For undirected, may be TLE depending on judge - not optimised
//Normal algorithm is O(E) but this one is probably O(2*E*logE something like that)
vector<int> findEulerianTour(vector<vector<int>> &AL,int start) {
  vector<int> stack,result,amountOfUsedConns(AL.size(),0);
  stack.push_back(start);
  multiset<pair<int,int>> usedEdges;
  while (!stack.empty()){
    int top = *stack.rbegin();

    //In case we previously used the next edge in the reverse direction
    while (amountOfUsedConns[top] < AL[top].size() && usedEdges.count(pair<int,int>(AL[top][amountOfUsedConns[top]],top)) > 0) {
      usedEdges.erase(usedEdges.find(pair<int,int>(AL[top][amountOfUsedConns[top]],top))); //we've seen the back-edge.  
      amountOfUsedConns[top]++;
    }

    if (amountOfUsedConns[top] >= AL[top].size()) {
      stack.pop_back();
      result.push_back(top);
    } else {
      stack.push_back(AL[top][amountOfUsedConns[top]]); //remember indexing
      if (top != AL[top][amountOfUsedConns[top]])
        usedEdges.insert(pair<int,int>(top,AL[top][amountOfUsedConns[top]]));
      else
        ++amountOfUsedConns[top]; //will be there twice so need to double up - self loop
      ++amountOfUsedConns[top];
    }
  }
  //may need to reverse;
  return result;
}
