/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package driver;

/**
 *
 * @author Faraz Ahmad
 */
public class TodayAtt {

    private String date;
    private String time;
    private String status;

    public String getDate() {
        return date;
    }

    public TodayAtt(String date, String time, String status) {

        this.date = date;
        this.status = status;
        this.time = time;
    }

    public String toString() {
        return "Date= " + date + "Time= " + time + "Status: " + status;

    }

    public TodayAtt() {

        this.date = "";
        this.status = "";
        this.time = "";
    }

    public String getStatus() {
        return status;
    }

    public String getTime() {
        return time;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public void setTime(String time) {
        this.time = time;
    }

}
