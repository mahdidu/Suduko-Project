import java.util.Scanner;

public class sal {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();

       
        int start, end;
        if (a < b) {
            start = a + 1;
            end = b - 1;
        } else {
            start = b + 1;
            end = a - 1;
        }

        
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) {
                System.out.println(i);
            }
        }
    }

 
    static boolean isPrime(int n) {
        if (n < 2) return false; 
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
