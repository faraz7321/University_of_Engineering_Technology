package driver;

import java.util.*;

/**
 *
 * @author Faraz Ahmad
 */
public class Driver {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here

        ArrayList< Attendance> attendance = new ArrayList<Attendance>();
        Admin admin = new Admin(attendance);

        new Login().setVisible(true);

    }

}
