package app;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 * @author Faraz Ahmad
 */

public class App {
    static String printMenu() {
        String x = JOptionPane.showInputDialog("Choose from the following option: \n\n" + "Press 1 to Add New Car\n"
                + "Press 2 to View Receipt\n" + "Press 3 to Exit Program");
        return x;
    }

    /**
     * @param args the command line arguments
     * @throws IOException
     */
    public static void main(String[] args) throws IOException {
        Car cars = new Car();
        Receipt receipts = new Receipt();
        receipts.setCar(cars);
        TollBooth tBooth = new TollBooth();
        tBooth.setReceipt(new ArrayList<>());
        tBooth.getReceipt().add(receipts);
        String model = "";
        String make = "";
        String carNumber = "";
        String engineCapacity = "";
        String seatingCapacity = "";
        String driverName = "";
        // String isGovtVehicle = "";
        boolean flag = false;
        Scanner scanner = new Scanner(System.in);
        do {
            switch (printMenu()) {
            case "1": {
                do {
                    flag = false;
                    model = JOptionPane.showInputDialog("Enter Model: ");
                    if (Car.isValidModel(model)) {
                        flag = true;
                    }
                } while (flag == false);
                do {
                    flag = false;
                    make = JOptionPane.showInputDialog("Enter Make: ");
                    if (Car.isValidMake(Integer.parseInt(make))) {
                        flag = true;
                    }
                } while (flag == false);
                do {
                    flag = false;
                    carNumber = JOptionPane.showInputDialog("Enter Car Number: ");
                    if (Car.isValidCarNumber(carNumber)) {
                        flag = true;
                    }
                } while (flag == false);
                do {
                    flag = false;
                    engineCapacity = JOptionPane.showInputDialog("Enter Engine capacity: ");
                    if (Car.isValidEngineCapacity(Integer.parseInt(engineCapacity))) {
                        flag = true;
                    }
                } while (flag == false);
                do {
                    flag = false;
                    seatingCapacity = JOptionPane.showInputDialog("Enter seating capacity: ");
                    if (Car.isValidSeatingCapacity(Integer.parseInt(seatingCapacity))) {
                        flag = true;
                    }
                } while (flag == false);
                do {
                    flag = false;
                    driverName = JOptionPane.showInputDialog("Enter Driver Name: ");
                    if (Car.isValidDriverName(driverName)) {
                        flag = true;
                    }
                } while (flag == false);
                boolean govt = Car.isValidIsGovtVehicle(carNumber);
                cars = new Car(model, make, carNumber, engineCapacity, seatingCapacity, driverName, govt);
                receipts = new Receipt();
                receipts.setCar(cars);
                tBooth = new TollBooth();
                tBooth.getReceipt().add(receipts);
                break;
            }
            case "2": {
                String cout = String.format("Location: " + tBooth.getLocation() + "\nDate & Time: " + receipts.getTime()
                        + "\n\nModel: " + receipts.getCar().getModel() + "\nMake: " + receipts.getCar().getMake()
                        + "\nCar Number: " + receipts.getCar().getCarNumber() + "\nEngine Capacity: "
                        + receipts.getCar().getEngineCapacity() + "\nSeat Capacity: "
                        + receipts.getCar().getSeatingCapacity() + "\nDriver Name: " + receipts.getCar().getDriverName()
                        + "\nToll Amount: " + receipts.getCar().calculateToll());
                JOptionPane.showMessageDialog(null, cout);
                break;
            }
            case "3": {
                tBooth.storeData(tBooth.getReceipt());
                break;
            }

            default:
                break;
            }
        } while (!printMenu().equals("3"));
        scanner.close();

    }

}
