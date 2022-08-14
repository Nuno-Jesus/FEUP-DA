package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.Graph;

import java.util.*;

import static java.lang.Math.min;

public class Scenario2_1 extends Scenario2 {
    public Scenario2_1(Graph g, Integer start, Integer target, Integer group_size) {
        super(g, start, target, group_size);
    }

    @Override
    public void execute() {
        System.out.println("\n                            SCENARIO 2.1                            \n");

        g.setMaxFlow(fordFulkerson());

        routes.sort(Comparator.comparingInt(Route::getCapacity));
        Collections.reverse(routes);

        var remaining_group_size = group_size;
        for(Route r : routes){
            r.setFlow(Math.min(r.getCapacity(), remaining_group_size));
            remaining_group_size -= r.getFlow();
        }

        if(remaining_group_size > 0){
            System.out.println("SCENARIO 1: Couldn't fit everyone in the network. " +
                "The requested group (" + group_size +
                ") exceeds the maximum flow (" + g.getMaxFlow() + ").");
            return;
        }

        System.out.println("Group: " + group_size + "\n");
        printRoutes();
    }

    public Integer fordFulkerson(){
        int max_graph_flow = 0;
        try{
            Graph residual = (Graph)g.clone();

            int[] parent = new int[g.getSize()];
            Arrays.fill(parent, -1);

            /* While there is an augmenting path */
            while (residual.bfs(start, target, parent)){
                int path_flow = Integer.MAX_VALUE;

                /* Creates a new Route object to store the new path */
                Route path = new Route();
                path.addEdge(target);

                /* And assembles it using a bottom-up approach */
                for (int i = target; i != start ; i = parent[i]){
                    int u = parent[i];
                    path.addEdge(u);
                    path_flow = min(path_flow, residual.getEdge(u, i).getCapacity());
                }

                path.setCapacity(path_flow);
                routes.add(path);

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

        } catch(CloneNotSupportedException e){
            throw new RuntimeException(e);
        }

        return max_graph_flow;
    }
}
