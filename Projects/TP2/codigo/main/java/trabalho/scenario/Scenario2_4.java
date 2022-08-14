package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.Graph;

import java.util.*;

public class Scenario2_4 extends Scenario2{
  private List<Integer> travel_times;

  public Scenario2_4(Graph g, Integer start, Integer target, List<Route> routes){
    super(g, start, target, routes);
    this.travel_times = new ArrayList<>(Collections.nCopies(routes.size(), 0));
  }

  @Override
  public void execute(){
    System.out.println("\n                            SCENARIO 2.4                            \n");

    for(int k = 0; k < routes.size(); k++){
      var r = routes.get(k);
      if(r.getFlow() != 0){
        for(int i = 0; i < r.getNodes().size() - 1; i++){
          int duration = g.getEdge(r.getNodes().get(i), r.getNodes().get(i + 1)).getDuration();
          travel_times.set(k, travel_times.get(k) + duration);
        }
        System.out.println("Route " + k + " (" + r.toPathString() + "): " + travel_times.get(k));
      }
    }

    System.out.println("The group is reunited again after a minimum of " + Collections.max(travel_times) +
        " time units.");
  }
}
