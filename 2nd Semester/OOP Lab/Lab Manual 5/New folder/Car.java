public class Car {

    private String model;
    private String make;
    private String carNumber;
    private String engineCapacity;
    private String seatingCapacity;
    private String driverName;
    private boolean isGovtVehicle;

    // CONSTRUCTOR.//
    public Car(String model, String make2, String carNumber, String engineCapacity2, String seatingCapacity2,
            String driverName, boolean isGovtVehicle) {
        this.model = model;
        this.make = make2;
        this.carNumber = carNumber;
        this.driverName = driverName;
        this.engineCapacity = engineCapacity2;
        this.isGovtVehicle = isGovtVehicle;
        this.seatingCapacity = seatingCapacity2;
    }

    public Car() {

    }

    public int calculateToll() {
        int toll = 0;
        toll = toll + 10;
        if (isGovtVehicle) {
            toll = 0;
            return toll;
        } else {
            int engine = Integer.parseInt(engineCapacity);
            if (engine <= 1000) {

            } else if (engine > 1000 && engine <= 1300) {
                toll = toll + engine / 100;
            } else if (engine > 1300 && engine <= 1800) {
                toll = toll + engine / 65;
            } else if (engine > 1800) {
                toll = toll + engine / 50;
            }

            if (Integer.parseInt(seatingCapacity) <= 4) {

            } else {
                toll = toll + (Integer.parseInt(seatingCapacity) - 4) * 5;
            }
            if (Integer.parseInt(make) >= 2018) {

            } else {
                toll = toll + (2018 - Integer.parseInt(make)) * 2;
            }
        }

        return toll;
    }

    // GETTER AND SETTERS.//
    public String getModel() {
        return model;
    }

    public String getMake() {
        return make;
    }

    public String getCarNumber() {
        return carNumber;
    }

    public String getDriverName() {
        return driverName;
    }

    public String getEngineCapacity() {
        return engineCapacity;
    }

    public String getSeatingCapacity() {
        return seatingCapacity;
    }

    public boolean getisGovtVehicle() {
        return isGovtVehicle;
    }

    ////////////////////////// VALIDATORS..//////////////////////////////////

    static boolean isValidModel(String model) {
        boolean flag = false;
        if (model.matches("[a-zA-Z_]+")) {
            flag = true;
        }
        return flag;
    }

    static boolean isValidMake(int make) {
        boolean flag = false;
        if (make >= 1900 && make <= 2021) {
            flag = true;
        }
        return flag;
    }

    public static boolean isValidCarNumber(String carNumber) {
        boolean flag = false;
        char[] c = carNumber.toCharArray();

        if (c[0] >= 'A' && c[0] <= 'Z' && c[1] >= 'A' && c[1] <= 'Z' && c[2] >= 'A' && c[2] <= 'Z') {
            if (c[3] == '-' && c[6] == '-') {
                if (c[4] >= '0' && c[4] <= '9' && c[5] >= '0' && c[5] <= '9') {
                    for (int i = 8; i < c.length; i++) {
                        if (c[i] >= '0' && c[i] <= '9') {
                            flag = true;
                        }
                    }
                }
            }
        }

        return flag;
    }

    static boolean isValidDriverName(String driverName) {
        boolean flag = false;
        if (driverName.matches("[a-zA-Z_]+")) {
            flag = true;
        }
        return flag;
    }

    static boolean isValidEngineCapacity(int engineCapacity) {
        boolean flag = false;
        if (engineCapacity >= 660 && engineCapacity <= 6000) {
            flag = true;
        }
        return flag;
    }

    static boolean isValidSeatingCapacity(int seatingCapacity) {
        boolean flag = false;
        if (seatingCapacity >= 2 && seatingCapacity <= 30) {
            flag = true;
        }
        return flag;
    }

    static boolean isValidIsGovtVehicle(String carNumber) {
        boolean isGovtVehicle = false;
        char[] c = carNumber.toCharArray();
        if (c[2] == 'G') {
            isGovtVehicle = true;
        }
        return isGovtVehicle;
    }

}
