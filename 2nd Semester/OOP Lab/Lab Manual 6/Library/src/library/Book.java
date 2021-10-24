package library;

/**
 *
 * @author Faraz Ahmad
 */
public class Book {

    private String booktitle;
    private String ISBN;
    private String bookStatus;

    public String getBookStatus() {
        return bookStatus;
    }

    public void setBookStatus(String bookStatus) {
        this.bookStatus = bookStatus;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String iSBN) {
        ISBN = iSBN;
    }

    public String getTitle() {
        return booktitle;
    }

    public void setTitle(String title) {
        this.booktitle = title;
    }

    @Override
    public String toString() {
        String x = "";
        return x;
    }

    public void bindBook() {

    }

    public int index(String isbn) {
        int index = 0;

        return index;
    }

}
