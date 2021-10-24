package library;

/**
 *
 * @author Faraz Ahmad
 */
public class Book {

    private String booktitle;
    private String ISBN;
    private String bookStatus;

    //public Book(String title, String author) {
    //}
    /**
     *
     * @return
     */
    public String getBookStatus() {
        return bookStatus;
    }

    /**
     *
     * @param bookStatus
     */
    public void setBookStatus(String bookStatus) {
        this.bookStatus = bookStatus;
    }

    /**
     *
     * @return
     */
    public String getISBN() {
        return ISBN;
    }

    /**
     *
     * @param iSBN
     */
    public void setISBN(String iSBN) {
        ISBN = iSBN;
    }

    /**
     *
     * @return
     */
    public String getTitle() {
        return booktitle;
    }

    /**
     *
     * @param title
     */
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
