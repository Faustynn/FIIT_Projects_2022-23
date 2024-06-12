package classes;

import java.util.List;

public interface DataOperations {
    void writeFile();
    void readFile();
    void printTickets();
    void calculateNumOfPlaces();
    int getTotalAvailableSeats();
    List<String> findAdminLogin(String enteredLogin);
    void printAdmins(String loadrank);
    void editBuyersList(String enteredName, String enteredType, String enteredData);
    boolean getAdminlog();
    int getRental_period();
    int getCount_of_ticket();
    String getName_of_hall();
    String getNameSurname();
    int getProfit();
    int getExpenses();
    void setAdminlog(boolean adminlog);
    void setRental_period(int rental_period);
    void setCount_of_ticket(int count_of_ticket);
    void setName_of_hall(String name_of_hall);
    void setProfit(int profit);
    void setExpenses(int expenses);
    void setNameSurname(String name_surname);
    void calculateProfit(String hallName);
    void calculateExpenses(String hallName);
}
