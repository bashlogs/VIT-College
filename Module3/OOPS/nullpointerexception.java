/**
 * nullpointerexception
 */
import java.util.Scanner;
public class nullpointerexception {

    public static void main(String[] args) {
        // Take user input
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        //read the string
        String str = sc.nextLine();
        // if input is null throw error
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