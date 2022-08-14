package trabalho.scenario;

import trabalho.Route;
import trabalho.Utils;
import trabalho.graph.Graph;

import java.util.*;

public class Scenario2_3 extends Scenario2{

    public Scenario2_3(Graph g, Integer start, Integer target){
        super(g, start, target);
    }


    @Override
    public void execute() {
        System.out.println("\n                            SCENARIO 2.3                            \n");

        Integer maximum_flow = fordFulkerson(start, target);
        routes.sort(Comparator.comparingInt(Route::getCapacity));
        Collections.reverse(routes);

        Utils.print_route(routes);
        System.out.println("Maximum network flow: " + maximum_flow);
    }

    public Integer fordFulkerson(Integer start, Integer target){
        Graph residual;
        int max_graph_flow = 0;

        try {
            residual = (Graph) g.clone();

            int[] parent = new int[g.getSize()];
            Arrays.fill(parent, -1);

            /* While there is an augmenting path */
            while (residual.bfs(start, target, parent)){
                int path_flow = Integer.MAX_VALUE;

                /* Creates a new Route object to store the new path */
                Route r = new Route();
                r.addEdge(target);

                /* And assembles it using a bottom-up approach */
                for (int i = target; i != start ; i = parent[i]){
                    int u = parent[i];
                    r.addEdge(u);
                    path_flow = Math.min(path_flow, residual.getEdge(u, i).getCapacity());
                }

                r.setFlow(path_flow);
                r.setCapacity(path_flow);
                routes.add(r);

                for (int i = target; i != start; i = parent[i]){
                    int u = parent[i];

                    int initialCapacity = residual.getEdge(u, i).getCapacity();
                    residual.getEdge(u, i).setCapacity(initialCapacity - path_flow);

                    if(!residual.hasEdge(i, u)){
                        residual.addEdge(i, u, -1, path_flow);
                    }
                    else{
                        int reversedCapacity = residual.getEdge(i, u).getCapacity();
                        residual.getEdge(i, u).setCapacity(reversedCapacity + path_flow);
                    }
                }

                max_graph_flow += path_flow;
                Arrays.fill(parent, -1);
            }

            routes.forEach(route -> Collections.reverse(route.getNodes()));
        } catch (CloneNotSupportedException e) {
            throw new RuntimeException(e);
        }

        g.setMaxFlow(max_graph_flow);
        return max_graph_flow;
    }
}



