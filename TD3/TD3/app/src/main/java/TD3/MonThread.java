//COURS 3 - Les mutex en Java

package TD3;

public class MonThread extends Thread{
    private int cpt;
    private int inc;
    private Variable var;

    public MonThread(int cpt, int inc, Variable var)
    {
        this.cpt = cpt;
        this.inc = inc;
        this.var = var;
    }

    public void run()
    {
        for(int i=0; i<cpt; i++) {
            //Rendre cette opération atomique
            synchronized (var) {
                var.val += inc;
            }
        }
    }
}