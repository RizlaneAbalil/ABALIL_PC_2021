package CC;

import java.util.List;

public class MonThread extends Thread{

    private List<Integer> valeur;

    public MonThread(List<Integer> valeur)
    {
        this.valeur = valeur;
    }

    public void run()
    {
        //On récupère les multiples de valeur

        //Elle reçoit des nombres de i-1 appelés reception

        //Elle envoie à i+1 les nombres non multiples de valeur
    }
}
