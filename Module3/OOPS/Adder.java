import java.util.Scanner;

public class Adder {
    int[] array;
    int targetSum;

    public Adder(int target) {
        targetSum = target;
    }

    void getData() {
        System.out.print("Enter numbers: ");
        Scanner scan = new Scanner(System.in);
        // Enter unlimited number and calculate size
        String input = scan.nextLine();
        String[] strArray = input.split(" ");
        array = new int[strArray.length];
        for (int i = 0; i < strArray.length; i++) {
            array[i] = Integer.parseInt(strArray[i]);
        }
        scan.close();
    }

    int[] numSum() {
        int[] result = { 0, 0 };
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = i + 1; j < array.length; j++) {
                if (array[i] + array[j] == targetSum) {
                    result[0] = array[i];
                    result[1] = array[j];
                    return result;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the Target Sum: ");
        int x = scan.nextInt();
        Adder adder = new Adder(x);
        adder.getData();
        int[] array = new int[2];
        array = adder.numSum();
        if (array[0] == 0) {
            System.out.println("Target not found!.\n");
        } else {
            System.out.print("Output: [" + array[0] + "," + array[1] + "]");
        }
        scan.close();
    }
}
