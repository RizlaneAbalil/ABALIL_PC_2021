package TD3.ExerciceBanque;

public class MonThread extends Thread{

    private CompteBancaire compteBancaire;
    public MonThread(CompteBancaire compteBancaire)
    {
        this.compteBancaire = compteBancaire;
    }

    public void run(double op1)
    {
        if(op1 >0)
        {
            compteBancaire.depot(op1);
        }
    }

}
