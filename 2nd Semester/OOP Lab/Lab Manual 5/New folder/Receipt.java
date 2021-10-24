import java.sql.Timestamp;

public class Receipt {
    private Car car;
    private Timestamp time;
    private double tollPaid;

    public Car getCar() {
        return car;
    }

    public void setCar(Car car) {
        this.car = car;
    }

    public Timestamp getTime() {
        time = new Timestamp(System.currentTimeMillis());
        return time;
    }

    public void setTime(Timestamp time) {
        this.time = time;
    }

    public double getTollPaid() {
        return tollPaid;
    }

    public void setTollPaid(double tollPaid) {
        this.tollPaid = tollPaid;
    }

}
