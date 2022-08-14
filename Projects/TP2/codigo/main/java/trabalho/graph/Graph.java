package trabalho.graph;

import java.util.*;
import java.util.stream.Collectors;

public class Graph implements Cloneable{
  private Integer size;
  private Integer maxFlow;
  private Boolean isDirected;
  private List<Node> nodes;

  public Graph(Integer size, Boolean isDirected){
    this.size = size;
    this.maxFlow = 0;
    this.isDirected = isDirected;
    this.nodes = new ArrayList<>();
  }

  public Graph(Graph g){
    this.size = g.getSize();
    this.isDirected = g.isDirected();
    this.nodes = g.getNodes();
  }

  public Boolean isDirected() {
    return isDirected;
  }

  public void addNode(Node node){
    nodes.add(node);
  }

  public List<Node> getNodes(){
    return nodes;
  }

  public void setNodes(Integer size) {
    setSize(size);

    for(int i = 0; i < size; i++){
      nodes.add(new Node());
    }
  }

  public Integer getSize() {
    return size;
  }

  public void setSize(Integer size) {
    this.size = size;
  }

  public Integer getMaxFlow() {
    return maxFlow;
  }

  public void setMaxFlow(Integer maxFlow) {
    this.maxFlow = maxFlow;
  }

  public void addEdge(Integer initial, Integer dest, Integer capacity, Integer duration){
    nodes.get(initial).addEdge(initial, dest, capacity, duration);
  }

  public Edge getEdge(Integer start, Integer target){
    for(Edge edge : nodes.get(start).getAdj()){
      if(edge.getDest().equals(target))
        return edge;
    }

    return null;
  }

  public Boolean hasEdge(Integer start, Integer target){
    return nodes.get(start).getAdj()
      .stream()
      .map(Edge::getDest)
      .toList()
      .contains(target);
  }

  public Boolean bfs(Integer start, Integer target, int[] parent){
    for (Node node : nodes)
      node.setVisited(false);

    List<Integer> queue = new ArrayList<>();// queue of unvisited nodes

    queue.add(start);
    nodes.get(start).setVisited(true);

    while (!queue.isEmpty()) { // while there are still unvisited nodes
      Integer u = queue.remove(0);

      for (Edge edge : nodes.get(u).getAdj()) {
        int child = edge.getDest();

        if (!nodes.get(child).isVisited() && getEdge(u, child).getCapacity() > 0) {
          queue.add(child);
          parent[child] = u;
          nodes.get(child).setVisited(true);

          if(child == target)
            return true;
        }
      }
    }

    return false;
  }

  public Graph transpose(){
    Graph gt = new Graph(size, isDirected);
    gt.setNodes(size);

    List<Edge> allEdges = getNodes().stream()
        .flatMap(n -> n.getAdj().stream())
        .collect(Collectors.toList());

    for(Edge e : allEdges)
      gt.addEdge(e.getDest(), e.getInitial(), e.getCapacity(), e.getDuration());

    return gt;
  }

  @Override
  public Object clone() throws CloneNotSupportedException {
    Graph clone = (Graph)super.clone();

    clone.size = this.size;
    clone.maxFlow = this.maxFlow;
    clone.isDirected = this.isDirected;
    clone.nodes = new ArrayList<>();
    for(Node n : nodes){
      clone.addNode((Node)n.clone());
    }

    return clone;
  }

  public void print(){
    System.out.println("src dst cap dur");
    for(int i = 1; i < size; i++){
      nodes.get(i).print(i);
    }
  }
}
