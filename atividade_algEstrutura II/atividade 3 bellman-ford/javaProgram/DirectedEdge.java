public class DirectedEdge {
    private final int v;
    private final int w;
    private final double weight;

    public DirectedEdge(int v, int w, double weigth) {
        if (v<0) throw new IllegalArgumentException("Vertex names must be non-negative intergers");
        if (w<0) throw new IllegalArgumentException("Vertex names must be non-negative intergers");
        if(Double.isNaN(weigth)) throw new IllegalArgumentException("Weight is NaN");

        this.v =v;
        this.w = w;
        this.weight = weigth;
    }

    public int from() {
        return v;
    }

    public int to() {
        return w;
    }

    public double weight() {
        return weight;
    }

    public String toString() {
        return v + "->" + w + " " + String.format("%5.2f", weight);
    }
}
