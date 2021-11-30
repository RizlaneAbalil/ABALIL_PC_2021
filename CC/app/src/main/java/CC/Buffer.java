package CC;

public class Buffer
{
    private Object buffer[];
    private int sizeMax;
    private int lire, ecrire;
    private int nbElmt;

    public Buffer(int N)
    {
        this.buffer = new Object[N];
        this.sizeMax = N;
        this.lire = this.ecrire = this.nbElmt = 0;
    }

    public synchronized void Put(Object o)//Bloquant si buffer plein
    {
        //JE METS A JOUR MON NB D'ELEMENTS +1
        while(this.nbElmt == this.sizeMax)
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
            this.buffer[this.ecrire++] = o;
            notify();
            nbElmt++;
            this.ecrire %= this.sizeMax;
        }
    }

    public synchronized Object get()//Bloquant si buffer vide
    {
        while (this.nbElmt == 0)
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        Object m = this.buffer[this.lire++];
        this.lire %= this.sizeMax;
        notify();
        nbElmt--; 
        return m;
    }
}
