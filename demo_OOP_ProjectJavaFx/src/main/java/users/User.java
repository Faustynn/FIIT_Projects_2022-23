package users;

import java.io.Serializable;

public class User extends Users implements UniversalAccount, Serializable {
    private int id;

    public User(String login, String password, String name, String surname,int age,int id) {
        super(login, password, age, name, surname);
        this.id=id;
    }
    public User() {
    }

    @Override
    public int getId() {
        return id;
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
        return 0;
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
