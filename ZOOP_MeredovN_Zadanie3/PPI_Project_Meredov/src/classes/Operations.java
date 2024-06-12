package classes;

import java.util.ArrayList;
import java.util.List;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;

import classes.hallclases.Classic;
import classes.hallclases.Gold;
import classes.hallclases.Platinum;
import classes.personal.*;

public class Operations implements DataOperations {
    private boolean adminlog = false;
    private int rental_period;
    private int count_of_ticket;
    private String name_of_hall;
    private String name_surname;
    private int profit;
    private int expenses;
    Classic classicHall = new Classic();
    Gold goldHall = new Gold();
    Platinum platinumHall = new Platinum();
    Service service = new Service("0", 0, 0, "0", "0","0");
    String CurrentLogin;


    public Operations(String CurrentLogin) {
        this.CurrentLogin = CurrentLogin;
    }

    public boolean getAdminlog() {
        return adminlog;
    }
    public int getRental_period() {
        return rental_period;
    }
    public int getCount_of_ticket() {
        return count_of_ticket;
    }
    public String getName_of_hall() {
        return name_of_hall;
    }
    public String getNameSurname() {
        return name_surname;
    }
    public int getProfit() {
        return profit;
    }
    public int getExpenses() {
        return expenses;
    }
    public void setAdminlog(boolean adminlog) {
        this.adminlog = adminlog;
    }
    public void setRental_period(int rental_period) {
        this.rental_period = rental_period;
    }
    public void setCount_of_ticket(int count_of_ticket) {
        this.count_of_ticket = count_of_ticket;
    }
    public void setName_of_hall(String name_of_hall) {
        this.name_of_hall = name_of_hall;
    }
    public void setProfit(int profit) {
        this.profit = profit;
    }
    public void setExpenses(int expenses) {
        this.expenses = expenses;
    }
    public void setNameSurname(String name_surname) {
        this.name_surname = name_surname;
    }
    public void calculateProfit(String hallName) {
        int profit = getCount_of_ticket() * getRental_period();
        setProfit(profit);
    }
    public void calculateExpenses(String hallName) {
        double expenses = 0;
        if ("Classic".equals(hallName)) {
            expenses = getCount_of_ticket() * classicHall.getExpenses();
        } else if ("Gold".equals(hallName)) {
            expenses = getCount_of_ticket() * goldHall.getExpenses();
        } else if ("Platinum".equals(hallName)) {
            expenses = getCount_of_ticket() * platinumHall.getExpenses();
        }
        setExpenses((int) expenses);
    }
    public void writeFile() {
        calculateProfit(getName_of_hall());
        calculateExpenses(getName_of_hall());
        String fileName = "Buyers_list.txt";
        String data = getNameSurname() + ";" + getName_of_hall() + ";" + getCount_of_ticket() + ";" + getRental_period() + ";" + getProfit() + ";" + getExpenses() + "\n";

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))) {
            writer.write(data);
            System.out.println("Data has been written to the file.");
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }
    }
    public void readFile() {
        String fileName = "Buyers_list.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            if(!getAdminlog()) {
                System.out.println("-------CUSTOMER-------");
            }else if (getAdminlog()){
                System.out.println("---WELCOME_ADMIN----");
            }
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                String nameSurname = parts[0];
                String hallName = parts[1];
                int ticketCount = Integer.parseInt(parts[2]);
                int rentalPeriod = Integer.parseInt(parts[3]);
                int profit = Integer.parseInt(parts[4]);
                int expenses = Integer.parseInt(parts[5]);

                if(!getAdminlog()) {
                    System.out.println("Name & Surname: " + nameSurname);
                    System.out.println("Hall type: " + hallName);
                    System.out.println("TicketCount: " + ticketCount);
                    System.out.println("RentalPeriod: " + rentalPeriod + " h ");
                    System.out.println("------------------------");
                }else if (getAdminlog()){
                    System.out.println("Name & Surname: " + nameSurname);
                    System.out.println("Hall type: " + hallName);
                    System.out.println("TicketCount: " + ticketCount);
                    System.out.println("RentalPeriod: " + rentalPeriod + " h ");
                    System.out.println("Profit: " + profit + " EUR ");
                    System.out.println("Expenses: " + expenses + " EUR ");
                    System.out.println("------------------------");
                }
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }
    public void printTickets() {
        String fileName = "Buyers_list.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            int k = 0;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                String nameSurname = parts[0];
                String hallName = parts[1];
                int ticketCount = Integer.parseInt(parts[2]);
                int rentalPeriod = Integer.parseInt(parts[3]);
                int profit = Integer.parseInt(parts[4]);
                int expenses = Integer.parseInt(parts[5]);
                if (nameSurname.equals(this.CurrentLogin)) {
                    k++;
                    System.out.println("Username: " + nameSurname + " | "  + hallName + " hall| " + ticketCount + "ks | " + rentalPeriod + "h  ");
                } else if(k == 0){
                    System.err.println(" You dont have any purchased tickets :( ");
                }
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }
    public void calculateNumOfPlaces(){
        String fileName = "Buyers_list.txt";
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                String nameSurname = parts[0];
                String hallName = parts[1];
                int ticketCount = Integer.parseInt(parts[2]);
                int rentalPeriod = Integer.parseInt(parts[3]);
                int profit = Integer.parseInt(parts[4]);
                int expenses = Integer.parseInt(parts[5]);

                if ("Classic".equals(hallName)){
                    classicHall.SetAktualpl(classicHall.GetAktualpl()-ticketCount);
                }else if ("Gold".equals(hallName)){
                    goldHall.SetAktualpl(goldHall.GetAktualpl()-ticketCount);
                } else if ("Platinum".equals(hallName)) {
                    platinumHall.SetAktualpl(platinumHall.GetAktualpl()-ticketCount);
                }
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
        System.out.println(classicHall.GetAktualpl());
        System.out.println(goldHall.GetAktualpl());
        System.out.println(platinumHall.GetAktualpl());

    }
    public int getTotalAvailableSeats() {
        int classicAvailable = classicHall.GetAktualpl();
        int goldAvailable = goldHall.GetAktualpl();
        int platinumAvailable = platinumHall.GetAktualpl();

        return classicAvailable + goldAvailable + platinumAvailable;
    }
    public List<String> findAdminLogin(String enteredLogin) {
        String fileName = "AdminList.txt";
        List<String> adminLogins = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(";");
                String nameSurname = parts[0];
                int age = Integer.parseInt(parts[1]);
                String rank = parts[2];
                String adminlog = parts[3];
                String adminpass = parts[4];
                if (adminlog.equals(enteredLogin)) {
                    String adminInfo = nameSurname + ";" + age + ";" + rank + ";" + adminlog + ";" + adminpass;
                    adminLogins.add(adminInfo);                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return adminLogins;
    }
    public void printAdmins(String loadrank){
        String fileName = "AdminList.txt";
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(";");
                String nameSurname = parts[0];
                int age = Integer.parseInt(parts[1]);
                String rank = parts[2];
                String adminlog = parts[3];
                String adminpass = parts[4];

                switch (loadrank) {
                    case "Unior" -> System.out.println(rank + ": "+ nameSurname + " " + age + "years   ");
                    case "Middle" -> {
                        if (rank.equals("Unior")) {
                            System.out.println(rank + ": "+ nameSurname + " " + age + "years   " + "High level:  " + "login:" + adminpass + "  password:" + adminlog);
                        } else {
                            System.out.println(rank + ": "+ nameSurname + " " + age + "years   ");
                        }
                    }
                    case "Senior" -> {
                        if (rank.equals("Unior")) {
                            System.out.println(rank + ": "+ nameSurname + " " + age + "years   " + "High level:  " + "login:" + adminpass + "  password:" + adminlog);
                        } else if (rank.equals("Middle")){
                            System.out.println(rank + ": "+ nameSurname + " " + age + "years   " + "High level:  " + "login:" + adminpass + "  password:" + adminlog);
                        } else {
                            System.out.println(rank + ": "+ nameSurname + " " + age + "years   ");
                        }
                    }
                }

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void editBuyersList(String enteredName, String enteredType, String enteredData) {
        String filePath = "Buyers_list.txt";
        String tempFilePath = "Buyers_list_temp.txt";

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath));
             BufferedWriter writer = new BufferedWriter(new FileWriter(tempFilePath))) {

            String currentLine;
            while ((currentLine = reader.readLine()) != null) {
                String[] parts = currentLine.split(";");
                if (parts.length == 6 && parts[0].equals(enteredName)) {
                    switch (enteredType) {
                        case "login" -> parts[0] = enteredData;
                        case "halltype" -> parts[1] = enteredData;
                        case "tickets" -> parts[2] = enteredData;
                        case "hours" -> parts[3] = enteredData;
                    }
                    currentLine = String.join(";", parts);
                }
                writer.write(currentLine);
                writer.newLine();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            Files.deleteIfExists(Path.of(filePath));
            Files.move(Path.of(tempFilePath), Path.of(filePath), StandardCopyOption.REPLACE_EXISTING);
            System.out.println("Rewriting was successful!");
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("Failed to rewrite the file.");
        }
    }
}