import java.util.ArrayList;
import java.util.Scanner;

public class Task5 {
    class PastVisits {
        private String DateVisited;
        private String MedicinePrescribed;
        private String Symptoms;

        public String getDateVisited() {
            return DateVisited;
        }

        public void setDateVisited(String dateVisited) {
            DateVisited = dateVisited;
        }

        public String getMedicinePrescribed() {
            return MedicinePrescribed;
        }

        public void setMedicinePrescribed(String medicinePrescribed) {
            MedicinePrescribed = medicinePrescribed;
        }

        public String getSymptoms() {
            return Symptoms;
        }

        public void setSymptoms(String symptoms) {
            Symptoms = symptoms;
        }

    }

    class PatientRecords {
        private String Name;
        private int Visits;
        ArrayList<PastVisits> pv = new ArrayList<>();

        public String getName() {
            return Name;
        }

        public void setName(String name) {
            Name = name;
        }

        public ArrayList<PastVisits> getPv() {
            return pv;
        }

        public void setPv(ArrayList<PastVisits> pv) {
            this.pv = pv;
        }
    }

    class PatientsQueue {
        private int NumOfPatient;

    }

    public static void DisplayFirstPatient() {

    }

    public static void FindPatients(String RequiredDate) {

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.println("1> Add Patient Record\n" + "2> Next Patient\n" + "3> Search Patients\n" + "Input: ");
            String input = scanner.nextLine();
            if (input.equals("1")) {

            } else if (input.equals("2")) {

            } else if (input.equals("3")) {

            }
        } while (input.equals("0"));

    }
}
