package classes.users;
import java.io.*;
import java.util.*;

public class Admin {
    private final String adminLogin;
    private final String adminPassword;
    private final String rank;

    private Customers[] customers;


    public Admin(String adminLogin, String adminPassword,String rank, Customers[] customers) {
        this.adminLogin = adminLogin;
        this.adminPassword = adminPassword;
        this.customers = customers;
        this.rank = rank;
    }

    //доработать
    public void AdminDatalist(String rank) {
        try (BufferedReader reader = new BufferedReader(new FileReader("AdminList.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                if (parts.length >= 5) {
                    String name = parts[0];
                    String age = parts[1];
                    String userRank = parts[2];
                    String login = parts[3];
                    String loginPass = parts[4];

                    if (userRank.equals(rank)) {
                        System.out.println("Name: " + name);
                        System.out.println("Age: " + age);
                        System.out.println("Rank: " + userRank);
                        System.out.println("Login: " + login);
                        System.out.println("LoginPass: " + loginPass);
                        System.out.println();
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void writeAdminDataList(String rank, String name, String age, String login) {
        List<String> lines = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader("AdminList.txt")) ) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                if (parts.length >= 4) {
                    String userRank = parts[2];

                    if (userRank.equals(rank)) {
                        line = name + ";" + age + ";" + userRank + ";" + login + ";" + parts[4];
                    }
                }
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("AdminList.txt"))) {
            for (String line : lines) {
                writer.write(line);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public String getAdminLogin() {
        return adminLogin;
    }
    public String getAdminPassword() {
        return adminPassword;
    }

    public void addCustomer(Customers newCustomer) {
        Customers[] newCustomersArray = new Customers[customers.length + 1];
        System.arraycopy(customers, 0, newCustomersArray, 0, customers.length);
        newCustomersArray[customers.length] = newCustomer;
        customers = newCustomersArray;
    }

    public void removeCustomer(String name, String surname) {
        for (int i = 0; i < customers.length; i++) {
            if (customers[i].getName().equals(name) && customers[i].getSurname().equals(surname)) {
                Customers[] newCustomersArray = new Customers[customers.length - 1];
                System.arraycopy(customers, 0, newCustomersArray, 0, i);
                System.arraycopy(customers, i + 1, newCustomersArray, i, customers.length - i - 1);
                customers = newCustomersArray;
                break;
            }
        }
    }


}
