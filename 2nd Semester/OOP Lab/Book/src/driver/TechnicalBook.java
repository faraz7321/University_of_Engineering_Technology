package library;

import java.util.ArrayList;

/**
 *
 * @author Faraz Ahmad
 */
public class TechnicalBook extends Book {

    private ArrayList<String> authors;
    private String edition;

    /**
     *
     * @return
     */
    public ArrayList<String> getAuthors() {
        return authors;
    }

    /**
     *
     * @param authors
     */
    public void setAuthors(ArrayList<String> authors) {
        this.authors = authors;
    }

    /**
     *
     * @return
     */
    public String getEdition() {
        return edition;
    }

    /**
     *
     * @param edition
     */
    public void setEdition(String edition) {
        this.edition = edition;
    }

    @Override
    public String toString() {
        String x = "";
        return x;
    }

}
