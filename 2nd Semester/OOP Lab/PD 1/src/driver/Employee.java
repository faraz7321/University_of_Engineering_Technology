package driver;

/**
 *
 * @author Faraz Ahmad
 */
public class Employee {

    private String name;
    private String desig;
    private String city;
    private String dob;
    private String empID;
    private String email;
    private String gender;
    private static int previousID = 0;

    public Employee() {
        String name = "";
        String desig = "";
        String city = "";
        String dob = "";
        String empID = "";
        String email = "";
        String gender = "";
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getDesig() {
        return desig;
    }

    public void setDesig(String desig) {
        this.desig = desig;
    }

    public String getDob() {
        return dob;
    }

    public void setDob(String dob) {
        this.dob = dob;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getEmpID() {
        return empID;
    }

    public void setEmpID(String empID) {
        this.empID = empID;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void createEmployee(String name, String desig, String city, String dob, String empID, String email, String gender) {

        previousID++;
        String val = String.valueOf(previousID);
        setName(name);
        setDesig(desig);
        setCity(city);
        setDob(dob);
        setEmpID("EMP-" + val);
        setEmail(email);
        setGender(gender);

    }

    public static void decrementID() {
        previousID--;
    }
}
