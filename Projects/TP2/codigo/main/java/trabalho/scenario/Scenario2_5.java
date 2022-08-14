package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.Graph;

import java.util.Arrays;
import java.util.List;

public class Scenario2_5 extends Scenario2{
  private int[] latest_arrival_times;
  private int[] earliest_arrival_times;

  public Scenario2_5(Graph g, Integer start, Integer target, List<Route> routes) {
    super(g, start, target, routes);

    this.latest_arrival_times = new int[g.getSize()];
    this.earliest_arrival_times = new int[g.getSize()];
    Arrays.fill(latest_arrival_times, Integer.MIN_VALUE);
    Arrays.fill(earliest_arrival_times, Integer.MAX_VALUE);
  }

  @Override
  public void execute(){
    System.out.println("\n                            SCENARIO 2.5                           \n");

    for(Route r : routes){
      int[] route_times = new int[g.getSize()];
      Arrays.fill(route_times, 0);

      for(int i = 0; i < r.getNodes().size() - 1; i++){
        int start = r.getNodes().get(i);
        int target = r.getNodes().get(i + 1);
        int duration = g.getEdge(start, target).getDuration();

        route_times[target] = route_times[start] + duration;
        latest_arrival_times[target] = Math.max(route_times[target], latest_arrival_times[target]);
        earliest_arrival_times[target] = Math.min(route_times[target], earliest_arrival_times[target]);
      }
    }

    for(int i = 2; i < g.getSize(); i++){
      int time = latest_arrival_times[i] - earliest_arrival_times[i];
      if(time != 0 && latest_arrival_times[i] != Integer.MIN_VALUE){
        System.out.println("Maximum waiting time at " + i + " must be " +
            time + " L: " + latest_arrival_times[i] + " | E : " + earliest_arrival_times[i]);
      }
    }
  }
}
