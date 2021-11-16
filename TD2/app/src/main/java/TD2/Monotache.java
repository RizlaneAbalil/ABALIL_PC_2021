package main.java.TD2;

public class Monotache extends Thread{

    private String str;

    public Monotache(String str)
    {
        this.str= str;
    }

    public void run()
    {
        System.out.println(str);
    }
}

