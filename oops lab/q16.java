import java.util.*;

public class q16 {

    public static void main(String[] args) {

        String str = "y";
        double mem = Double.MIN_VALUE;
        int choice = 0;
        Scanner sc = new Scanner(System.in);

        while(!str.equals("n")) {
            System.out.println("\n\nEnter the first number (or type MEM for memory)");
            str = sc.next();
            double a = getNum(str, mem);

            System.out.println("Enter the second number (or type MEM for memory)");
            str = sc.next();
            double b = getNum(str, mem);

            while (choice <= 0 || choice >2) {
                System.out.printf("Enter the operation to be performed\n1.Add.\n2.Subtract");
                choice = sc.nextInt();
            }
            double ans = getResult(choice, a, b);
            System.out.println("The answer is " + ans );
            System.out.println("Do you want to remember it? (y or n)");
            str = sc.next();

            mem = remember(str, mem, ans);
            System.out.println("Do you want to continue? (y or n)");
            str = sc.next();
        }
    }


    public static double add (double a, double b) {
        return a + b;
    }

    public static double sub (double a, double b) {
        return a - b;
    }

    public static double remember (String str,double mem, double ans) {
        if(str.toLowerCase().equals("y") || str.toLowerCase().equals("yes"))
            return ans;
        else return mem;
    }

    public static double getResult(int choice, double a, double b) {
        if (choice == 1)
            return add(a, b);
        else if (choice == 2)
            return sub(a, b);
        else {
            throw new IllegalArgumentException("wrong choice");
        }
    }

    public static double getNum(String str, double mem) {
        try {
            return Double.parseDouble(str);
        } catch (IllegalArgumentException e) {
            if(mem == Double.MIN_VALUE) {
                System.out.println("Mem not initialised, will use 0 for the mem.");
                return 0;
            } else return mem;
        }
    }
}
