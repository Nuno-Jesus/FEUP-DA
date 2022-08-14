package trabalho;

import trabalho.graph.Graph;
import trabalho.scenario.*;

import java.util.Scanner;

public class Main {
  public static void main(String[] args){
    System.out.print("File to parse: ");

    Scanner myScanner = new Scanner(System.in);
    Integer fileNumber = myScanner.nextInt();

    Graph g = new Graph(0, false);
    Utils.readDataset(fileNumber, g);

    new Scenario1(g).execute();
    new Scenario2(g).execute();

  }
}


