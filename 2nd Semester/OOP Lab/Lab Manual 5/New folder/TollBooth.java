import java.util.ArrayList;
import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
public class TollBooth {
    private String location;
    private List<Receipt> receipt;

    public void storeData(List<Receipt> receipts2) {
        Receipt receipts = new Receipt();
        try {
            int size = receipts2.size();
            FileWriter fout = new FileWriter("Data.txt");
            System.out.print(size);
            for (int i = 0; i < size; i++) {
                receipts = receipts2.get(i);
                fout.write(receipts.getCar().getModel() + "," + receipts.getCar().getMake() + ","
                        + receipts.getCar().getCarNumber() + "," + receipts.getCar().getEngineCapacity() + ","
                        + receipts.getCar().getSeatingCapacity() + "," + receipts.getCar().getDriverName() + "\n");

            }
            fout.flush();
            fout.close();
        } catch (Exception e) {
            System.out.println("\nError!\n");
        }
    }
        public List<Receipt> loadData(){
        String model = "";
        String make = "";
        String carNumber = "";
        String engineCapacity = "";
        String seatingCapacity = "";
        String driverName = "";
        boolean govt = false;
        List<Receipt> receipts = new ArrayList<Receipt>();
        try
        {
        FileReader fin = new FileReader("Data.txt");
        BufferedReader yo = new BufferedReader(fin);
        Receipt objReceipt = new Receipt();
        Car car = new Car();
        while (yo.readLine() != null) {
            String line = yo.readLine();
            String arrInput[] = line.split(",");
            model = arrInput[0];
            make = arrInput[1];
            carNumber = arrInput[2];
            engineCapacity = arrInput[3];
            seatingCapacity = arrInput[4];
            driverName = arrInput[5];
            govt = Car.isValidIsGovtVehicle(carNumber);
            car = new Car(model, make, carNumber, engineCapacity, seatingCapacity, driverName, govt);
            objReceipt.setCar(car);
            receipts.add(objReceipt);
        }
        yo.close();
        }
        catch(Exception ex)
        {
         
        }
        return receipts;
    }
    public TollBooth(){
        this.receipt = loadData();
        this.location = "Ravi Toll Plaza, Lahore";
    }

    public String getLocation() {
        return location;
    }

    public List<Receipt> getReceipt() {
        return receipt;
    }

    public void setReceipt(List<Receipt> receipt) {
        this.receipt = receipt;
    }
}
