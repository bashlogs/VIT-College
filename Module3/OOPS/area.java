import java.util.Scanner;

class Shape {
    float setArea(int base, int height) {
        return ((base * height) / 2);
    }

    float setArea(int side) {
        return (side * side);
    }

    double setArea(float radius) {
        double PI = 3.14;
        return (PI * (radius * radius));
    }
}

class Triangle extends Shape {
    Triangle() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Base of triangle: ");
        int base = sc.nextInt();
        System.out.print("Enter Height of triangle: ");
        int height = sc.nextInt();

        float area = setArea(base, height);
        System.out.println("Area of Triangle is: " + area + " sq/cm");
    }
}

class Square extends Shape {
    Square() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of the square: ");
        int side = sc.nextInt();

        float area = setArea(side);
        System.out.println("Area of Square is: " + area + " sq/cm");
    }
}

class Circle extends Shape {
    Circle() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter radius of Circle: ");
        float radius = sc.nextFloat();
        double area = setArea(radius);
        System.out.println("Area of Circle is: " + area + " sq/cm");
    }
}

public class area {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Shape shape = null;

        

        while(true){

            System.out.println("\nChoose a shape: \n0. Exit\n1. Triangle\n2. Square\n3. Circle\n");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 0:
                    System.out.println("Exiting...");
                    System.exit(0);
                case 1:
                    shape = new Triangle();
                    break;
                case 2:
                    shape = new Square();
                    break;
                case 3:
                    shape = new Circle();
                    break;
                default:
                    System.out.println("Invalid choice");
                    System.exit(0);
            }
        }
    }
}
