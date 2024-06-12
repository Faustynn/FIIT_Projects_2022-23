package users;

import java.io.Serializable;

public interface UniversalAccount extends Serializable {
    String getUsername();
    String getPassword();
    String getFirstName();
    String getLastName();
    int getAge();
    int getId();
    int getScore();

    void setUsername(String name);
    void setPassword(String pass);
    void setFirstName(String firstName);
    void setLastName(String lastName);
    void setAge(int age);
    void setId(int id);
    void setScore(int score);
}
