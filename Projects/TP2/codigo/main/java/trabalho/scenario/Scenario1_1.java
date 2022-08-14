package trabalho.scenario;

import trabalho.Route;
import trabalho.Utils;
import trabalho.graph.Edge;
import trabalho.graph.Graph;
import trabalho.graph.Node;

import java.util.*;

public class Scenario1_1 extends Scenario1{
  private Integer max_group_size;

  public Scenario1_1(Graph g, Integer start, Integer target){
    super(g, start, target);
    this.max_group_size = Integer.MIN_VALUE;
  }

  @Override
  public void execute(){
    System.out.println("\n                            SCENARIO 1.1                           \n");

    Integer[] parent = new Integer[g.getSize()];
    maxMinPath(parent);

    System.out.println("The route " + routes.get(0).toPathString() + " can route the biggest group (" +
        max_group_size + ")");
  }

  public void maxMinPath(Integer[] parent){
    int[] cap = new int[g.getSize()];

    /* Initializing */
    Arrays.fill(parent, -1);
    Arrays.fill(cap, 0);

    cap[start] = Integer.MAX_VALUE;

    Queue<Node> q = new LinkedList<>(g.getNodes());
    while(!q.isEmpty()) {
      Node v = q.poll();
      for (Edge e : v.getAdj()){
        /* If the minimum capacity of this path is greater than the maximum capacity found so far */
        if(Math.min(cap[e.getInitial()], e.getCapacity()) > cap[e.getDest()]){
          cap[e.getDest()] = Math.min(cap[e.getInitial()], e.getCapacity());

          /* If we reached the target node we save the current maximum group size
          * (the maximum of the minimum capacities found so far) */
          if(e.getDest().equals(g.getSize() - 1) && cap[e.getDest()] > max_group_size){
            max_group_size = cap[e.getDest()];
          }

          /* We also update the best route to return */
          parent[e.getDest()] = e.getInitial();
        }
      }
    }

    /* Assembling the maximum minimum capacity route, to be printed later */
    List<Integer> path = new ArrayList<>();
    for(Integer i = target; !i.equals(start); i = parent[i]){
      path.add(0, i);
    }
    path.add(0, start);
    routes.add(new Route(path, max_group_size, max_group_size));
  }
}
