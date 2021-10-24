interface Discount {
    String doOperation();
}

class NewCustomerDiscount implements Discount {

    @Override
    public String doOperation() {
        return "New Customer Discount";
    }
}

class LoyalCustomerDiscount implements Discount {

    @Override
    public String doOperation() {
        return "Loyal Customer Discount";
    }
}

class GoodsDiscount implements Discount {

    @Override
    public String doOperation() {
        return "Discount for customers purchasing goods of more than Rs. 10000";
    }
}

class Context {
    private Discount discount;

    public Context(Discount discount) {
        this.discount = discount;
    }

    public String executeDiscount() {
        return discount.doOperation();
    }
}

public class Task3 {
    public static void main(String[] args) {

        Context context;

        // Prints new customer discount
        context = new Context(new NewCustomerDiscount());
        System.out.println(context.executeDiscount());

        // Prints loyal customer discount
        context = new Context(new LoyalCustomerDiscount());
        System.out.println(context.executeDiscount());

        // Prints Discounts for purchase more than 10000
        context = new Context(new GoodsDiscount());
        System.out.println(context.executeDiscount());
    }
}
