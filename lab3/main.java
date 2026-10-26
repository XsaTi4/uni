import java.math.*;
import java.util.Arrays;
public class main{

    public int[] arrGen(){
        int[] a = new int[12];

        for (int i = 0; i < 11; i++) {
            a[0+i] = (int)(Math.random()* 11);
        }

        System.out.printf("Generated array: \n", a);

        return a;


    }

    }
    public static void main(String[] args){
        


    }
