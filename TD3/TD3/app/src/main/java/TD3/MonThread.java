//COURS 3 - Les mutex en Java

package TD3;

public class MonThread extends Thread{
    private static int valeur;

    public MonThread()
    {
        this.valeur = 0;
    }

    public synchronized void inc()
    {
        for(int i=0; i<10000; i++) {
            this.valeur++;
        }
        System.out.println("Void inc "+ this.valeur);
    }

    public synchronized void dec()
    {
        for(int i=0; i<10000; i++) {
            this.valeur--;
        }
        System.out.println("Void dec "+ this.valeur);
    }

    public void run()
    {
        inc();
        dec();
        System.out.println("Valeur "+this.valeur);
    }

}
