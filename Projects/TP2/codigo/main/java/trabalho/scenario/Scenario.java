package trabalho.scenario;

import trabalho.Route;
import trabalho.graph.Graph;

import java.util.ArrayList;
import java.util.List;

public abstract class Scenario {
    protected Graph g;
    protected List<Route> routes;

    public Scenario(Graph g){
        this.g = g;
        this.routes = new ArrayList<>();
    }

    public Scenario(Graph g, List<Route> routes){
        this.g = g;
        this.routes = routes;
    }

    public abstract void execute();

    public void printRoutes(){
        for(Route r : routes)
            if(r.getFlow() != 0)
                System.out.println(r);
    }

    public List<Route> getRoutes() {
        return routes;
    }
}
