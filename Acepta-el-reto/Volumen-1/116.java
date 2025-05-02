package aceptaelreto.holamundo;

import java.util.Scanner;

public class HolaMundo {

    public static void main(String args[]) {

        byte n = new Scanner(System.in).nextByte();
        if (n > -1 && n < 6) {
            while (n-- > 0) {
                System.out.println("Hola mundo.");
            }
        }
    }

}
