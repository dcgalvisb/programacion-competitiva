import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        
        String codigo;
        Scanner entrada = new Scanner(System.in);
        int suma, codVerificacion;

        codigo = entrada.nextLine();
        while (!codigo.equals("0")) {

            if (codigo.length() < 8) {
                codigo = obtenerNuevoCodigo(codigo, 8);
            } else if (codigo.length() > 8 && codigo.length() < 13) {
                codigo = obtenerNuevoCodigo(codigo, 13);
            }
            suma = sumarCodigo(codigo);
            
            codVerificacion = Integer.parseInt(codigo.substring(codigo.length() - 1));

            if (codigo.length() == 13) {
                if (verificarCodigo(suma, codVerificacion)) {
                    System.out.print("SI ");
                    switch (obtnerCodigoDelPais(codigo)) {
                        case 0:
                            System.out.println("EEUU");
                            break;
                        case 380:
                            System.out.println("Bulgaria");
                            break;
                        case 50:
                            System.out.println("Inglaterra");
                            break;
                        case 539:
                            System.out.println("Irlanda");
                            break;
                        case 560:
                            System.out.println("Portugal");
                            break;
                        case 70:
                            System.out.println("Noruega");
                            break;
                        case 759:
                            System.out.println("Venezuela");
                            break;
                        case 850:
                            System.out.println("Cuba");
                            break;
                        case 890:
                            System.out.println("India");
                            break;
                        default:
                            System.out.println("Desconocido");
                            break;
                    }
                } else {
                    System.out.println("NO");
                }

            }
            else{
                System.out.println((verificarCodigo(suma, codVerificacion) ? "SI" : "NO"));
            }
            codigo = entrada.nextLine();
        }
    }

    public static int sumarCodigo(String codigo) {
        int sumaPar = 0;
        int sumaImpar = 0;
        int j = 1;
        for (int i = codigo.length() - 2; i > -1; i--) {

            if ((j & 1) == 0) {

                sumaPar += Integer.parseInt(codigo.substring(i, i + 1));

            } else {
                sumaImpar += (Integer.parseInt(codigo.substring(i, i + 1)));
            }
            j++;

        }

        return sumaPar + (3 * sumaImpar);
    }

    public static int obtnerCodigoDelPais(String codigo) {
        int codigoPais = Integer.parseInt(codigo.substring(0, 1));
        if (codigoPais == 0) {
            return codigoPais;
        } else {
            codigoPais = 10 * codigoPais + Integer.parseInt(codigo.substring(1, 2));
            if (codigoPais == 50 || codigoPais == 70) {
                return codigoPais;
            } else {
                return 10 * codigoPais + Integer.parseInt(codigo.substring(2, 3));
            }
        }
    }

    public static boolean verificarCodigo(int suma, int codVerificacion) {
        return (((suma + codVerificacion) % 10) == 0);
    }

    public static String obtenerNuevoCodigo(String codigo, int limite) {

        for (int i = codigo.length(); i < limite; i++) {
            codigo = "0" + codigo;
        }
        return codigo;
    }

}
