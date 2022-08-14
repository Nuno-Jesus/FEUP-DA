package trabalho.graph;

import java.util.ArrayList;
import java.util.List;


public class Node implements Cloneable{
  private List<Edge> adj;
  private Boolean visited;

  public Node() {
    this.visited = false;
    this.adj = new ArrayList<>();
  }
  public Node(List<Edge> adj) {
    this.visited = false;
    this.adj = adj;
  }

  public Boolean isVisited() {
    return visited;
  }

  public void setVisited(Boolean visited) {
    this.visited = visited;
  }

  public List<Edge> getAdj() {
    return adj;
  }

  public void addEdge(Integer initial, Integer dest, Integer capacity, Integer duration){
    adj.add(new Edge(initial, dest, capacity, duration));
  }

  public void print(Integer number){
    for(Edge edge : adj){
      System.out.print(number + " ");
      edge.print();
    }
  }

  @Override
  protected Object clone() throws CloneNotSupportedException {
    Node clone = (Node)super.clone();

    clone.visited = this.visited;
    clone.adj = new ArrayList<>();
    for(Edge e : adj){
      clone.addEdge(e.getInitial(), e.getDest(), e.getCapacity(), e.getDuration());
    }

    return clone;
  }
}


