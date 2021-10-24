package library;

/**
 *
 * @author Faraz Ahmad
 */
public class Magazine extends Book {

    private String editors;
    private int monthOfPublish;

    /**
     *
     * @return
     */
    public String getEditors() {
        return editors;
    }

    /**
     *
     * @param editors
     */
    public void setEditors(String editors) {
        this.editors = editors;
    }

    /**
     *
     * @return
     */
    public int getMonthOfPublish() {
        return monthOfPublish;
    }

    /**
     *
     * @param monthOfPublish
     */
    public void setMonthOfPublish(int monthOfPublish) {
        this.monthOfPublish = monthOfPublish;
    }

    @Override
    public String toString() {
        String x = "";
        return x;
    }

}
