package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.Graph;

import java.util.Scanner;

public class Scenario1 extends Scenario {
  protected Integer start;
  protected Integer target;

  public Scenario1(Graph g){
    super(g);
  }

  public Scenario1(Graph g, Integer start, Integer target){
    super(g);
    this.start = start;
    this.target = target;
  }

  @Override
  public void execute() {
    System.out.println("                           SCENARIO 1                           ");
    getInput();

    Scenario1_1 s1_1= new Scenario1_1(g, start, target);
    s1_1.execute();

    Route mostCapacity = s1_1.getRoutes().get(0);
    Scenario1_2 s1_2 = new Scenario1_2(g, start, target, mostCapacity);
    s1_2.execute();
  }


  public void getInput() {
    Scanner myScanner = new Scanner(System.in);
    System.out.print("Starting node: ");
    start = myScanner.nextInt();

    System.out.print("Target node: ");
    target = myScanner.nextInt();
  }
}
