interface Person {
    String name = "";
    int age = 0;
    String gender = "";

    public default void print() {
        System.out.println("Person");
    }
}

interface Employee extends Person {
    int salary = 0;
}

interface Teacher extends Employee {
    String department = "Computer Science";
}

interface Student extends Person {
    int fees = 0;
    String regNo = "2020-CS-144";
}

interface PostgraduateStudent extends Student {
    public default void print() {
        System.out.println("Postgraduate Assisstant");
    }
}

interface UndergraduateStudent extends Student {
    public default void print() {
        System.out.println("Undergraduate Assisstant");
    }
}

class GraduateAssisstant implements Teacher, PostgraduateStudent {
    public void print() {
        System.out.println("Graduate Assisstant");
    }
}

public class Task2 {

    /**
     *
     * @param args
     */
    public static void main(String[] args) {

        // Teacher p = (Teacher) new Person();
        // Person obj = new Teacher();
        // obj.print(); // Prints "Person" .//
    }
}
