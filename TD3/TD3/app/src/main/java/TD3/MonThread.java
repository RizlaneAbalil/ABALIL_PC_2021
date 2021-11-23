//COURS 3 - Les mutex en Java

package TD3;

import java.util.concurrent.Semaphore;

public class MonThread extends Thread{
    private int cpt;
    private int inc;
    private Variable var;
    Semaphore s;


    public MonThread(int cpt, int inc, Variable var, Semaphore s)
    {
        this.cpt = cpt;
        this.inc = inc;
        this.var = var;
        this.s = s ;
    }

    public void run()
    {
        for(int i=0; i<cpt; i++) {
            //Rendre cette opération atomique
            /*synchronized (var) {
                var.val += inc;
            }*/

            //Soit synchronised soit semaphore
            try{
                s.acquire();
            }
            catch (Exception e){}
            {
                var.val += inc;
            }
            s.release();
        }
    }
}