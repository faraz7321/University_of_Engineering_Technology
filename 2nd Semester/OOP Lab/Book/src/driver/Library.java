package library;

import java.io.IOException;
import java.util.*;

/**
 *
 * @author FARAZ AHMAD
 */
public class Library {

    private List<Magazine> magazines = new ArrayList<>();
    private List<TechnicalBook> technicalBook;
    private String libraryName;

    public Library() {

    }

    // GETTERS AND SETTERS.///////////////////////////////////////
    /**
     *
     * @return
     */
    public String getLibraryName() {
        return libraryName;
    }

    /**
     *
     * @param libraryName
     */
    public void setLibraryName(String libraryName) {
        this.libraryName = libraryName;
    }

    /**
     *
     * @return
     */
    public List<Magazine> getMagazines() {
        return magazines;
    }

    /**
     *
     * @param magazines
     */
    public void setMagazines(List<Magazine> magazines) {
        this.magazines = magazines;
    }

    /**
     *
     * @return
     */
    public List<TechnicalBook> getTechnicalBook() {
        return technicalBook;
    }

    /**
     *
     * @param technicalBook
     */
    public void setTechnicalBook(List<TechnicalBook> technicalBook) {
        this.technicalBook = technicalBook;
    }

    // PUBLIC METHODS.////////////////////////////////////////////
    /**
     *
     * @param b
     * @return
     */
    public boolean addMagazine(Magazine b) {
        magazines.add(b);

        return true;
    }

    /**
     *
     * @param iisbn
     * @return
     */
    public boolean deleteMagazine(String iisbn) {
        boolean flag = false;

        return flag;
    }

    /**
     *
     * @param isbn
     * @param b
     * @return
     */
    public boolean editMagazine(String isbn, Magazine b) {
        boolean flag = false;

        return flag;
    }

    /**
     *
     * @param titleText
     * @return
     */
    public List<Magazine> searchMagazineByTitle(String titleText) {
        return magazines;

    }

    /**
     *
     * @param authorText
     * @return
     */
    public List<Magazine> searchMagazineByAuthor(String authorText) {
        return magazines;

    }

    /**
     *
     * @param b
     * @return
     */
    public boolean addTechnicalBook(TechnicalBook b) {
        return false;

    }

    /**
     *
     * @param isbn
     * @return
     */
    public boolean deleteTechnicalBook(String isbn) {
        return false;

    }

    /**
     *
     * @param isbn
     * @param b
     * @return
     */
    public boolean editTechnicalBook(String isbn, TechnicalBook b) {
        return false;

    }

    /**
     *
     * @param titleText
     * @return
     */
    public List<TechnicalBook> searchTechnicalBookByTitle(String titleText) {
        return technicalBook;

    }

    /**
     *
     * @param authorText
     * @return
     */
    public List<TechnicalBook> searchTechnicalBookByAuthor(String authorText) {
        return technicalBook;

    }

    public int index(String isbn) {
        int index = 0;
        for (int i = 0; i <= magazines.size(); i++) {
            if (isbn.equals(magazines.get(i).getISBN())) {
                index = i;
            }
        }
        return index;
    }

    /**
     *
     * @throws java.io.IOException
     */
    public void saveData() throws IOException {

        /*
         * FileWriter obj = new FileWriter("BookData.txt"); Magazine mag = new
         * Magazine();
         *
         * for (int i = 0; i < magazines.size(); i++) { mag = new Magazine(); mag =
         * magazines.get(i); obj.write(mag.getTitle() + ";" + mag.getISBN() + ";" +
         * mag.getMonthOfPublish() + ";"); for (int j = 0; j <= mag.editiorSize(mag);
         * i++) { obj.write(mag.getEditors().get(i) + ","); } } obj.close();
         */
    }

    /**
     *
     * @throws java.io.FileNotFoundException
     */
    public void loadData() {
        /*
         * try { FileReader fr = new FileReader("BookData.txt"); BufferedReader br = new
         * BufferedReader(fr); String line = br.readLine(); do { List<String> li = new
         * ArrayList<String>(); li.add("Faraz"); li.add("Ahmed"); String arr[] =
         * line.split(";"); Magazine mag = new Magazine(); mag.setTitle(arr[0]);
         * mag.setISBN(arr[1]); mag.setMonthOfPublish(Integer.parseInt(arr[2]));
         * mag.setEditors(arr[3]);
         *
         * this.magazines.add(mag); } while (line != null); fr.close(); br.close(); }
         * catch (Exception ex) {
         *
         * }
         */

    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.print("Heloo");
        Dashboard d = new Dashboard();
        d.setVisible(true);
    }
}
