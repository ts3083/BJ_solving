import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count1 = 0, count2 = 0, temp = 0;
        int n0 = n;

        if (n / 5 > 0) { // 5kg으로 나눠담을 수 있다면
            int x = n / 5;
            for (int i = 1; i <= x; i++) {
                n = n0;
                temp = 0;
                temp += i;
                n -= 5*i;
                if (n % 3 == 0) {
                    temp += n / 3;
                }
                else {
                    temp = 100000;
                }
                if (count1 == 0 && temp != 0)
                    count1 = temp;
                else
                    count1 = Math.min(count1, temp);
            }
        }
        else {
            count1 = 100000;
        }

        n = n0;
        if (n % 3 == 0) {
            count2 += n / 3;
        }
        else {
            count2 = 100000;
        }

        int result = Math.min(count1, count2);
        if (result == 100000)  {
            System.out.println(-1);
        }
        else {
            System.out.println(result);
        }
    }
}
