package driver;

import java.util.*;

/**
 *
 * @author Faraz Ahmad
 */
public class Attendance {

    ArrayList<TodayAtt> attend;
    private Employee emp;
    Employee employee = new Employee();

    public Attendance(Employee emp) {
        this.employee = emp;
        attend = new ArrayList<>();
    }

    public void setAttendance(String date, String time, String status) {

        attend.add(new TodayAtt(date, time, status));
    }

    public String getAttendance() {
        String result = "";
        for (int i = 0; i < attend.size(); i++) {
            result += attend.get(i);
            result += "\n";
        }
        return result;
    }

    public Employee getEmp() {
        return emp;
    }

    public void setEmp(Employee emp) {
        this.emp = emp;
    }

    public Attendance() {

    }

}
