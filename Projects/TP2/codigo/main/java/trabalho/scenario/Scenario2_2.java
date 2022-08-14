package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.Graph;

import java.util.*;

public class Scenario2_2 extends Scenario2 {
  private Integer extra_people;

  public Integer getExtra_people() {
    return extra_people;
  }

  public Scenario2_2(Graph g, Integer group_size, List<Route> routes) {
    super(g, group_size, routes);
    this.extra_people = 0;
  }

  @Override
  public void execute() {
    System.out.println("\n                            SCENARIO 2.2                            \n");

    System.out.print("How many people do you wish to add to the group? ");
    Scanner myScanner = new Scanner(System.in);

    extra_people = myScanner.nextInt();

    int remaining_group_size = extra_people;
    for (Route r : routes){
      /* If the route has residual capacity  */
      if(!r.getFlow().equals(r.getCapacity())){
        var chunk = Math.min(r.getCapacity() - r.getFlow(), remaining_group_size);
        remaining_group_size -= chunk;
        r.setFlow(r.getFlow() + chunk);
      }
    }

    if (remaining_group_size > 0) {
      System.out.println("\nSCENARIO 2: Couldn't fit everyone in the network. " +
          "The current capacity (" + group_size + ") + the extra people (" + extra_people +
          ") exceeds the maximum flow (" + g.getMaxFlow() + ").");
      return;
    }

    System.out.println("\nGroup: " + (group_size + extra_people) + "\n");
    printRoutes();
  }


}