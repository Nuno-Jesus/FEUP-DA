package trabalho;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Route implements Comparable<Route>{
    private Integer flow;
    private Integer capacity;
    private List<Integer> nodes;

    public Route(){
        this.nodes = new ArrayList<>();
        this.flow = 0;
        this.capacity = 0;
    }
    public Route(List<Integer> nodes, Integer flow, Integer capacity){
        this.nodes = nodes;
        this.flow = flow;
        this.capacity = capacity;
    }

    public void setCapacity(Integer capacity) {
        this.capacity = capacity;
    }

    public void setFlow(Integer flow) {
        this.flow = flow;
    }

    public void setNodes(List<Integer> nodes) {
        this.nodes = nodes;
    }

    public void addEdge(Integer edge) {
        this.nodes.add(edge);
    }

    public List<Integer> getNodes() {
        return nodes;
    }

    public Integer getFlow() {
        return flow;
    }

    public Integer getCapacity() {
        return capacity;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();

        builder.append("The route " + nodes.get(0).toString());
        for(Integer node : nodes.subList(1, nodes.size())){
            builder.append("->" + node.toString());
        }
        builder.append(" is routing " + flow + " out of its capacity (" + capacity + ")");
        return builder.toString();
    }

    public String toPathString(){
        StringBuilder builder = new StringBuilder();

        builder.append(nodes.get(0).toString());
        for(Integer node : nodes.subList(1, nodes.size())){
            builder.append("->" + node.toString());
        }

        return builder.toString();
    }

    @Override
    public boolean equals(Object obj) {
        // If the object is compared with itself then return true
        if (obj == this) {
            return true;
        }

        if (!(obj instanceof Route route))
            return false;

        for (int i = 0; i < this.nodes.size(); i++){
            if (!Objects.equals(this.nodes.get(i), route.getNodes().get(i)))
                return false;
        }

        return Objects.equals(this.capacity, route.getCapacity())
                && Objects.equals(this.flow, route.getFlow());
    }

    public int compareTo(Route r2){
        return this.getCapacity().compareTo(r2.getCapacity());
    }
}
