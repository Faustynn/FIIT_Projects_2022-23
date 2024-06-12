package classes.personal;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Service {
    private String nameSurname;
    private int age;
    private int salary;
    private String individualLogin;
    private String individualPass;
    private String rank;

    private static Service instance;

    public Service(String nameSurname, int age, int salary, String individualLogin, String individualPass,String rank) {
        this.nameSurname = nameSurname;
        this.age = age;
        this.salary = salary;
        this.individualLogin = individualLogin;
        this.individualPass = individualPass;
        this.rank = rank;
    }

    protected static Service getInstance() {
        if (instance == null) {
            instance = new Service("0", 0, 0, "0", "0","0");
        }
        return instance;
    }

    public String getNameSurname() {
        return nameSurname;
    }

    public int getAge() {
        return age;
    }

    public int getSalary() {
        return salary;
    }

    public String getIndividualLogin() {
        return individualLogin;
    }

    public String getIndividualPass() {
        return individualPass;
    }

    public String getRank(){
        return  rank;
    }

    public void setRank(String rank) {
        this.rank = rank;
    }
    public void setNameSurname(String nameSurname) {
        this.nameSurname = nameSurname;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public void setIndividualLogin(String individualLogin) {
        this.individualLogin = individualLogin;
    }

    public void setIndividualPass(String individualPass) {
        this.individualPass = individualPass;
    }

    public final double calculateBonus() {
        double bonus = 0.1 * salary;
        return bonus;
    }

    public void editlogAdmin(String enteredLog, String name, int age,String login, String loginPass) {
        Service service = new Service(name, age, 1000, enteredLog, loginPass, "Unior");
        Unior douwnCastingUnior = (Unior) service;

        String fileName = "AdminList.txt";
        List<String> modifiedLines = new ArrayList<>();

        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                String nameSurname = parts[0];
                int ages = Integer.parseInt(parts[1]);
                String rank = parts[2];
                String adminlog = parts[3];
                String adminpass = parts[4];

                if (adminlog.equals(login)) {
                    douwnCastingUnior.editloginUniorEvent(enteredLog);
                    adminlog = enteredLog;
                    login = enteredLog;
                }
                String modifiedLine = nameSurname + ";" + ages + ";" + rank + ";" + adminlog + ";" + adminpass;
                modifiedLines.add(modifiedLine);
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (String modifiedLine : modifiedLines) {
                writer.write(modifiedLine);
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }
    }
    public void editloginUniorEvent(String newLogin) {
        setIndividualLogin(newLogin);
        System.out.println(getNameSurname() + " your new LOGIN is " + newLogin);
    }

    public void editpassAdmin(String enteredPass, String name, int age, String login) {
        Unior unior;
        unior = new Unior(name, age, 1000, login, enteredPass, "Unior");
        Service upCastingUnior = (Service) unior;

        String fileName = "AdminList.txt";
        List<String> modifiedLines = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                String nameSurname = parts[0];
                int ages = Integer.parseInt(parts[1]);
                String rank = parts[2];
                String adminlog = parts[3];
                String adminpass = parts[4];

                if (nameSurname.equals(name)) {
                    upCastingUnior.editpassUniorEvent(enteredPass);
                    adminpass = enteredPass;
                }
                String modifiedLine = nameSurname + ";" + ages + ";" + rank + ";" + adminlog + ";" + adminpass;
                modifiedLines.add(modifiedLine);
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (String modifiedLine : modifiedLines) {
                writer.write(modifiedLine);
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }
    }
    public void editpassUniorEvent(String newPass) {
        setIndividualPass(newPass);
        System.out.println(getNameSurname() + " your new PASSWORD is " + newPass);
    }

}

