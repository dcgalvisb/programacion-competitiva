public class Cuadros {

    public static void main(String args[]) {
        java.util.Scanner in = new java.util.Scanner(System.in);
        short n;
        
        int datos[][];
        while ((n = in.nextShort()) != 0) {
            datos = new int[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    datos[i][j] = in.nextInt();
                }
            }
            System.out.println(esDiabolico(datos) ? (esEsoterico(datos) ? "ESOTERICO" : "DIABOLICO") : "NO");
            
        }

    }

    public static boolean esEsoterico(int[][] cuadro) {

        int suma = 0;
        int n2 = cuadro.length*cuadro.length;
        for (int[] cuadro1 : cuadro) {
            for (int j = 0; j < cuadro.length; j++) {
                if (cuadro1[j] > (n2)) {
                    return false;
                }
                suma += cuadro1[j];
            }
        }
        if (suma != ((n2 * (n2 + 1)) / 2)) {
            return false;
        }
        int cm, cm2, t, c;
        cm = 0;
        for (int i = 0; i < cuadro.length; i++) {
            cm += cuadro[0][i];
        }
        cm2 = (4 * cm) / cuadro.length;
        t = cuadro.length - 1;

        if ((cuadro.length & 1) == 1) {
            c = (t + 1) / 2;
            if ((cuadro[0][0] + cuadro[0][t] + cuadro[t][0] + cuadro[t][t]) == cm2) {
                if ((4 * cuadro[c][c]) == cm2) {
                    return ((cuadro[0][c] + cuadro[t][c] + cuadro[c][0] + cuadro[c][t]) == cm2);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            c = (t - 1) / 2;
            if ((cuadro[0][0] + cuadro[0][t] + cuadro[t][0] + cuadro[t][t]) == cm2) {
                if ((cuadro[c][c] + cuadro[c][c + 1] + cuadro[c + 1][c] + cuadro[c + 1][c + 1]) == cm2) {
                    return ((cuadro[0][c] + cuadro[0][c + 1] + cuadro[c][0] + cuadro[c][t] + cuadro[c + 1][0] + cuadro[c + 1][t]
                            + cuadro[t][c] + cuadro[t][c + 1]) == (2 * cm2));
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

    }

    public static boolean esDiabolico(int[][] cuadro) {

        int sumaFilas, sumaColumnas, auxFilas, auxColumnas, diagonal1, diagonal2;
        sumaFilas = sumaColumnas = auxFilas = auxColumnas = diagonal1 = diagonal2 = 0;

        for (int i = 0; i < cuadro.length; i++) {
            sumaFilas += cuadro[0][i];
            sumaColumnas += cuadro[i][0];
            diagonal1 += cuadro[cuadro.length - 1 - i][i];
            diagonal2 += cuadro[cuadro.length - 1 - i][cuadro.length - 1 - i];
        }

        if (sumaFilas != sumaColumnas || (sumaFilas != diagonal1) || (sumaFilas != diagonal2)) {
            return false;
        }
        for (int i = 1; i < cuadro.length; i++) {
            for (int j = 0; j < cuadro.length; j++) {
                auxFilas += cuadro[i][j];
                auxColumnas += cuadro[j][i];
            }
            if (sumaFilas != auxFilas || sumaColumnas != auxColumnas) {
                return false;
            }
            auxFilas = auxColumnas = 0;
        }
        return true;
    }
}
