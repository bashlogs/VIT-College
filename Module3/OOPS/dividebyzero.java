// Write a progrom to handle divide by zero exception
import java.util.Scanner;

class nullpointer{
    nullpointer(){
        Scanner sc = new Scanner(System.in);    
        System.out.print("Enter number : ");
        int number = sc.nextInt();
        System.out.print("Enter divisor : ");
        int divisor = sc.nextInt();
        try {
            int c = number / divisor;
            int d = number % divisor;
            System.out.println("Division: " + c);
            System.out.println("Remainder: " + d);
        } catch (Exception e) {
            System.out.println("Divide by zero error");
        }
    }
}

class array{
    array(){
        int[] array;
        Scanner scan = new Scanner(System.in);  
        Scanner sc = new Scanner(System.in);  

        System.out.print("Enter how much element you want: ");
        int n = sc.nextInt();
        array = new int[n];
        System.out.print("Enter the list of array: ");
        String input = scan.nextLine();
        String[] strArray = input.split(" ");
        int sum = 0;
        try {
            for (int i = 0; i < strArray.length; i++) {
                array[i] = Integer.parseInt(strArray[i]);
                sum = sum + array[i];
            }
            System.out.println("Sum of the array: " + sum);
        }
        catch (Exception e) {
            System.out.println("Array Index Out of Bound Exception");
        }
    }
}
class strlength{
    strlength(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        String str = sc.nextLine();

        try {
            if(str == null || str.length() == 0){
                throw new NullPointerException();
            } 
            else{
                System.out.println(str.length());
            }
        } catch (Exception e) {
            System.out.println("Null pointer exception");
        }
    }
}
public class dividebyzero {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = 0;
        while(true){
            System.out.println("\n0)Exit \n1)Divide \n2)Access array element \n3)Find lenght of the string\n");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch(choice){
                case 0:
                    System.out.println("Exiting...");
                    System.exit(0);
                case 1:
                    new nullpointer();
                    break;
                case 2:
                    new array();
                    break;
                case 3:
                    new strlength();
                    break;
                default:
                    System.out.println("Invalid choice");
                    System.exit(0);
            }
        }
    }
}