package TD3.ExerciceBanque;

/*
ENONCE
    On a une classe CompteBnacaire avec 2 methodes et 1 attribut :
        - Retrait(montant)
        - Depot (montant) -> renvoie -1 si pas possible
        - montantDisponible
 */

public class CompteBancaire {
    public double solde;

    public CompteBancaire(double montantDisponible)
    {
        this.solde = montantDisponible;
    }

    public synchronized void retrait(double montant) throws Exception
    {
        if(solde-montant<0) {
            throw new Exception();
        }
        this.solde -= montant;
    }

    public synchronized void depot(double montant)
    {
        this.solde += montant;
    }

    public synchronized void setSolde(double solde)
    {
        this.solde = solde;
    }
}
