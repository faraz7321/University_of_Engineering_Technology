import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;

class Product {
    int productId;
    String category;
    String productName;

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public int getProductId() {
        return productId;
    }

    public void setProductId(int productId) {
        this.productId = productId;
    }

    public String getProductName() {
        return productName;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public boolean addProduct(String productName, String cat) {
        boolean flag = false;
        Product p = new Product();
        Random rand = new Random();
        int r = rand.nextInt(99999);
        p.setProductName(productName);
        p.setCategory(cat);
        p.setProductId(r);
        if (llproducts.add(p) && alproducts.add(p)) {
            flag = true;
        }
        return flag;

    }

    public boolean deleteProduct(int deleteId) {
        boolean flag = false;
        Iterator<Product> itr = Product.llproducts.iterator();
        while (itr.hasNext()) {
            Product p = itr.next();
            int id = p.getProductId();
            if (id == deleteId) {
                itr.remove();
                flag = true;
            }
        }
        return flag;
    }

    public boolean updateProduct(int searchId) {
        Scanner scanner = new Scanner(System.in);
        boolean flag = false;
        String cat = "";
        String prodName = "";
        Iterator<Product> itr = Product.llproducts.iterator();
        while (itr.hasNext()) {
            Product p = itr.next();
            int id = p.getProductId();
            if (id == searchId) {
                System.out.println("Product Name: ");
                cat = scanner.nextLine();
                System.out.println("Product Category: ");
                prodName = scanner.nextLine();
                p.setCategory(cat);
                p.setProductName(prodName);
                flag = true;
            }
        }
        return flag;
    }

    void viewItems() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
        Iterator<Product> itr = Product.llproducts.iterator();
        String format = "%-20s %-20s%-20s";
        System.out.println(String.format(format, "ProductID", "Category", "Product Name"));
        while (itr.hasNext()) {
            Product pitr = itr.next();
            int pId = pitr.getProductId();
            String cat = pitr.getCategory();
            String name = pitr.getProductName();
            System.out.println(String.format(format, pId, cat, name));
        }
    }

    static LinkedList<Product> llproducts = new LinkedList<>();
    static ArrayList<Product> alproducts = new ArrayList<>();

}

public class Task1 {

    public static void main(String[] args) {

        Product product = new Product();
        Scanner scanner = new Scanner(System.in);
        String input = "";
        do {
            System.out.print("\033[H\033[2J");
            System.out.flush();
            System.out.println("1> Add Item\n2> Delete Item\n3> Update Item\n4> View All Items\n0> Exit");
            input = scanner.nextLine();
            switch (input) {

            // Add Items
            case "1": {
                System.out.println("Product Name: ");
                String prodname = scanner.nextLine();
                System.out.println("Product Category: ");
                String prodcat = scanner.nextLine();
                if (product.addProduct(prodname, prodcat)) {
                    System.out.println("Product added successfully!");
                } else {
                    System.out.println("Product was not added ");
                }
                break;
            }
            // Delete Items
            case "2": {
                System.out.println("Enter Product ID to Delete");
                int deleteid = scanner.nextInt();
                if (product.deleteProduct(deleteid)) {
                    System.out.println("Product Deleted Successfully!");
                } else {
                    System.out.println("Product Was Not Deleted!");
                }
                break;
            }
            // Update Items
            case "3": {
                System.out.println("Enter Product ID to Update");
                int searchId = scanner.nextInt();
                if (product.updateProduct(searchId)) {
                    System.out.println("Product Updated Successfully!");
                } else {
                    System.out.println("Product Was Not Updated!");
                }

                break;
            }
            // View All Items
            case "4": {
                product.viewItems();
                System.out.println("Press any key to continue...");
                scanner.nextLine();
                break;
            }
            case "0": {
                scanner.close();
                System.exit(0);

                break;
            }
            default: {
                break;
            }
            }

        } while (input != "0");

    }

}