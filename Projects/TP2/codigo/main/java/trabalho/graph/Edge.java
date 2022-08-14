package trabalho.graph;

public class Edge implements Cloneable{
  private Integer initial;
  private Integer dest;
  private Integer duration;
  private Integer capacity;

  public Edge(Integer initial, Integer dest, Integer capacity, Integer duration)  {
    this.initial = initial;
    this.dest = dest;
    this.duration = duration;
    this.capacity = capacity;
  }

  public Integer getDest() {
    return dest;
  }

  public void setDest(Integer dest) {
    this.dest = dest;
  }

  public Integer getDuration() {
    return duration;
  }

  public void setDuration(Integer duration) {
    this.duration = duration;
  }

  public Integer getCapacity() {
    return capacity;
  }

  public void setCapacity(Integer capacity) {
    this.capacity = capacity;
  }

  public Integer getInitial() {
    return initial;
  }

  public void print(){
    System.out.println(dest.toString() + " " + capacity.toString() + " " + duration.toString());
  }

  public Edge clone() throws CloneNotSupportedException{
    return (Edge) super.clone();
  }
}




