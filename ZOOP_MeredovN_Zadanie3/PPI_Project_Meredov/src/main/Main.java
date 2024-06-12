package main;

import java.util.List;
import java.util.Scanner;
import classes.hallclases.Classic;
import classes.hallclases.Gold;
import classes.hallclases.Platinum;
import classes.Operations;
import classes.personal.Service;
import classes.MySeparator;

public class Main {
    private final Classic classicHall;
    private final Gold goldHall;
    private final Platinum platinumHall;

    private final Service service;
    public Main(){
        classicHall = new Classic();
        goldHall = new Gold();
        platinumHall = new Platinum();
     //   Operations operations = new Operations(null);
        service = new Service("0", 0, 0, "0", "0","0");
    }

public void run(){
        System.out.println("Provided and created by Meredov Nazar for STU FIIT 2023 ZOOP_Project\n");
        System.out.println("1) Login => l");
        System.out.println("2) Buy tickets => b");
        System.out.println("3) View available places => s");
        System.out.println("4) End the program => e");

        Scanner in = new Scanner(System.in);
        char input1;
        String terminal;
        String enteredLogin = null;
        Operations operations = new Operations(enteredLogin);
        while (true) {
            do {
                System.out.println("Please enter your command:");
                String userInput = in.nextLine();
                if (userInput.length() == 1 && Character.isLetter(userInput.charAt(0))) {
                    input1 = Character.toLowerCase(userInput.charAt(0));
                    break;
                } else {
                    System.out.println("Error, please write a single letter from Aa to Zz");
                }
            } while (true);


            label:
            switch (input1) {
                case 'l':



                    System.out.println("If you want to go back, write e");
                    System.out.println("Write your Login:");
                    enteredLogin = in.nextLine();
                    List<String> adminInf= operations.findAdminLogin(enteredLogin);

                    if (adminInf.isEmpty()) {
                        if(enteredLogin.equals("e")){
                            break;
                        }else{
                            System.out.println("Write your password:");
                            String enteredPassword = in.nextLine();
                            System.out.println("Welcome dear customer!");
                            boolean j=true;
                            while (j){
                                System.out.println("Please write your command:");
                                System.out.println("i - information | b - busket | e - log-out");
                                terminal = in.nextLine();
                                switch (terminal){
                                    case "i":{
                                        System.out.println("Information about you:");
                                        System.out.println("Login: "+ enteredLogin + "\n  Password: " + enteredPassword);
                                        break;
                                    }
                                    case "b":{
                                        Operations operations2 = new Operations(enteredLogin);
                                        System.out.println("All purchased tickets:");
                                        operations2.printTickets();
                                        break;
                                    }
                                    case "e":{
                                        System.out.println("Log-out was sucsesful!");
                                        j=false;
                                        break;
                                    }
                                }
                            }
                        }
                    } else {
                        MySeparator separator = new MySeparator();
                        List<String> separatedAdminInf = separator.separate(adminInf.get(0));
                        String name = separatedAdminInf.get(0);
                        String age = separatedAdminInf.get(1);
                        String rank = separatedAdminInf.get(2);
                        String login = separatedAdminInf.get(3);
                        String loginPass = separatedAdminInf.get(4);
                        int ageInt = Integer.parseInt(age);

                        System.out.println("Write your ADMIN password:");
                        String enteredPassword = in.nextLine();

                        String input = "";
                        if (enteredPassword.equals(loginPass)) {
                            System.out.println("Welcome " + name);
                            System.out.println("Your interface lvl " +rank);
                            while (true){
                                switch (rank) {
                                    case "Unior" -> {
                                        System.out.println("Please write your command:");
                                        System.out.println("il - information list with all buyers | p - see all admin personal | rp - edit password/login | e - log-out");
                                        input = in.nextLine();
                                        switch (input) {
                                            case "il": {
                                                operations.readFile();
                                                break;
                                            }
                                            case "p": {
                                                operations.printAdmins(rank);
                                                break;
                                            }
                                            case "rp": {
                                                System.out.println("What you want reset? (l-login / p-password):");
                                                String reset = in.nextLine();
                                                if (reset.equals("l")){
                                                    System.out.println("Please write your new login:");
                                                    String newlogin = in.nextLine();
                                                    service.editlogAdmin(newlogin,name,ageInt,login,loginPass);
                                                    break;

                                                }else if (reset.equals("p")){
                                                    System.out.println("Please write your new password:");
                                                    String newpassord = in.nextLine();
                                                    service.editpassAdmin(newpassord,name,ageInt,loginPass);
                                                    break;
                                                }else {
                                                    System.err.println("Error,write l or p !!");
                                                    continue;
                                                }
                                            }
                                            case "e": {
                                                System.out.println("Log-out was successful!");
                                                break;
                                            }
                                        }
                                    }
                                    case "Middle" -> {
                                        System.out.println("Please write your command:");
                                        System.out.println("il - information list with all buyers* | p - see all admin personal* | rp - edit password/login | e - log-out");
                                        input = in.nextLine();
                                        switch (input) {
                                            case "il": {
                                                System.out.println("Please write your next command:");
                                                System.out.println("s - see list with all buyers | ed - edit buyers list");
                                                input = in.nextLine();
                                                switch (input){
                                                    case "s": {
                                                        operations.readFile();
                                                        break;
                                                    }
                                                    case "ed": {
                                                        System.out.println("Please write Registration Login:");
                                                        String enteredName = in.nextLine();
                                                        System.out.println("Write what you want change: (login,halltype,tickets,hours)");
                                                        String enteredType = in.nextLine();
                                                        System.out.println("Write your new Data:");
                                                        String enteredData = in.nextLine();
                                                        operations.editBuyersList(enteredName,enteredType,enteredData);
                                                    }
                                                }
                                                break;
                                            }
                                            case "p": {
                                                operations.printAdmins(rank);
                                                break;
                                            }
                                            case "rp": {
                                                System.out.println("What you want reset? (l-login / p-password):");
                                                String reset = in.nextLine();
                                                if (reset.equals("l")){
                                                    System.out.println("Please write your new login:");
                                                    String newlogin = in.nextLine();
                                                    service.editlogAdmin(newlogin,name,ageInt,login,loginPass);
                                                    break;

                                                }else if (reset.equals("p")){
                                                    System.out.println("Please write your new password:");
                                                    String newpassord = in.nextLine();
                                                    service.editpassAdmin(newpassord,name,ageInt,loginPass);
                                                    break;
                                                }else {
                                                    System.err.println("Error,write l or p !!");
                                                    continue;
                                                }
                                            }
                                            case "e": {
                                                System.out.println("Log-out was successful!");
                                                break;
                                            }
                                        }
                                    }
                                    case "Senior" -> {
                                        System.out.println("Please write your command:");
                                        System.out.println("il - information list with all buyers** | p - see all admin personal** | rp - edit password/login | e - log-out");
                                        input = in.nextLine();
                                        switch (input) {
                                            case "il": {
                                                System.out.println("Please write your next command:");
                                                System.out.println("s - see list with all buyers | ed - edit buyers list");
                                                input = in.nextLine();
                                                switch (input){
                                                    case "s": {
                                                        operations.readFile();
                                                        break;
                                                    }
                                                    case "ed": {
                                                        System.out.println("Please write Registration Login:");
                                                        String enteredName = in.nextLine();
                                                        System.out.println("Write what you want change: (login,halltype,tickets,hours)");
                                                        String enteredType = in.nextLine();
                                                        System.out.println("Write your new Data:");
                                                        String enteredData = in.nextLine();
                                                        operations.editBuyersList(enteredName,enteredType,enteredData);
                                                    }
                                                }
                                                break;
                                            }
                                            case "p": {
                                                operations.printAdmins(rank);
                                                break;
                                            }
                                            case "rp": {
                                                System.out.println("What you want reset? (l-login / p-password):");
                                                String reset = in.nextLine();
                                                if (reset.equals("l")){
                                                    System.out.println("Please write your new login:");
                                                    String newlogin = in.nextLine();
                                                    service.editlogAdmin(newlogin,name,ageInt,login,loginPass);
                                                    break;

                                                }else if (reset.equals("p")){
                                                    System.out.println("Please write your new password:");
                                                    String newpassord = in.nextLine();
                                                    service.editpassAdmin(newpassord,name,ageInt,loginPass);
                                                    break;
                                                }else {
                                                    System.err.println("Error,write l or p !!");
                                                    continue;
                                                }
                                            }
                                            case "e": {
                                                System.out.println("Log-out was successful!");
                                                break;
                                            }
                                        }
                                    }
                                }
                                if(input.equals("e")){
                                    break;
                                }
                            }
                        } else {
                            System.out.println("Error, please write correct password");
                            break;
                        }
                    }
                    break;
                case 'b':
                    System.out.println("If you want to go back, write e\n");
                    System.out.println("________________________________________________");
                    System.out.println("Hall:               Classic         Gold         Platinum");
                    System.out.println("Price:              " + classicHall.getPrice() + "€           " + goldHall.getPrice() + "€        " + platinumHall.getPrice()+ "€");
                    System.out.println("Number of places:   " + classicHall.GetAktualpl() + "/" + classicHall.getnumbofpl() + "         " + goldHall.GetAktualpl() + "/" + goldHall.getnumbofpl() + "        " + platinumHall.GetAktualpl() + "/" + platinumHall.getnumbofpl() );
                    System.out.println(operations.getTotalAvailableSeats());
              //      System.out.println("Expenses:           " + classicHall.getExpenses() + "€          " + goldHall.getExpenses() + "€       " + platinumHall.getExpenses()+ "€");
              //      System.out.println("Staff Count:        " + classicHall.getStaffCount() + "              " + goldHall.getStaffCount() + "            " + platinumHall.getStaffCount() );
                    System.out.println("________________________________________________");
                    System.out.println("Please Write your name and surname:");
                    operations.setNameSurname(in.nextLine());
                    System.out.println("Enter the type of hall what you want to buy:");
                    String type_of_hall = in.nextLine();
                    int input;


                    switch (type_of_hall) {
                        case "Classic": {
                            operations.setName_of_hall("Classic");
                            int currentAvailableTickets = classicHall.GetAktualpl();
                            System.out.println("Enter the number of tickets you want to buy:");
                            input = Integer.parseInt(in.nextLine());
                            operations.setCount_of_ticket(input);
                            if (input <= currentAvailableTickets) {
                                classicHall.SetAktualpl(currentAvailableTickets - input);
                            } else {
                                System.out.println("Not enough available tickets.");
                            }
                            break;
                        }
                        case "Gold": {
                            int currentAvailableTickets = goldHall.GetAktualpl();
                            operations.setName_of_hall("Gold");
                            System.out.println("Enter the number of tickets you want to buy:");
                            input = Integer.parseInt(in.nextLine());
                            operations.setCount_of_ticket(input);
                            if (input <= currentAvailableTickets) {
                                goldHall.SetAktualpl(currentAvailableTickets - input);
                            } else {
                                System.out.println("Not enough available tickets.");
                            }
                            break;
                        }
                        case "Platinum": {
                            operations.setName_of_hall("Platinum");
                            int currentAvailableTickets = platinumHall.GetAktualpl();
                            System.out.println("Enter the number of tickets you want to buy:");
                            input = Integer.parseInt(in.nextLine());
                            operations.setCount_of_ticket(input);
                            if (input <= currentAvailableTickets) {
                                platinumHall.SetAktualpl(currentAvailableTickets - input);
                            } else {
                                System.out.println("Not enough available tickets.");
                            }
                            break;
                        }
                        default:
                            System.out.println("Invalid hall type.\n");
                            break label;
                    }
                    System.out.println("Write the desired rental period (hours):");
                    input = Integer.parseInt(in.nextLine());
                    operations.setRental_period(input);
                    System.out.println("Tickets purchased successfully!");
                    System.out.println("Thanks for your visit & Enjoy the game :D\n");


                    operations.writeFile();

                    System.out.println("1) Login => l");
                    System.out.println("2) Buy tickets => b");
                    System.out.println("3) View available places => s");
                    System.out.println("4) End the program => e");
                    break;
                case 's':
                    System.out.println("________________________________________________");
                    System.out.println("Hall:               Classic         Gold         Platinum");
                    System.out.println("Price:              " + classicHall.getPrice() + "€           " + goldHall.getPrice() + "€        " + platinumHall.getPrice()+ "€");
                    System.out.println("Number of places:   " + classicHall.GetAktualpl() + "/" + classicHall.getnumbofpl() + "         " + goldHall.GetAktualpl() + "/" + goldHall.getnumbofpl() + "        " + platinumHall.GetAktualpl() + "/" + platinumHall.getnumbofpl() );
                    System.out.println("Total Available Seats:  " + operations.getTotalAvailableSeats());
                    //      System.out.println("Expenses:           " + classicHall.getExpenses() + "€          " + goldHall.getExpenses() + "€       " + platinumHall.getExpenses()+ "€");
                    //      System.out.println("Staff Count:        " + classicHall.getStaffCount() + "              " + goldHall.getStaffCount() + "            " + platinumHall.getStaffCount() );
                    System.out.println("________________________________________________");
                    break;
                case 'e':
                    System.out.println("Thanks for using my program!");
                    in.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Error, please write a command from the list below:");
                    System.out.println("1) Login => l");
                    System.out.println("2) Buy tickets => b");
                    System.out.println("3) View available places => s");
                    System.out.println("4) End the program => e");
                    break;
            }
        }
   }

    public static void main(String[] args) {
        Main main = new Main();
        main.run();
    }
}