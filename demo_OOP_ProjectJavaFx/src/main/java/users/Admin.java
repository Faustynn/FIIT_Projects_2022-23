package users;

import java.io.Serializable;

public class Admin extends Users implements UniversalAccount, Serializable {
    private int score;
    private int money;

    public Admin(String login, String password, String name, String surname,int age,int score,int money) {
        super(login, password, age, name, surname);
        this.money = money;
        this.score = score;
    }
    public Admin() {
    }

    @Override
    public int getId() {
        return 0;
    }

    @Override
    public String getUsername() {
        return getLogin();
    }

    @Override
    public String getFirstName() {
        return getName();
    }

    @Override
    public String getLastName() {
        return getSurname();
    }

    @Override
    public int getScore() {
        return score;
    }

    @Override
    public void setUsername(String name) {

    }

    @Override
    public void setFirstName(String firstName) {

    }

    @Override
    public void setLastName(String lastName) {

    }

    @Override
    public void setId(int id) {

    }

    @Override
    public void setScore(int score) {

    }
}
