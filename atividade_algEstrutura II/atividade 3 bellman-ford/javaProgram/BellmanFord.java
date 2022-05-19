import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BellmanFord {
    private static final double EPSILON = 1E-14;
    private double[] distTo ;
    private int[] edgeTo;
    private DirectedEdge[] aresta;
    private int cost;
    private int V;
    private int E;
    private int s;

    public BellmanFord(String filepath, int source) {
        s = source;

        readInput(filepath);
        Inicializa();

        int i,j;
        for (i = 1; i< V; ++i) {
            for (j=0; j< E; ++j) {
                relax(aresta[j]);
            }
        }

        for (i = 0; i< V; ++i) {
            if(hasPathTo(i)) {
                System.out.printf("Rota de %d a %d (%5.2f)",
                        s,
                        i,
                        distTo[i]);
                printPathTo(i);
                System.out.println();
            }
        }
        if (!negative()) {
            System.out.println("\nNao ha Ciclos Negativos\n");
        }
    }

    private boolean negative() {
        int v,w;
        double peso;
        boolean negative = false;

        for (int i = 0; i< E; ++i) {
            v = aresta[i].from();
            w = aresta[i].to();
            peso = aresta[i].weight();

            if (distTo[w] > distTo[v] + peso + EPSILON) {
                negative = true;
                System.out.printf("\nCiclo Negativo entre %d e %d",v,w);
            }
        }
        return  negative;
    }

    public void printPathTo(int v) {
        if (v == s) {
            System.out.println("\t");
            System.out.print(s);
            return;
        }
        printPathTo(edgeTo[v]);
        System.out.print(" -> ");
        System.out.print(v);
    }

    public void Inicializa() {
        for (int i=0; i< V; i++) {
            distTo[i] = Double.POSITIVE_INFINITY;
            edgeTo[i] = -1;
        }
        distTo[s] = 0.0;
    }

    private void relax(DirectedEdge aresta) {
        int v = aresta.from();
        int w = aresta.to();
        double peso = aresta.weight();
        if (distTo[w] > distTo[v] + peso + EPSILON) {
            distTo[w] = distTo[v] + peso;
            edgeTo[w] = v;
        }
    }

    public boolean hasPathTo(int v) {
        return distTo[v] < Double.POSITIVE_INFINITY;
    }

    public void readInput(String filepath){
        Scanner sc;
        File file = null;
        String line;
        int a,b;
        double cost;
        StringTokenizer tk;
        try {
            file = new File(filepath);
            sc = new Scanner(file);
            if (sc.hasNext())
                V = sc.nextInt();
            else {
                System.out.println("\nArquivo Invalido");
                System.exit(0);
            }

            if (sc.hasNext()) {
                E = sc.nextInt();
            }
            else {
                System.out.println("\nAruivo infalido");
                System.exit(0);
            }
            distTo = new double[V];
            edgeTo = new int[V];
            aresta = new DirectedEdge[E];
            for (int i = 0; i<E;++i){
                a = sc.nextInt();
                b= sc.nextInt();

                cost = Double.parseDouble(sc.next());

                aresta[i] = new DirectedEdge(a,b,cost);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        if (args.length <2) {
            System.out.println("\n\nUso java BellmanFord Grafo no-inicial\n");
            return;
        }
        BellmanFord BF = new BellmanFord(args[0], Integer.parseInt(args[1]));
    }
}
