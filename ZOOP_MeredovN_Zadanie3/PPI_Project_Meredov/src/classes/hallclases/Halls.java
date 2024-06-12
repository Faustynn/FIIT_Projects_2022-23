package classes.hallclases;
public class Halls {
    private double price;
    private int numbofpl;
    private int aktualpl;
    private double expenses;
    private int staffCount;

    // Konstructor
    public Halls(double price, int numbofpl,int aktualpl, double expenses, int staffCount) {
        this.price = price;
        this.numbofpl = numbofpl;
        this.aktualpl = aktualpl;
        this.expenses = expenses;
        this.staffCount = staffCount;
    }

    public double getPrice() {
        return price;
    }
    public void setPrice(double price) {
        this.price = price;
    }

    public int getnumbofpl() {
        return numbofpl;
    }
    public void setnumbofpl(int numbofpl) {
        this.numbofpl = numbofpl;
    }

    public int GetAktualpl() {
        return aktualpl;
    }
    public void SetAktualpl(int aktualpl) {
        this.aktualpl = aktualpl;
    }

    public double getExpenses() {
        return expenses;
    }
    public void setExpenses(double expenses) {
        this.expenses = expenses;
    }

    public int getStaffCount() {
        return staffCount;
    }
    public void setStaffCount(int staffCount) {
        this.staffCount = staffCount;
    }





}