package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.*;

import java.util.*;

public class Scenario1_2 extends Scenario1 {
    private Integer maxGroupSize;
    private List<Route> bestRoutes;
    private Route mostCapacityRoute;
    private Map<Integer, Route> nonComparableRoutes;

    public Scenario1_2(Graph g, Integer start, Integer target, Route r) {
        super(g, start, target);
        this.mostCapacityRoute = r;
        this.maxGroupSize = Integer.MIN_VALUE;
        this.bestRoutes = new ArrayList<>();
        this.nonComparableRoutes = new HashMap<>();
        this.nonComparableRoutes.put(mostCapacityRoute.getCapacity(), mostCapacityRoute);
    }

    @Override
    public void execute(){
        System.out.println("\n                            SCENARIO 1.2                            \n");

        List<Integer> path = new ArrayList<>();
        int capacity = Integer.MAX_VALUE;
        path.add(start);

        /* The dfs*/
        dfs(start, path, capacity);
        findBestRoutes();
        printRoutes();
    }

    /** This is a modified version of the dfs, because it only stops when it find all
    * paths available between a start and a target. Whenever it hits the target, it
    * adds a path assembled recursively.
     *
     *  @param v The node to explore
     *  @param path The path built up so far
     *  @param capacity The path capacity (the minimum of edge capacities)
    * */
    public void dfs(int v, List<Integer> path, int capacity){
        for(Edge e : g.getNodes().get(v).getAdj()){
            if(e.getDest().equals(target)){
                List<Integer> clone = new ArrayList<>(path);
                clone.add(target);
                capacity = Math.min(e.getCapacity(), capacity);
                Route r = new Route(clone, capacity, capacity);
                routes.add(r);
                return;
            }

            int oldCapacity = capacity;
            path.add(e.getDest());
            capacity = Math.min(e.getCapacity(), capacity);
            dfs(e.getDest(), path, capacity);
            capacity = oldCapacity;
            path.removeIf(value -> value.equals(e.getDest()));
        }
    }

    public void findBestRoutes(){
        /* DEBUG PURPOSES
        Route r = new Route(Arrays.asList(1, 3, 6), -1, 11);
        routes.add(r);
        r = new Route(Arrays.asList(1, 3), -1, 9);
        routes.add(r);
        r = new Route(Arrays.asList(1, 3), -1, 10);
        routes.add(r);
         DEBUG PURPOSES */
        routes.sort(Comparator.reverseOrder());
        /* Number of stops of the route with most capacity */
        int stopOvers = mostCapacityRoute.getNodes().size();

        /* Remove all routes that have more stopOvers than the route with the most capacity */
        final int finalStopOvers = stopOvers;
        routes.removeIf(route -> route.getNodes().size() >= finalStopOvers && !route.equals(mostCapacityRoute));

        /* Iterate over each route to verify which routes are non-comparable */
        for(Route route : routes){
            /* If the capacity wasn't associated with a route, insert it*/
            if(!nonComparableRoutes.containsKey(route.getCapacity())){
                if(route.getNodes().size() < stopOvers){
                    nonComparableRoutes.put(route.getCapacity(), route);
                    stopOvers = route.getNodes().size();
                }
            }
            /* Otherwise, the best route will be the one with fewer stopovers */
            else if(nonComparableRoutes.get(route.getCapacity()).getNodes().size() > route.getNodes().size())
                nonComparableRoutes.put(route.getCapacity(), route);
        }

        bestRoutes.addAll(nonComparableRoutes.values());
        routes = bestRoutes;
    }
}
