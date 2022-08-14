package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.Graph;

import java.util.List;
import java.util.Scanner;

public class Scenario2 extends Scenario{
  protected Integer start;
  protected Integer target;
  protected Integer group_size;

  public Scenario2(Graph g) {
    super(g);
  }

  public Scenario2(Graph g, Integer start, Integer target){
    super(g);
    this.start = start;
    this.target = target;
  }

  public Scenario2(Graph g, Integer group_size, List<Route> routes) {
    super(g, routes);
    this.group_size = group_size;
  }

  public Scenario2(Graph g, Integer start, Integer target, Integer group_size) {
    super(g);
    this.start = start;
    this.target = target;
    this.group_size = group_size;
  }

  public Scenario2(Graph g, Integer start, Integer target, List<Route> routes) {
    super(g, routes);
    this.start = start;
    this.target = target;
  }

  @Override
  public void execute() {
    System.out.println("                           SCENARIO 2                           ");
    getInput();

    Scenario2_1 s2_1 = new Scenario2_1(g, start, target, group_size);
    s2_1.execute();
    routes = s2_1.getRoutes();

    Scenario2_2 s2_2 = new Scenario2_2(g, group_size, routes);
    if(group_size < g.getMaxFlow())
      s2_2.execute();

    else
      System.out.println("\nSCENARIO 2: Couldn't run scenario 2 since the current group size (" +
          group_size + ") exceed the maximum flow of the network " + g.getMaxFlow() + "\n");

    Scenario2_3 s2_3 = new Scenario2_3(g, start, target);
    s2_3.execute();

    Scenario2_4 s2_4 = new Scenario2_4(g, start, target, routes);
    Scenario2_5 s2_5 = new Scenario2_5(g, start, target, routes);

    if(group_size + s2_2.getExtra_people() < g.getMaxFlow()){
      s2_4.execute();
      s2_5.execute();
    }

    else{
      System.out.println("\nSCENARIO 4: Couldn't run scenario 4 since the current group size (" +
          (group_size + s2_2.getExtra_people()) + ") exceed the maximum flow of the network " + g.getMaxFlow() + "\n");
      System.out.println("SCENARIO 5: Couldn't run scenario 5 since the current group size (" +
          (group_size + s2_2.getExtra_people()) + ") exceed the maximum flow of the network " + g.getMaxFlow() + "\n");
    }

  }

  public void getInput() {
    Scanner myScanner = new Scanner(System.in);
    System.out.print("Starting node: ");
    start = myScanner.nextInt();

    System.out.print("Target node: ");
    target = myScanner.nextInt();

    System.out.print("Group size: ");
    group_size = myScanner.nextInt();
  }
}
