import java.util.ArrayList;
import java.util.Scanner;

class Order {
    private ArrayList<String> itemNames;
    private boolean isCashOnDelivery;

    public Order(ArrayList<String> itemNames, boolean isCashOnDelivery) {
        this.itemNames = itemNames;
        this.isCashOnDelivery = isCashOnDelivery;
    }

    public ArrayList<String> getItems() {
        return itemNames;
    }


    public boolean isCashOnDelivery() {
        return isCashOnDelivery;
    }
}

public class arraylist {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Order> orders = new ArrayList<>();

        // Get order details from user
        Scanner id = new Scanner(System.in);
        System.out.print("Enter Total Orders: ");
        int totalOrders = id.nextInt();
        int i = 1;
        do {
            System.out.println("\nEnter "+i+" order details");
            System.out.print("Enter item names: ");
            String itemNamesInput = input.nextLine();
            ArrayList<String> itemNames = new ArrayList<>(java.util.Arrays.asList(itemNamesInput.split(",")));

            System.out.print("Is cash on delivery? (true/false): ");
            boolean isCashOnDelivery = input.nextBoolean();

            Order order = new Order(itemNames, isCashOnDelivery);
            orders.add(order);
            input.nextLine(); // Consume newline character

            i++;
        } while (i<=totalOrders);

        input.close();

        // Retrieve and print the list of items from all orders
        ArrayList<String> allItems = new ArrayList<>();
        for (Order order : orders) {
            ArrayList<String> items = order.getItems();
            allItems.addAll(items);
        }

        System.out.println("\nList of items present in all orders: ");
        System.out.println(allItems);
    }
}