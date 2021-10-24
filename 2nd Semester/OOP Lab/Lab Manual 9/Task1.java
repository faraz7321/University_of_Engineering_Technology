abstract class Vehicle {
    abstract void draw();

    String regNo;
    String model;
    String color;
    String seatingCapacity;

}

class Motorbike extends Vehicle {
    public void draw() {
        System.out.println("Drawing Motorbike");
    }
}

abstract class Car extends Vehicle {
    abstract void draw();
}

class SaloonCar extends Car {
    public void draw() {
        System.out.println("Drawing Saloon Car");
    }
}

class EstateCar extends Car {
    public void draw() {
        System.out.println("Drawing Estate Car");
    }
}

public class Task1 {
    public static void main(String[] args) {

        Vehicle saloonVehicle = new SaloonCar();
        saloonVehicle.draw(); // Draws Saloon Car .//
    }
}
