public class Example3 {
    class Student {
        public int Id;
        public String name;
    }

    public static void main(String[] args) {
        String strMain = "I am Student of Computer Science";
        String[] splitArr = strMain.split(" ");
        for (int i = 0; i < splitArr.length; i++) {
            System.out.println(splitArr[i]);
        }
    }
}