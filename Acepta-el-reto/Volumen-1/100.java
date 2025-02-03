package aceptaelreto.kaprekar;

import java.util.Scanner;

public class Kaprekar {

    public static void main(String args[]) {
        Scanner entrada = new Scanner(System.in);

        int numero, mayor, menor, contador = 0, aux, i = 0;
        int digitos[];
        short nPruebas;

        nPruebas = entrada.nextShort();

        while (i < nPruebas) {
            numero = entrada.nextShort();
            digitos = obtenerDigitosOrdenados(numero);
            while (numero != 6174 && contador < 8) {
                contador++;
                aux = 1000;
                mayor = menor = 0;
                for (int j = 0; j < 4; j++) {
                    menor += (digitos[j] * aux);
                    mayor += (digitos[3 - j] * aux);
                    aux /= 10;
                }
                numero = mayor - menor;
                digitos = obtenerDigitosOrdenados(numero);

            }

            System.out.println(contador);
            contador = 0;
            i++;
        }

    }

    public static int[] obtenerDigitosOrdenados(int numero) {
        int i, j, residuo;
        int digitos[] = new int[4];

        for (i = 0; i < 4; i++) {
            residuo = numero % 10;
            numero /= 10;
            j = i - 1;
            while (j >= 0 && residuo < digitos[j]) {
                digitos[j + 1] = digitos[j];
                j -= 1;
            }
            digitos[j + 1] = residuo;
        }
        return digitos;
    }
}
