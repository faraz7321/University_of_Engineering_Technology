package library;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

/**
 *
 * @author FARAZ AHMAD
 */
public class Library {

    public List<Book> book = new ArrayList<>();
    public List<Magazine> mag = new ArrayList<>();
    public List<TechnicalBook> tb = new ArrayList<>();
    public String libraryName;

    public Library() {

    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Dashboard d = new Dashboard();
        d.setVisible(true);
    }

    public String getLibraryName() {
        return libraryName;
    }

    public void setLibraryName(String libraryName) {
        this.libraryName = libraryName;
    }

    public boolean addMagazine(Magazine b) {
        mag.add(b);

        return true;
    }

    public boolean deleteMagazine(String iisbn) {
        boolean flag = false;

        return flag;
    }

    public boolean editMagazine(String isbn, Magazine b) {
        boolean flag = false;

        return flag;
    }

    public List<Magazine> searchMagazineByTitle(String titleText) {
        return mag;

    }

    public List<Magazine> searchMagazineByAuthor(String authorText) {
        return mag;

    }

    public boolean addTechnicalBook(TechnicalBook b) {
        tb.add(b);
        return true;

    }

    public boolean deleteTechnicalBook(String isbn) {
        return false;

    }

    public boolean editTechnicalBook(String isbn, TechnicalBook b) {
        return false;

    }

    public List<TechnicalBook> searchTechnicalBookByTitle(String titleText) {
        List<TechnicalBook> techh = new ArrayList<>();
        TechnicalBook e = new TechnicalBook();
        for (int i = 0; i < tb.size(); i++) {
            if (titleText.equals(tb.get(i).getTitle())) {
                e.setEdition(tb.get(i).getEdition());
                e.setAuthors(tb.get(i).getAuthors());
                e.setTitle(tb.get(i).getTitle());
                e.setISBN(tb.get(i).getISBN());
                techh.add(e);
            }
        }
        return techh;

    }

    public List<TechnicalBook> searchTechnicalBookByAuthor(String authorText) {
        List<TechnicalBook> techh = new ArrayList<>();
        TechnicalBook e = new TechnicalBook();
        for (int i = 0; i < tb.size(); i++) {
            if (authorText.equals(tb.get(i).getTitle())) {
                e.setEdition(tb.get(i).getEdition());
                e.setAuthors(tb.get(i).getAuthors());
                e.setTitle(tb.get(i).getTitle());
                e.setISBN(tb.get(i).getISBN());
                techh.add(e);
            }
        }
        return techh;
        // return tb;

    }

    public int index(String isbn) {
        int index = 0;
        for (int i = 0; i <= mag.size(); i++) {
            if (isbn.equals(mag.get(i).getISBN())) {
                index = i;
            }
        }
        return index;
    }

    public void saveData() {
        try {
            try (FileWriter myWriter = new FileWriter("magazinesData.txt")) {
                for (int i = 0; i < mag.size(); i++) {
                    Magazine e = mag.get(i);
                    myWriter.write(e.getTitle() + "," + e.getISBN() + "," + e.getMonthOfPublish() + "," + e.getEditors() + "," + e.getBookStatus() + "\n");
                }
            }
            //System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
        }
        try {
            try (FileWriter myWriter = new FileWriter("techBookData.txt")) {
                for (int i = 0; i < tb.size(); i++) {
                    TechnicalBook e = tb.get(i);
                    myWriter.write(e.getTitle() + "," + e.getISBN() + "," + e.getAuthors() + "," + e.getEdition() + "," + e.getBookStatus() + "\n");
                }
            }
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
        }
    }

    public void loadData() {
        mag.removeAll(mag);
        tb.removeAll(tb);
        try {
            Scanner br = new Scanner(new File("magazinesData.txt"));
            while (br.hasNextLine()) {
                String line = br.nextLine();
                String arr[] = line.split(",");
                Magazine magz = new Magazine();
                magz.setTitle(arr[0]);
                magz.setISBN(arr[1]);
                magz.setMonthOfPublish(arr[2]);
                magz.setEditors(arr[3]);
                magz.setBookStatus(arr[4]);
                mag.add(magz);
                // System.out.println(line);
                //br.close();
            }

        } catch (Exception ex) {
        }
        //br.close();
        //TechBookData
        try {
            Scanner br = new Scanner(new File("techBookData.txt"));
            while (br.hasNextLine()) {
                String line = br.nextLine();
                String arr[] = line.split(",");
                TechnicalBook tech = new TechnicalBook();
                tech.setTitle(arr[0]);
                tech.setISBN(arr[1]);
                tech.setAuthors(arr[2]);
                tech.setEdition(arr[3]);
                tech.setBookStatus(arr[4]);
                tb.add(tech);
                // System.out.println(line);
                //br.close();
            }

        } catch (Exception ex) {
        }

    }
}
