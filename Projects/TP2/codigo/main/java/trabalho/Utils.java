package trabalho;

import trabalho.graph.Graph;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class Utils {
  public static String buildFileName(Integer number){
    String filename;

    try{
      if(number < 10)
        filename = "input/in0" + number + ".txt";
      else
        filename = "input/in" + number + ".txt";

      new FileReader(filename);
      return filename;

    }catch(FileNotFoundException e){
      e.printStackTrace();
    }

    return "";
  }

  public static void readDataset(Integer number, Graph g){
    try {
      String filename = Utils.buildFileName(number);
      File file = new File(filename);
      Scanner myScanner = new Scanner(file);

      String[] tokens = myScanner.nextLine().split(" ");

      int numEdges = Integer.parseInt(tokens[1]);
      g.setNodes(Integer.parseInt(tokens[0]) + 1);

      for(int i = 0; i < numEdges; i++){
        tokens = myScanner.nextLine().split(" ");
        g.addEdge(
            Integer.parseInt(tokens[0]),
            Integer.parseInt(tokens[1]),
            Integer.parseInt(tokens[2]),
            Integer.parseInt(tokens[3])
        );
      }

    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void print_route(List<Route> routes){
    for(Route r : routes){
      if(r.getFlow() != 0){
        System.out.print("Route: ");

        for (int i = 0; i < r.getNodes().size(); i++) {
          if (i != r.getNodes().size() - 1)
            System.out.print(r.getNodes().get(i) + "->");
          else
            System.out.println(r.getNodes().get(i) + " | f -> " + r.getFlow() + " | c -> " + r.getCapacity());
        }
      }
    }
  }
}
