package classes.users;

public class Customers {
    private static String name;
    private static String surname;
    private static int age;

    public Customers(String name, String surname, int age) {
        this.name = name;
        this.surname = surname;
        this.age = age;
    }

    public static String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public static String getSurname() {
        return surname;
    }
    public void setSurname(String surname) {
        this.surname = surname;
    }

    public static int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
}

